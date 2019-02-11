[@bs.module "react-transition-group/index"]
external cssTransition: ReasonReact.reactClass = "CSSTransition";

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

type timeout('a) = [< | `int(int) | `obj(timeoutFull)] as 'a;

[@bs.deriving abstract]
type classFull = {
  [@bs.optional]
  appear: string,
  [@bs.optional]
  appearActive: string,
  [@bs.optional]
  enter: string,
  [@bs.optional]
  enterActive: string,
  [@bs.optional]
  enterDone: string,
  [@bs.optional]
  exit: string,
  [@bs.optional]
  exitActive: string,
  [@bs.optional]
  exitDone: string,
};

module ClassValue = {
  type t;
  external string: string => t = "%identity";
  external classFull: classFull => t = "%identity";
};

type classNames = [ | `string(string) | `obj(classFull)];

let setClassName =
  fun
  | `string(string) => ClassValue.string(string)
  | `obj(classFull) => ClassValue.classFull(classFull);

module TimeoutValue = {
  type t;
  external int: int => t = "%identity";
  external timeoutFull: timeoutFull => t = "%identity";
};

let setTimeout = (a: timeout('a)) =>
  switch (a) {
  | `int(int) => TimeoutValue.int(int)
  | `obj(timeoutFull) => TimeoutValue.timeoutFull(timeoutFull)
  };

[@bs.obj]
external makeProps:
  (
    ~_in: bool=?,
    ~mountOnEnter: bool=?,
    ~unmountOnExit: bool=?,
    ~appear: bool=?,
    ~enter: bool=?,
    ~exit: bool=?,
    ~timeout: TimeoutValue.t=?,
    ~classNames: ClassValue.t=?,
    ~onEnter: enterMethod=?,
    ~onEntering: enterMethod=?,
    ~onEntered: enterMethod=?,
    ~onExit: exitMethod=?,
    ~onExiting: exitMethod=?,
    ~onExited: exitMethod=?,
    unit
  ) =>
  _ =
  "";

let make =
    (
      ~_in=?,
      ~mountOnEnter=?,
      ~unmountOnExit=?,
      ~appear=?,
      ~enter=?,
      ~exit=?,
      ~timeout=?,
      ~classNames=?,
      ~onEnter=?,
      ~onEntering=?,
      ~onEntered=?,
      ~onExit=?,
      ~onExiting=?,
      ~onExited=?,
      children: state => ReasonReact.reactElement,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=cssTransition,
    ~props=
      makeProps(
        ~_in?,
        ~mountOnEnter?,
        ~unmountOnExit?,
        ~appear?,
        ~enter?,
        ~exit?,
        ~timeout=?timeout->Belt.Option.map(v => setTimeout(v)),
        ~classNames=?classNames->Belt.Option.map(v => setClassName(v)),
        ~onEnter?,
        ~onEntering?,
        ~onEntered?,
        ~onExit?,
        ~onExiting?,
        ~onExited?,
        (),
      ),
    children,
  );