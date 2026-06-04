# Day 1 - Arduino Basics: Blink LED and Serial Monitor Output

## Objective

Learn the fundamentals of Arduino programming by controlling the onboard LED and displaying messages through the Serial Monitor.

---

## Concepts Learned

* Arduino IDE setup
* Board selection and port configuration
* `setup()` function
* `loop()` function
* `pinMode()`
* `digitalWrite()`
* `delay()`
* `Serial.begin()`
* `Serial.println()`

---

## Components Used

* Arduino Uno R3
* USB Cable
* Computer with Arduino IDE

---

## Connections

### LED

The onboard LED connected to **Pin 13** was used.

No external wiring was required.

### Serial Communication

The Arduino was connected to the computer using a USB cable to display messages in the Serial Monitor.

---

## Program Description

The program performs two tasks:

1. Blinks the onboard LED every second.
2. Prints a message to the Serial Monitor.

### Serial Monitor Message

```text
Hello Zelbytes! Arduino Day 1
```

---

## Expected Output

### LED Output

* LED turns ON for 1 second.
* LED turns OFF for 1 second.
* Process repeats continuously.

### Serial Monitor Output

The following message is displayed repeatedly in the Serial Monitor:

```text
Hello Zelbytes! Arduino Day 1
```

---

## Files

```text
day-01-blink.ino
```

---

## Learning Outcomes

By completing this exercise, I learned:

* How to install and configure the Arduino IDE.
* How to upload code to an Arduino Uno board.
* How to control digital output pins.
* How to use delays for timing operations.
* How to establish serial communication between Arduino and a computer.
* How to display messages using the Serial Monitor.
* Basic Arduino program structure using `setup()` and `loop()` functions.

---

## Status

✅ Completed

Completed
