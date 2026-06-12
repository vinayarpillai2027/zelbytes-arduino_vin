# Multi-Sensor Environmental Monitoring System using Arduino Uno

## Overview

This project integrates multiple sensors with an Arduino Uno to monitor environmental conditions in real time. The system collects data from:

* DHT22 Temperature and Humidity Sensor
* LDR (Light Dependent Resistor)
* Soil Moisture Sensor
* HC-SR04 Ultrasonic Distance Sensor

All sensor readings are transmitted through the Serial Monitor in CSV format, making them easy to log, visualize, or process using tools such as Excel, Python, MATLAB, or IoT platforms.

---

## Components Required

* Arduino Uno
* DHT22 Temperature & Humidity Sensor
* LDR Module or LDR with Resistor
* Soil Moisture Sensor
* HC-SR04 Ultrasonic Sensor
* Breadboard
* Jumper Wires
* USB Cable

---

## Circuit Connections

### DHT22

| DHT22 Pin | Arduino Pin |
| --------- | ----------- |
| VCC       | 5V          |
| GND       | GND         |
| DATA      | D7          |

### LDR Sensor

| LDR Output | Arduino Pin |
| ---------- | ----------- |
| AO         | A1          |
| VCC        | 5V          |
| GND        | GND         |

### Soil Moisture Sensor

| Sensor Output | Arduino Pin |
| ------------- | ----------- |
| AO            | A0          |
| VCC           | 5V          |
| GND           | GND         |

### HC-SR04 Ultrasonic Sensor

| HC-SR04 Pin | Arduino Pin |
| ----------- | ----------- |
| VCC         | 5V          |
| GND         | GND         |
| TRIG        | D9          |
| ECHO        | D10         |

---

## Features

* Measures ambient temperature
* Measures relative humidity
* Detects light intensity
* Monitors soil moisture level
* Measures distance using ultrasonic sensing
* Outputs all sensor values in CSV format
* Suitable for data logging and IoT applications

---

## Data Format

Sensor readings are printed as:

```text
Temperature(C),Humidity(%),LDR,Soil,Distance(cm)
```

Example:

```text
28.40,68.20,512,420,15.63
28.50,68.10,510,418,15.55
28.60,68.00,509,417,15.48
```

---

## Arduino Code

The project uses:

* DHT Library by Adafruit
* Arduino Core Functions
* Analog Sensor Inputs
* Ultrasonic Pulse Timing

### Required Library

Install the following library from Arduino IDE Library Manager:

```text
DHT sensor library by Adafruit
```

---

## Working Principle

### Temperature & Humidity

The DHT22 sensor provides digital measurements of:

* Temperature (°C)
* Relative Humidity (%)

### Light Intensity

The LDR changes resistance based on light levels. The Arduino reads this change as an analog value.

### Soil Moisture

The soil moisture sensor outputs an analog voltage proportional to the moisture content in the soil.

### Distance Measurement

The HC-SR04 sends ultrasonic pulses and measures the echo return time to calculate distance.

Distance Formula:

Distance (cm) = (Duration × 0.0343) / 2

---

## Applications

* Smart Agriculture
* Greenhouse Monitoring
* Weather Stations
* Environmental Data Logging
* Smart Irrigation Systems
* IoT Sensor Nodes
* Research and Educational Projects

---

## Repository Structure

```text
multi-sensor-monitoring/
│
├── README.md
│
├── sketches/
│   └── multi_sensor_monitoring/
│       └── multi_sensor_monitoring.ino
│
├── docs/
│   ├── wiring/
│   │   └── circuit_diagram.png
│   │
│   └── screenshots/
│       └── serial_output.png
│
└── data/
    └── sample_sensor_log.csv
```

---

## Sample Serial Output

```csv
Temperature(C),Humidity(%),LDR,Soil,Distance(cm)
28.50,67.80,514,435,14.72
28.60,67.90,510,432,14.69
28.60,68.00,508,430,14.66
```

---

## Future Enhancements

* ESP32 Wi-Fi Connectivity
* Cloud Data Logging
* MQTT Integration
* OLED/LCD Display
* Automatic Irrigation Control
* Mobile Dashboard
* Data Visualization using Grafana

---

## Author

Multi-Sensor Environmental Monitoring System developed using Arduino Uno for embedded systems, sensor interfacing, data acquisition, and IoT learning.
