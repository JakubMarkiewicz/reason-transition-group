[@bs.module "react-transition-group/index"]
external cssTransition: ReasonReact.reactClass = "CSSTransition";

type state = string;
type node = Dom.element;
type isAppearing = bool;
type enterMethod = (node, isAppearing) => unit;
type exitMethod = node => unit;

[@bs.obj]
external makeProps:
  (
    ~_in: bool=?,
    ~mountOnEnter: bool=?,
    ~unmountOnExit: bool=?,
    ~appear: bool=?,
    ~enter: bool=?,
    ~exit: bool=?,
    ~timeout: int=?,
    ~classNames: string=?,
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
        ~timeout?,
        ~classNames?,
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