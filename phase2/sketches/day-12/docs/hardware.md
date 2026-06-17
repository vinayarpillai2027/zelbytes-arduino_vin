\## Hardware Details and Their Working in the Project



\### 1. Arduino Uno



Working:



\* Acts as the main controller of the irrigation system.

\* Reads data from the soil moisture sensor and DHT22 sensor.

\* Controls the relay, solenoid valve, and LED based on the state machine logic.



\### 2. Soil Moisture Sensor



Working:



\* Measures the moisture content present in the soil.

\* Produces an analog output proportional to the soil moisture level.

\* Helps determine whether the soil is \*\*DRY\*\* or \*\*WET\*\*.

\* Triggers irrigation when the soil moisture falls below the threshold.



\### 3. DHT22 Sensor



Working:



\* Measures the ambient temperature and relative humidity.

\* Provides digital output to the Arduino.

\* Used for environmental monitoring.

\* If the sensor fails three consecutive times, the system enters the \*\*FAULT\*\* state and disables irrigation.



\### 4. Relay Module 



Working:



\* Acts as an electrically controlled switch.

\* Receives control signals from the Arduino.

\* Turns the solenoid valve ON or OFF by connecting or disconnecting the external power supply.

\* Provides isolation between the low-power Arduino circuit and the valve circuit.



\### 5. Solenoid Valve



Working:



\* Controls the flow of water in the irrigation system.

\* Opens when the relay is activated, allowing water to flow to the plants.

\* Closes when the relay is deactivated, stopping the water flow.

\* Performs the actual irrigation process.



\### 6. LED Indicator



Working:



\* Indicates the status of irrigation.

\* Turns ON when the system is in the \*\*IRRIGATING\*\* state.

\* Turns OFF when irrigation stops.

\* Provides visual feedback to the user.



\## Overall Working of the Project



The Arduino continuously monitors the soil moisture, temperature, and humidity. When the soil becomes dry, the system enters the IRRIGATING state, activating the relay and opening the solenoid valve to supply water. Simultaneously, the LED turns ON to indicate that irrigation is in progress. Once the soil becomes sufficiently wet, the relay deactivates, the valve closes, and the LED turns OFF. In case of three consecutive DHT22 sensor failures, the system enters the FAULT state and disables irrigation to ensure safe operation.
