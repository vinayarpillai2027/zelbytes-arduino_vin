# Day 6 - Phase 1 Integration: Manual Irrigation Toggle

## Objective

Integrate button input, LED status indication, serial debugging, relay control, and valve safety features into a single irrigation control system.

## Features

* Debounced button input
* Momentary irrigation control
* Status LED indication
* Relay-controlled valve
* Emergency stop functionality
* Serial status monitoring
* Event logging using millis()

## System Behavior

### Button Pressed

* Valve opens
* Relay energizes
* Status LED turns ON

### Button Released

* Valve closes
* Relay de-energizes
* Status LED turns OFF

## Emergency Stop

### Serial Command

```text
e
```

### Result

* Valve closes
* Relay OFF
* Irrigation stops immediately

## Status Command

### Serial Command

```text
s
```

### Example Output

```text
valve=OPEN lastEventMs=12345 uptime=67890
```

## Learning Outcomes

* Modular firmware design
* Reusing previous code modules
* Integrating multiple hardware interfaces
* Fail-safe valve control
* Event logging and diagnostics

## Verification Checklist

* Momentary irrigation verified
* LED correctly indicates valve state
* ESTOP tested
* Serial status command tested
* No water leaks observed
* Wiring photo saved

## Status

Completed
