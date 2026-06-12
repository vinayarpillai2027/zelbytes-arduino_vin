# Smart Irrigation System using Arduino Uno

## Overview

This project implements a Smart Irrigation System using an Arduino Uno, Soil Moisture Sensor, DHT22 Temperature & Humidity Sensor, Relay Module, and LED indicator.

The system uses a Finite State Machine (FSM) to control irrigation safely and efficiently. Based on soil moisture levels, the system automatically activates a water valve (through a relay) and enters different operating states.

## Features

* Automatic irrigation based on soil moisture
* Finite State Machine (FSM) implementation
* DHT22 temperature and humidity monitoring
* Relay-controlled solenoid valve or water pump
* LED status indication
* Cooldown period after irrigation
* Fault detection for DHT22 sensor failures
* Serial monitoring for debugging and logging

---

## Components Required

* Arduino Uno
* DHT22 Temperature & Humidity Sensor
* Soil Moisture Sensor
* 1-Channel Relay Module
* Solenoid Valve or Water Pump
* LED
* 220Ω Resistor
* Breadboard
* Jumper Wires
* USB Cable

---

## Circuit Connections

### DHT22 Sensor

| DHT22 Pin | Arduino Pin |
| --------- | ----------- |
| VCC       | 5V          |
| GND       | GND         |
| DATA      | D4          |

### Soil Moisture Sensor

| Sensor Pin | Arduino Pin |
| ---------- | ----------- |
| AO         | A0          |
| VCC        | 5V          |
| GND        | GND         |

### Relay Module

| Relay Pin | Arduino Pin |
| --------- | ----------- |
| IN        | D8          |
| VCC       | 5V          |
| GND       | GND         |

### Status LED

| LED Pin     | Arduino Pin                 |
| ----------- | --------------------------- |
| Anode (+)   | D13                         |
| Cathode (-) | GND (through 220Ω resistor) |

---

## State Machine Design

The irrigation controller operates using four states:

### 1. IDLE

* System monitoring soil moisture
* Valve OFF
* LED OFF
* Waits for dry soil condition

### 2. IRRIGATING

* Relay activated
* Valve ON
* LED ON
* Continues watering until moisture threshold is reached

### 3. COOLDOWN

* Valve OFF
* LED OFF
* Waits for a fixed cooldown period
* Prevents rapid relay switching

### 4. FAULT

* Triggered when DHT22 fails three consecutive readings
* Valve OFF
* LED OFF
* Requires troubleshooting before normal operation resumes

---

## Threshold Logic

### Soil Moisture Calibration

```cpp id="0szlcl"
const int SOIL_DRY = 600;
const int SOIL_WET = 400;
```

| Sensor Value | Condition       |
| ------------ | --------------- |
| > 600        | Dry Soil        |
| < 400        | Wet Soil        |
| 400 - 600    | Transition Zone |

### Irrigation Rules

1. Start irrigation when soil becomes dry.
2. Stop irrigation when soil becomes sufficiently wet.
3. Enter cooldown state for 5 seconds.
4. Return to monitoring mode.
5. Enter FAULT state if DHT22 fails three times consecutively.

---

## System Flow

```text id="z09qpr"
IDLE
  │
  ├── Soil Dry
  ▼
IRRIGATING
  │
  ├── Soil Wet
  ▼
COOLDOWN
  │
  ├── 5 Seconds Complete
  ▼
IDLE

DHT22 Failure × 3
        │
        ▼
      FAULT
```

---

## Serial Monitor Output Example

```text id="ol00jl"
State: IDLE
Soil Status: DRY
Soil Value: 645 (DRY) | Temperature: 29.4 °C | Humidity: 68.2 %

State: IRRIGATING
Valve ON
LED ON
Soil Value: 630 (DRY) | Temperature: 29.5 °C | Humidity: 68.0 %

State: COOLDOWN
Soil Value: 390 (WET) | Temperature: 29.3 °C | Humidity: 68.4 %
```

---

## Fault Detection

The system continuously validates DHT22 readings.

```cpp id="8fe9qw"
if (isnan(humidity) || isnan(temperature))
```

After three consecutive failures:

```text id="m7ptm3"
State: FAULT
DHT22 failed 3 consecutive times!
```

Safety actions:

* Relay OFF
* Valve OFF
* LED OFF

---

## Applications

* Smart Agriculture
* Home Gardening Automation
* Greenhouse Irrigation
* Water Conservation Systems
* Precision Farming
* IoT-Based Irrigation Projects

---

## Repository Structure

```text id="4f61n6"
smart-irrigation-system/
│
├── README.md
│
├── sketches/
│   └── smart_irrigation/
│       └── smart_irrigation.ino
│
├── docs/
│   ├── wiring/
│   │   └── circuit_diagram.png
│   │
│   ├── state_machine/
│   │   └── state_diagram.png
│   │
│   └── screenshots/
│       └── serial_output.png
│
└── data/
    └── sample_logs.csv
```

---

## Future Enhancements

* ESP32 Wi-Fi Integration
* MQTT Communication
* Mobile App Monitoring
* Cloud Dashboard
* OLED Display
* Weather Forecast Integration
* Water Consumption Analytics
* Multiple Irrigation Zones

---

## Learning Outcomes

This project demonstrates:

* Sensor interfacing
* Finite State Machines (FSM)
* Threshold-based decision making
* Relay control
* Fault handling and recovery
* Embedded system design principles
* Smart agriculture automation

---

## Author

Smart Irrigation System developed using Arduino Uno, DHT22, Soil Moisture Sensor, Relay Module, and State Machine Control for embedded systems and IoT learning.
