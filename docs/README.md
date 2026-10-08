<div align="center">

# 🌱 Smart Grow Bench: Arduino & IoT Irrigation System

**From blinking an LED to a sensor-driven, safety-aware irrigation controller that streams telemetry to the cloud.**

![Arduino](https://img.shields.io/badge/Arduino-Uno_R3-00979D?logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-Firmware-00599C?logo=cplusplus&logoColor=white)
![Python](https://img.shields.io/badge/Python-pyserial_%2B_requests-3776AB?logo=python&logoColor=white)
![Status](https://img.shields.io/badge/status-_done-green)

</div>

---

## 📖 Overview

This repository documents a hands-on Arduino & IoT internship (Zelbytes), built up day by day into a **smart grow-bench irrigation system**. The system reads soil moisture, temperature, humidity, and light, decides when to water using a **finite state machine**, switches a pump or solenoid valve through a relay, and reports data to a cloud IoT lab.

**Highlights**
- ⚙️ Non-blocking firmware using `millis()` instead of `delay()`
- 🔁 Finite state machine (FSM) irrigation logic with cooldown and sensor-fault handling
- 🛑 Interrupt-driven emergency stop
- 🧪 Sensor calibration (LDR, soil moisture) with documented test results
- ☁️ Python bridge from serial CSV to a cloud telemetry API
- 📚 Wiring diagrams, pin tables, and a bench card for every build

## 🗺️ Project Roadmap

| Phase | Focus | Days / Tasks | Status |
|---|---|---|---|
| **Phase 1** | Arduino foundations & safe actuation | Days 1–6 | ✅ Done |
| **Phase 2** | Sensors, automation & cloud telemetry | Days 7–15, Tasks 8–9 | ✅ Done |
| **Phase 3** | Advanced integration | Task 10 | ✅ Done |

## 🧩 What's Built

### Phase 1: Foundations (`sketches/`)

| Day | Topic | Key concept |
|---|---|---|
| 1 | Blink LED & Serial Hello | Upload workflow, Serial Monitor |
| 2 | Git & repository setup | Version control workflow |
| 3 | Button + LED with debouncing | Digital I/O, input handling |
| 4 | Serial debugging | Logging and diagnostics |
| 5 | Relay-controlled solenoid valve | Safe high-power switching |
| 6 | Manual irrigation toggle | Phase 1 integration, [bench card](sketches/day-06/BENCH_CARD.md) |

### Phase 2: Sensing, Automation & IoT (`phase2/sketches/`)

| Day / Task | Project | What it demonstrates |
|---|---|---|
| Day 7 | LDR light calibration | Voltage divider, ADC calibration, light threshold bands |
| Day 8 | DHT22 temperature & humidity | Error handling, non-blocking reads |
| Day 9 | HC-SR04 ultrasonic | Distance sensing (e.g. water level) |
| Day 10 | Soil moisture monitoring | Calibrated % reading; sensor powered only during reads to reduce probe corrosion |
| Day 11 | Multi-sensor "unity" system | DHT22 + LDR + soil + ultrasonic streamed as CSV |
| Day 12 | Threshold-based smart irrigation | **FSM**, cooldown, DHT22 fault detection ([state diagram](phase2/sketches/day-12/docs/state%20machine%20diagram.jpeg)) |
| Day 13 | Motor & valve control | PWM speed control, serial commands, **interrupt-driven E-stop** |
| Day 15 | Sensor logger | Timestamped CSV every 20 s for logging and analysis |
| Task 8 | **First cloud post** | Arduino CSV → Python (`pyserial` + `requests`) → IoT Lab API; 10+ samples verified on dashboard |
| Task 9 | **Automated grow bench** | Soil sensor + relay pump + manual override |

📄 The full engineering write-up is in the **[Final Report](phase2/sketches/readme.md)**: BOM, wiring tables, calibration (dry ≈ 875 / wet ≈ 325 ADC, irrigation threshold 700), test results, limitations, and future work.

## 🛠️ Hardware

| Component | Used for |
|---|---|
| Arduino Uno R3 (ATmega328P) | Main controller |
| DHT22 / AM2301 | Temperature & humidity |
| Resistive soil moisture sensor | Soil moisture |
| LDR (GL5528) + 10 kΩ | Light level |
| HC-SR04 | Ultrasonic distance |
| 5 V relay module | Switching pump / valve |
| Solenoid valve / mini water pump | Water delivery |
| DC motor + driver (L298N/L293D) | Motor control (Day 13) |
| Push buttons, LEDs, 220 Ω resistors | Manual control & status |
| External power supply | Powering the pump / valve |

## 🔌 Core Wiring (Final Grow Bench, Task 9)

| Component | Pin | Arduino |
|---|---|---|
| Soil moisture sensor | AO | A0 |
| Relay module | IN | D7 |
| Push button (manual override) | one side | D2 (other side to GND) |
| Pump / valve | via relay NO + COM | External supply |

> Pin assignments differ between days. Each folder has its own table and wiring photo.

## ⚡ Getting Started

**Requirements:** Arduino IDE 2.x, Arduino Uno R3, USB cable. Some sketches need the **DHT sensor library** (Adafruit) from the Library Manager.

```bash
git clone https://github.com/vinayarpillai2027/zelbytes-arduino_vin.git
```

1. Open a sketch (`.ino`) in Arduino IDE
2. **Tools → Board → Arduino Uno**, then select your port
3. Click **Upload**, then open the Serial Monitor (9600 baud unless the sketch says otherwise)

### Cloud telemetry (Task 8)

```bash
pip install pyserial requests
# Add your API key to a local, git-ignored config, never to the source
python "phase2/sketches/task  8/codes/telemetry.py"
```

## 🛡️ Safety

- Valves and pumps are **always driven through a relay**, never directly from a GPIO pin
- Check wiring before power-up and disconnect power before changing connections
- Hardware **emergency stop** on interrupt in the motor/valve controller
- FSM includes a **cooldown** and **sensor-fault** state to prevent over-watering

See [`docs/SAFETY.md`](docs/SAFETY.md), [`docs/HARDWARE.md`](docs/HARDWARE.md), and [`docs/DEBUGGING.md`](docs/DEBUGGING.md).

## 📂 Repository Structure

```
.
├── docs/                    # Safety, hardware, debugging notes
├── sketches/                # Phase 1: Days 1–6
├── wiring-images/           # Phase 1 wiring photos
├── phase2/
│   └── sketches/
│       ├── readme.md        # ← Final Report
│       ├── day-07 … day-15/ # Sensors, FSM, motor, logger
│       ├── task  8/         # Cloud telemetry (Arduino + Python)
│       ├── task9/           # Automated grow bench
│       └── wiring images/   # Phase 2 wiring photos
```

## 🧠 Skills Demonstrated

**Embedded:** digital/analog I/O · ADC calibration · PWM · interrupts · non-blocking `millis()` timing · `F()` memory optimization · state machines · fault handling
**IoT:** CSV telemetry · serial-to-HTTP bridge · REST API integration · API key handling
**Engineering practice:** wiring documentation · test plans & results · safety-first design · Git workflow

## 🔮 Future Work

- Capacitive moisture sensor to avoid probe corrosion
- Adaptive thresholds
- Water-reservoir level monitoring (ultrasonic/float)
- ESP32 Wi-Fi for direct cloud connectivity and a mobile dashboard
- Weather-aware watering

## 👤 Author

**Vinaya R Pillai**
[GitHub](https://github.com/vinayarpillai2027) · [LinkedIn](#) · [Email](#)
