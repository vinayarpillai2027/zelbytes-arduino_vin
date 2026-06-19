# FINAL REPORT

## Smart Grow Bench Irrigation System Using Arduino Uno

---

# 1. Project Overview

## Objective

The objective of this project was to design and implement an automated grow-bench irrigation system capable of monitoring soil moisture levels and controlling water delivery to plants. The system uses an Arduino Uno, a soil moisture sensor, and a relay-controlled water pump to automate irrigation while providing manual override capabilities.

The project demonstrates practical applications of embedded systems in smart agriculture and water conservation.

---

# 2. Hardware Bill of Materials (BOM)

| Component            | Quantity | Purpose                  |
| -------------------- | -------- | ------------------------ |
| Arduino Uno          | 1        | Main controller          |
| Soil Moisture Sensor | 1        | Measures soil moisture   |
| Relay Module (5V)    | 1        | Controls water pump      |
| Mini Water Pump      | 1        | Delivers water           |
| Push Button          | 1        | Manual override          |
| LED Indicator        | 1        | System status indication |
| 220Ω Resistor        | 1        | LED current limiting     |
| Breadboard           | 1        | Prototyping              |
| Jumper Wires         | Multiple | Connections              |
| USB Cable            | 1        | Arduino programming      |

---

# 3. System Architecture

The grow bench consists of three major subsystems:

1. Moisture sensing subsystem
2. Irrigation control subsystem
3. User interaction subsystem

The moisture sensor continuously measures soil conditions and sends analog values to the Arduino. The Arduino compares readings against predefined thresholds and activates the relay when watering is required.

The relay energizes the water pump until acceptable moisture levels are restored.

A manual push button allows users to force irrigation regardless of sensor readings.

---

# 4. Wiring Diagrams

## Arduino Connections

### Soil Moisture Sensor

| Sensor Pin | Arduino Pin |
| ---------- | ----------- |
| VCC        | 5V          |
| GND        | GND         |
| AO         | A0          |

### Relay Module

| Relay Pin | Arduino Pin |
| --------- | ----------- |
| VCC       | 5V          |
| GND       | GND         |
| IN        | D8          |

### Push Button

| Button Pin | Arduino Pin |
| ---------- | ----------- |
| One Side   | D7          |
| Other Side | GND         |

### Status LED

| LED Pin | Arduino Pin               |
| ------- | ------------------------- |
| Anode   | D13                       |
| Cathode | GND through 220Ω resistor |

### Pump Connection

Water Pump → Relay NO Terminal

Power Supply → Relay COM Terminal

---

## Wiring Images

Insert images below:

```markdown
![Wiring Diagram](images/wiring_diagram.png)

![Fritzing Diagram](images/fritzing_export.png)
```

If available, export diagrams from Fritzing and store them in:

```text
docs/images/
```

---

# 5. Software Design

## Main Functions

### Moisture Monitoring

Reads analog sensor values and converts them into moisture readings.

### Automatic Irrigation

Turns the pump ON when soil becomes dry.

### Manual Override

Allows user-controlled irrigation using a push button.

### Serial Interface

Provides commands for:

* STATUS
* PUMP_ON
* PUMP_OFF

---

# 6. Calibration Methodology

## Purpose

Sensor calibration is required because raw analog readings vary based on soil type, sensor condition, and environmental factors.

---

## Dry Calibration

The sensor was placed in completely dry soil.

Observed values:

```text
850 – 900
```

Average dry value:

```text
875
```

---

## Wet Calibration

The sensor was placed in fully saturated soil.

Observed values:

```text
300 – 350
```

Average wet value:

```text
325
```

---

## Threshold Selection

Based on testing:

| Condition  | Analog Reading |
| ---------- | -------------- |
| Dry Soil   | >700           |
| Moist Soil | 450–700        |
| Wet Soil   | <450           |

Automatic irrigation threshold:

```text
700
```

The pump activates whenever the moisture reading exceeds the threshold.

---

# 7. Testing Procedure

## Test 1 – Dry Soil Detection

### Steps

1. Insert sensor into dry soil.
2. Observe serial monitor.
3. Verify pump activation.

### Result

PASS

Pump activated automatically.

---

## Test 2 – Wet Soil Detection

### Steps

1. Saturate soil with water.
2. Observe readings.
3. Verify pump remains OFF.

### Result

PASS

Pump remained OFF.

---

## Test 3 – Manual Override

### Steps

1. Press push button.
2. Observe relay operation.

### Result

PASS

Pump activated successfully.

---

## Test 4 – Serial Commands

### Commands Tested

```text
STATUS
PUMP_ON
PUMP_OFF
```

### Result

PASS

All commands executed correctly.

---

# 8. Test Results

| Test Case       | Expected Result    | Actual Result      | Status |
| --------------- | ------------------ | ------------------ | ------ |
| Dry Soil        | Pump ON            | Pump ON            | PASS   |
| Wet Soil        | Pump OFF           | Pump OFF           | PASS   |
| Button Control  | Pump ON            | Pump ON            | PASS   |
| Serial Commands | Command Response   | Correct Response   | PASS   |
| Relay Switching | Reliable Operation | Reliable Operation | PASS   |

---

# 9. Known Limitations

## Sensor Corrosion

Low-cost soil moisture sensors can corrode over time due to continuous exposure to moisture.

### Mitigation

Use capacitive moisture sensors.

---

## Fixed Threshold

The current implementation uses a fixed irrigation threshold.

### Improvement

Implement adaptive thresholds.

---

## No Water-Level Monitoring

The system cannot detect an empty water reservoir.

### Improvement

Add an ultrasonic or float sensor.

---

## No Remote Monitoring

The project currently operates locally.

### Improvement

Integrate Wi-Fi using ESP32.

---

# 10. Future Enhancements

## IoT Connectivity

Enable cloud monitoring and control.

## Mobile Dashboard

Create a smartphone application.

## Data Logging

Store moisture history for analysis.

## Weather Integration

Prevent watering during rain forecasts.

## Solar Power

Deploy using renewable energy.

---

# 11. Reflashing Instructions for Next Intern

## Repository Setup

Clone repository:

```bash
git clone <repository-url>
```

Navigate to project folder:

```bash
cd grow-bench
```

---

## Install Arduino IDE

Download and install Arduino IDE.

Open:

```text
File → Open → grow_bench.ino
```

---

## Connect Hardware

1. Connect Arduino Uno via USB.
2. Select correct COM port.
3. Select board:

```text
Arduino Uno
```

---

## Upload Firmware

Click:

```text
Verify
```

Then:

```text
Upload
```

Wait until upload completes.

---

## Verify Operation

Open Serial Monitor.

Set baud rate:

```text
9600
```

Check:

* Moisture readings
* Pump operation
* Button operation
* Serial commands

---

## Troubleshooting

### Upload Failure

Check COM port.

### Sensor Not Responding

Verify A0 connection.

### Pump Not Running

Verify relay wiring and power supply.

### Random Readings

Inspect sensor and grounding connections.

---

# 12. Conclusion

The Smart Grow Bench Irrigation System successfully demonstrated automatic plant watering using soil moisture sensing and relay-controlled irrigation. The project achieved reliable detection of dry soil conditions, automatic pump control, manual override functionality, and serial monitoring capabilities.

The system provides a strong foundation for future smart agriculture solutions and can be expanded with IoT connectivity, cloud monitoring, and advanced environmental sensing technologies.

---
