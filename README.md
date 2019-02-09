# reason-transition-group

This is [Bucklescript](https://bucklescript.github.io/) bindings for [reason-transition-group](https://github.com/reactjs/react-transition-group).

# Install, [npm](https://www.npmjs.com/package/@ahrefs/bs-recharts)

```
yarn add reason-transition-group
```

# Setup

Add reason-transition-group to `bs-depenencies` in your `bsconfig.json`!

```js
{
  /* ... */
  "bs-dependencies": [
    "reason-transition-group"
  ],
  /* ... */
}
```

# Usage

Folow official docs of [React Transition Group](https://reactcommunity.org/react-transition-group/).

```
open ReasonTransitionGroup

...
<Transition _in={inState} timeout={"enter": int, "exit": int}>
...{state => <div>{state |> ReasonReact.string}</div>}
</Transiton>
...

...
<CSSTransition _in={inState} timeout={"enter": int, "exit": int} classNames="myClassName">
...{state => <div>{state |> ReasonReact.string}</div>}
</CSSTransiton>
...


```

# Current state

Most of functionalities are ready.
Js.t({..}) should be replaced with some strong types.
