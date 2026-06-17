# Smart Environment Monitoring System using Arduino

## Objective

The objective of this project is to monitor environmental conditions using an Arduino Uno, DHT22 sensor, soil moisture sensor, and LDR sensor. The system collects temperature, humidity, soil moisture, and ambient light data and outputs the readings in CSV format through the serial port for logging, analysis, and IoT applications.

## Hardware Used

* Arduino Uno
* DHT22 Temperature and Humidity Sensor
* Soil Moisture Sensor
* LDR (Light Dependent Resistor) Module
* Breadboard
* Jumper Wires

## Pin Connections

| Component        | Arduino Pin |
| ---------------- | ----------- |
| DHT22 Data       | D4          |
| Soil Moisture AO | A0          |
| LDR AO           | A1          |
| VCC              | 5V          |
| GND              | GND         |

## Features

* Temperature monitoring
* Humidity monitoring
* Soil moisture measurement
* Ambient light detection
* CSV-formatted serial output
* Data collection every 20 seconds
* Easy integration with data logging and IoT platforms

## Working

The Arduino initializes the DHT22 sensor and continuously reads temperature, humidity, soil moisture, and light intensity values. Every 20 seconds, the sensor readings are transmitted through the serial port in CSV format with a timestamp. This format allows the data to be easily stored, visualized, or processed using tools such as Excel, Python, MATLAB, or cloud-based IoT dashboards.

## Sample Output

```csv
timestamp,temp,humidity,soil,light
0,29.10,65.20,512,740
20000,29.20,65.00,505,735
40000,29.10,64.80,498,730
```

## Software Requirements

* Arduino IDE
* DHT Sensor Library by Adafruit
* Adafruit Unified Sensor Library

## Applications

* Smart Agriculture
* Greenhouse Monitoring
* Environmental Data Logging
* IoT Sensor Networks
* Educational Embedded Systems Projects

## Future Improvements

* Automatic irrigation control
* Cloud connectivity using ESP32
* MQTT integration
* Mobile dashboard monitoring
* SD card data logging
* Threshold-based alert system

