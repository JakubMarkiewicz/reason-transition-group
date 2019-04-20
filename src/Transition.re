type state = string;
type node = Dom.element;
type isAppearing = bool;
type enterMethod = (node, isAppearing) => unit;
type exitMethod = node => unit;

[@bs.deriving abstract]
type timeoutFull = {
  [@bs.optional]
  enter: int,
  [@bs.optional]
  exit: int,
};

type timeout = [ | `int(int) | `obj(timeoutFull)];

module TimeoutValue = {
  type t;
  external int: int => t = "%identity";
  external timeoutFull: timeoutFull => t = "%identity";
};

let setTimeout = (a: timeout) =>
  switch (a) {
  | `int(int) => TimeoutValue.int(int)
  | `obj(timeoutFull) => TimeoutValue.timeoutFull(timeoutFull)
  };

module InternalBind = {
  [@bs.module "react-transition-group/esm/index"] [@react.component]
  external make:
    (
      ~_in: bool=?,
      ~mountOnEnter: bool=?,
      ~unmountOnExit: bool=?,
      ~appear: bool=?,
      ~enter: bool=?,
      ~exit: bool=?,
      ~timeout: TimeoutValue.t=?,
      ~onEnter: enterMethod=?,
      ~onEntering: enterMethod=?,
      ~onEntered: enterMethod=?,
      ~onExit: exitMethod=?,
      ~onExiting: exitMethod=?,
      ~onExited: exitMethod=?,
      ~children: state => React.element
    ) =>
    React.element =
    "Transition";
};

[@react.component]
let make =
    (
      ~_in: bool=?,
      ~mountOnEnter: bool=?,
      ~unmountOnExit: bool=?,
      ~appear: bool=?,
      ~enter: bool=?,
      ~exit: bool=?,
      ~timeout: timeout=?,
      ~onEnter: enterMethod=?,
      ~onEntering: enterMethod=?,
      ~onEntered: enterMethod=?,
      ~onExit: exitMethod=?,
      ~onExiting: exitMethod=?,
      ~onExited: exitMethod=?,
      ~children: state => React.element,
    ) =>
  <InternalBind
    _in
    mountOnEnter
    unmountOnExit
    appear
    enter
    exit
    timeout={setTimeout(timeout)}
    onEnter
    onEntering
    onEntered
    onExit
    onExiting
    onExited>
    {state => children(state)}
  </InternalBind>;