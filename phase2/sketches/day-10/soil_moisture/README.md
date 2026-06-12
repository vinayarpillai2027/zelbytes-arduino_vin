# Soil Moisture Monitoring using Arduino Uno

## Overview

This project measures soil moisture using an analog soil moisture sensor connected to an Arduino Uno. The sensor's analog output is read by the Arduino and converted into a moisture percentage based on calibration values.

To reduce corrosion in resistive soil moisture probes, the sensor is powered only during measurements and turned off afterward.

## Components Required

* Arduino Uno
* Soil Moisture Sensor (Analog)
* Jumper Wires
* Breadboard (Optional)
* USB Cable

## Circuit Connections

| Sensor Pin | Arduino Uno Pin |
| ---------- | --------------- |
| VCC        | D7              |
| GND        | GND             |
| AO         | A1              |

> Note: The sensor is powered through Digital Pin 7 to minimize probe corrosion by supplying power only when readings are taken.

## Working Principle

1. Arduino powers the sensor through pin D7.
2. The sensor measures soil conductivity.
3. An analog value is read from pin A1.
4. The raw ADC value is mapped to a moisture percentage.
5. The sensor is powered off until the next reading.

## Calibration

The following values should be determined experimentally:

| Condition           | ADC Value |
| ------------------- | --------- |
| Completely Dry Soil | 820       |
| Fully Wet Soil      | 380       |

These values are used to convert raw readings into a percentage.

## Arduino Code

```cpp
const uint8_t MOIST_PIN = A1;
const uint8_t MOIST_PWR = 7;

const int DRY_ADC = 820;
const int WET_ADC = 380;

int readMoistRaw() {
  digitalWrite(MOIST_PWR, HIGH);
  delay(10);

  int v = analogRead(MOIST_PIN);

  digitalWrite(MOIST_PWR, LOW);
  return v;
}

int toPercent(int raw) {
  return constrain(map(raw, DRY_ADC, WET_ADC, 0, 100), 0, 100);
}

void setup() {
  pinMode(MOIST_PWR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int raw = readMoistRaw();

  Serial.print(F("raw="));
  Serial.print(raw);

  Serial.print(F(" pct="));
  Serial.println(toPercent(raw));

  delay(1000);
}
```

## Sample Output

```text
raw=805 pct=3
raw=720 pct=22
raw=610 pct=47
raw=500 pct=72
raw=390 pct=97
```

## Moisture Percentage Guide

| Moisture (%) | Soil Condition |
| ------------ | -------------- |
| 0 – 20       | Very Dry       |
| 21 – 40      | Dry            |
| 41 – 60      | Moderate       |
| 61 – 80      | Moist          |
| 81 – 100     | Wet            |

## Applications

* Smart Irrigation Systems
* Automated Plant Watering
* Greenhouse Monitoring
* Precision Agriculture
* Home Gardening Projects
* IoT-Based Farming Systems

## Repository Structure

```text
soil-moisture-monitor/
│
├── README.md
├── sketches/
│   └── soil_moisture_monitor/
│       └── soil_moisture_monitor.ino
│
└── docs/
    └── wiring/
        └── soil_sensor_connection.png
```

## Future Improvements

* Add LCD/OLED display
* Control a water pump automatically
* Send readings to a cloud dashboard
* Add temperature and humidity monitoring
* Use ESP32 for Wi-Fi connectivity

## Author

Arduino-based Soil Moisture Monitoring project created for learning embedded systems, sensors, and IoT applications.
