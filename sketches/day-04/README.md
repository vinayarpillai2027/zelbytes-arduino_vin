# Day 4 - Serial Monitor and Debugging Techniques

## Objective

Learn how to use the Arduino Serial Monitor as a debugging tool for firmware development. Implement serial commands, understand baud rate communication, use the `F()` macro for memory optimization, and create a simple command-based interface for controlling hardware.

---

## Concepts Learned

* Serial Communication
* Serial Monitor
* Baud Rate Matching
* Serial Commands
* Command Parsing
* Debug Logging
* Conditional Compilation
* `F()` Macro
* SRAM Optimization
* Non-blocking Programming
* Firmware Debugging Techniques

---

## Components Used

* Arduino Uno R3
* USB Cable
* Computer with Arduino IDE
* Onboard LED (Pin 13)

---

## Circuit Connections

### LED

The onboard LED connected to **Pin 13** was used.

No external wiring was required.

### USB Communication

The Arduino communicates with the computer through the USB cable using Serial communication.

---

## Program Description

The sketch creates a simple command-line interface using the Serial Monitor.

The user can type commands into the Serial Monitor to control the onboard LED and receive system information.

### Supported Commands

| Command | Function          |
| ------- | ----------------- |
| `?`     | Display help menu |
| `l`     | Turn LED ON       |
| `o`     | Turn LED OFF      |

The system also prints a periodic uptime message every 2 seconds when DEBUG mode is enabled.

---

## Serial Monitor Configuration

### Baud Rate

```cpp
Serial.begin(9600);
```

The Serial Monitor must also be set to:

* 9600 baud

If the baud rate does not match, unreadable characters may appear.

---

## DEBUG Mode

The program uses a compile-time debug flag:

```cpp
#define DEBUG 1
```

### DEBUG Enabled

When enabled:

```text
uptime_ms=2000
uptime_ms=4000
uptime_ms=6000
```

Periodic diagnostic messages are displayed.

### DEBUG Disabled

Comment out the line:

```cpp
// #define DEBUG 1
```

The uptime messages will no longer appear.

The command interface will continue to function normally.

---

## F() Macro

### Example

```cpp
Serial.println(F("Commands: ? help, l on, o off"));
```

### Purpose

Normally, text strings are copied into SRAM.

Using `F()`:

* Stores strings in Flash memory.
* Saves SRAM.
* Improves memory efficiency on Arduino Uno.

---

## Example Serial Session

```text
Commands: ? help, l on, o off

?

l=LED on, o=off

l

ON

o

OFF
```

---

## Expected Output

### LED Behavior

* Command `l` → LED turns ON
* Command `o` → LED turns OFF

### Serial Output

```text
Commands: ? help, l on, o off
uptime_ms=2000
uptime_ms=4000
```

---

## Files

```text
day-04-serial-debug.ino
README.md
docs/DEBUGGING.md
```

---

## Learning Outcomes

By completing this task, I learned:

* How Serial communication works.
* How baud rates affect communication.
* How to send and receive data through the Serial Monitor.
* How to build a simple command parser.
* How to create debug messages for troubleshooting.
* How to use conditional compilation with DEBUG flags.
* How the `F()` macro helps conserve SRAM.
* How to monitor firmware health using uptime messages.

---

## Verification Checklist

* [x] Serial Monitor configured to correct baud rate
* [x] Commands `?`, `l`, and `o` function correctly
* [x] LED responds to serial commands
* [x] DEBUG mode tested
* [x] Uptime messages displayed every 2 seconds
* [x] No long blocking delays present
* [x] `DEBUGGING.md` completed
* [x] Changes committed to branch `day-04-serial-debug`

---

## Status

✅ Completed
