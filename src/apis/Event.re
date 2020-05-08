module EventMethods = (T: {
                         type target;
                         type r;
                       }) => {
  [@bs.get] [@bs.return nullable]
  external bubbles: T.target => option(bool) = "bubbles";
  [@bs.get] [@bs.return nullable]
  external cancelable: T.target => option(bool) = "cancelable";
  [@bs.get] external currentTarget: T.target => float = "currentTarget";
  [@bs.get] [@bs.return nullable]
  external defaultPrevented: T.target => option(bool) = "defaultPrevented";
  [@bs.get] external dispatchConfig: T.target => T.r = "dispatchConfig";
  [@bs.get] [@bs.return nullable]
  external eventPhase: T.target => option(float) = "eventPhase";
  [@bs.send] external preventDefault: T.target => unit = "preventDefault";
  [@bs.send]
  external isDefaultPrevented: T.target => bool = "isDefaultPrevented";
  [@bs.send] external stopPropagation: T.target => unit = "stopPropagation";
  [@bs.send]
  external isPropagationStopped: T.target => bool = "isPropagationStopped";
  [@bs.get] [@bs.return nullable]
  external isTrusted: T.target => option(bool) = "isTrusted";
  [@bs.get] external nativeEvent: T.target => 'a = "nativeEvent";
  [@bs.send] external persist: T.target => unit = "persist";
  [@bs.get] [@bs.return nullable]
  external target: T.target => option(float) = "target";
  [@bs.get] external timeStamp: T.target => float = "timeStamp";
  [@bs.get] [@bs.return nullable]
  external _type: T.target => option(string) = "type";
};

module SyntheticEvent = (T: {type payload;}) => {
  type t = {
    bubbles: Js.Nullable.t(bool),
    cancelable: Js.Nullable.t(bool),
    currentTarget: float,
    defaultPrevented: Js.Nullable.t(bool),
    dispatchConfig: registrationName,
    eventPhase: Js.Nullable.t(float),
    isTrusted: Js.Nullable.t(bool),
    nativeEvent: T.payload,
    target: Js.Nullable.t(float),
    timeStamp: float,
    [@bs.as "type"]
    _type: Js.Nullable.t(string),
  }
  and registrationName = {registrationName: string};

  include EventMethods({
    type target = t;
    type r = registrationName;
  });
};

module ResponderSyntheticEvent = (T: {type payload;}) => {
  type t = {
    bubbles: Js.Nullable.t(bool),
    cancelable: Js.Nullable.t(bool),
    currentTarget: float,
    defaultPrevented: Js.Nullable.t(bool),
    dispatchConfig: registrationName,
    eventPhase: Js.Nullable.t(float),
    isTrusted: Js.Nullable.t(bool),
    nativeEvent: T.payload,
    target: Js.Nullable.t(float),
    timeStamp: float,
    [@bs.as "type"]
    _type: Js.Nullable.t(string),
    touchHistory,
  }
  and registrationName = {registrationName: string}
  and touchHistory = {
    indexOfSingleActiveTouch: float,
    mostRecentTimeStamp: float,
    numberActiveTouches: float,
    touchBank: array(touchBank),
  }
  and touchBank = {
    touchActive: bool,
    startPageX: float,
    startPageY: float,
    startTimeStamp: float,
    currentPageX: float,
    currentPageY: float,
    currentTimeStamp: float,
    previousPageX: float,
    previousPageY: float,
    previousTimeStamp: float,
  };

  include EventMethods({
    type target = t;
    type r = registrationName;
  });

  [@bs.get] external touchHistory: t => touchHistory = "touchHistory";
};

module LayoutEvent =
  SyntheticEvent({
    type layout = {
      x: float,
      y: float,
      width: float,
      height: float,
    };
    type payload = {layout};
  });

module TextLayoutEvent =
  SyntheticEvent({
    type line = {
      x: float,
      y: float,
      width: float,
      height: float,
      ascender: float, // verify
      capHeight: float, // verify
      descender: float, // verify
      text: string,
      xHeight: float // verify
    };
    type payload = {lines: array(line)};
  });

module PressEvent =
  ResponderSyntheticEvent({
    type payload = {
      changedTouches: array(payload),
      force: float,
      identifier: int,
      locationX: float,
      locationY: float,
      pageX: float,
      pageY: float,
      target: Js.Nullable.t(float),
      timestamp: float,
      touches: array(payload),
    };
  });

module ScrollEvent =
  SyntheticEvent({
    type contentOffset = {
      x: float,
      y: float,
    };

    type contentInset = {
      bottom: float,
      left: float,
      right: float,
      top: float,
    };

    type dimensions = {
      height: float,
      width: float,
    };

    type payload = {
      contentInset: contentOffset,
      contentOffset: contentInset,
      contentSize: dimensions,
      layoutMeasurement: dimensions,
    };
  });

module SwitchChangeEvent =
  SyntheticEvent({
    type payload = {value: bool};
  });

module TargetEvent =
  SyntheticEvent({
    type payload = {target: int};
  });

type layoutEvent = LayoutEvent.t;
type textLayoutEvent = TextLayoutEvent.t;
type pressEvent = PressEvent.t;
type scrollEvent = ScrollEvent.t;
type switchChangeEvent = SwitchChangeEvent.t;
type targetEvent = TargetEvent.t;
