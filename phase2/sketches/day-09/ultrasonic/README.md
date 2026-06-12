# HC-SR04 Ultrasonic Distance Measurement using Arduino Uno

## Overview

This project demonstrates how to measure distance using an HC-SR04 Ultrasonic Sensor and an Arduino Uno. The sensor sends ultrasonic waves and measures the time taken for the echo to return, allowing the Arduino to calculate the distance to an object.

## Components Required

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* Jumper Wires
* USB Cable
* Breadboard (Optional)

## Circuit Connections

| HC-SR04 Pin | Arduino Uno Pin |
| ----------- | --------------- |
| VCC         | 5V              |
| GND         | GND             |
| TRIG        | D9              |
| ECHO        | D10             |

## Working Principle

1. The Arduino sends a 10 µs pulse to the TRIG pin.
2. The HC-SR04 emits an ultrasonic sound wave.
3. The wave reflects from an object and returns to the sensor.
4. The ECHO pin stays HIGH for the duration of the round-trip travel time.
5. The Arduino measures this duration and calculates the distance.

## Distance Calculation

The distance is calculated using:

Distance (cm) = (Duration × 0.0343) / 2

Where:

* Duration = Echo pulse time in microseconds
* 0.0343 cm/µs = Speed of sound in air
* Division by 2 accounts for the round trip of the sound wave

## Arduino Code

```cpp
const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}
```

## Expected Output

Open the Serial Monitor (9600 baud) to view readings:

```text
Distance: 12.45 cm
Distance: 11.98 cm
Distance: 11.76 cm
```

## Applications

* Obstacle Detection
* Distance Measurement
* Water Level Monitoring
* Robotics Navigation
* Smart Parking Systems
* Automation Projects

## Repository Structure

```text
ultrasonic-distance-sensor/
│
├── README.md
├── sketches/
│   └── ultrasonic_sensor/
│       └── ultrasonic_sensor.ino
│
└── docs/
    └── wiring/
        └── hc_sr04_connections.png
```

## Author

Developed using Arduino Uno and HC-SR04 Ultrasonic Sensor for learning embedded systems and IoT fundamentals.
