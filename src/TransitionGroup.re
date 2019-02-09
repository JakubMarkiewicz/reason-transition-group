[@bs.module "react-transition-group/index"]
external transition: ReasonReact.reactClass = "TransitionGroup";

[@bs.obj]
external makeProps: (~appear: bool=?, ~enter: bool=?, ~exit: bool=?, unit) => _ =
  "";

let make = (~appear=?, ~enter=?, ~exit=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=transition,
    ~props=makeProps(~appear?, ~enter?, ~exit?, ()),
    children,
  );