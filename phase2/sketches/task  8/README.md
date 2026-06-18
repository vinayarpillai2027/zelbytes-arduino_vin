# Task 8 - First Cloud Post

This project demonstrates the integration of an Arduino Uno with the Zelbytes IoT Learning Lab. The Arduino Uno generates telemetry data in CSV format and transmits it through the serial port. A host Python script reads the serial data, converts the CSV values into JSON format, and uploads the telemetry to the IoT Lab cloud using the provided API key.

The project was implemented using Arduino IDE and Python with the `pyserial` and `requests` libraries. More than 10 telemetry samples were successfully transmitted and stored in the IoT Learning Lab. The uploaded data was verified through the IoT Lab dashboard, confirming successful communication between the device and the cloud platform.

This implementation demonstrates the basic workflow of collecting data from embedded hardware and sending it to a cloud service for monitoring and analysis. It also highlights the importance of securely managing API keys and documenting field mappings for IoT applications.