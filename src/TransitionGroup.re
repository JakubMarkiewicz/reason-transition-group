[@bs.module "react-transition-group/esm/index"] [@react.component]
external make:
  (~appear: bool=?, ~enter: bool=?, ~exit: bool=?, ~children: React.element) =>
  React.element =
  "TransitionGroup";