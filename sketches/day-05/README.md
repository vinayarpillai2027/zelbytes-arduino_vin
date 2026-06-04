# Day 5 - Relay Controlled Solenoid Valve

## Objective

Learn safe control of a solenoid valve using a relay module and implement emergency stop functionality.

---

## Concepts Learned

* Relay operation
* Solenoid valve control
* Active-low relay logic
* Safe startup behavior
* Emergency stop (E-Stop) implementation
* External power switching
* Serial command interface
* Electrical safety practices

---

## Components Used

* Arduino Uno R3
* 5V Relay Module
* Solenoid Valve
* External Power Supply
* Jumper Wires
* USB Cable

---

## Safety Rules

⚠️ **Important Safety Precautions**

* Never connect a solenoid valve directly to an Arduino GPIO pin.
* Always use a relay module to switch the valve power.
* Verify relay operation before connecting the solenoid valve.
* Keep a manual shutoff valve accessible during testing.
* Use a drip tray under plumbing connections.
* Disconnect power before modifying wiring.
* Verify all connections before energizing the system.

---

## Circuit Overview

### Arduino to Relay

| Arduino Pin        | Relay Module |
| ------------------ | ------------ |
| Digital Output Pin | IN           |
| 5V                 | VCC          |
| GND                | GND          |

### Relay to Solenoid Valve

The relay switches power from the external supply to the solenoid valve.

**Important:** The valve must be powered by an appropriate external power source according to its voltage and current requirements.

---

## Program Description

The sketch provides a simple Serial Monitor interface for controlling the solenoid valve.

The relay remains OFF during startup to ensure safe operation.

Users can send commands through the Serial Monitor to briefly energize the valve or immediately stop all operation.

---

## Supported Commands

| Command | Action             |
| ------- | ------------------ |
| `v`     | Briefly open valve |
| `e`     | Emergency stop     |

---

## Example Serial Session

```text
Valve OFF. Commands: v=toggle, e=estop

v

Valve briefly energized.

e

ESTOP
```

---

## Expected Output

### Valve Behavior

* System starts with valve OFF.
* Command `v` energizes the relay and briefly opens the valve.
* Command `e` immediately de-energizes the relay and stops valve operation.

### Serial Output

```text
Valve OFF. Commands: v=toggle, e=estop

Valve briefly energized.

ESTOP
```

---

## Files

```text
day-05-relay-solenoid.ino
README.md
wiring-images/day-05.jpg
```

---

## Learning Outcomes

By completing this task, I learned:

* How relay modules safely control higher-current devices.
* Why a solenoid valve must never be connected directly to an Arduino output pin.
* How active-low relay modules operate.
* How to implement safe startup behavior in firmware.
* How to create an emergency stop function.
* How to control hardware using Serial Monitor commands.
* Important electrical and plumbing safety procedures when working with solenoid valves.

---

## Verification Checklist

* [x] Relay module connected correctly
* [x] Solenoid powered using external supply
* [x] Valve remains OFF during startup
* [x] Command `v` energizes valve correctly
* [x] Command `e` performs emergency stop
* [x] Serial Monitor displays status messages
* [x] Wiring photo saved as `wiring-images/day-05.jpg`
* [x] Sketch committed to branch `day-05-relay-solenoid`

---

## Status

✅ Completed
