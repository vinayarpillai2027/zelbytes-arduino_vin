import serial
import requests
import time

# Your IoT Lab API key
API_KEY = "zil_ffm1wawbptkpqstrpuqcjczhowfzuzkn"

# IoT Lab endpoint
URL = "https://careers.zelbytes.com/api/iot-lab/v1/telemetry"

# Open serial port
ser = serial.Serial('COM7', 115200)

headers = {
    "Authorization": f"Bearer {API_KEY}"
}

sample_count = 0

while sample_count < 10:

    line = ser.readline().decode().strip()

    print("CSV:", line)

    values = line.split(",")

    if len(values) == 3:

        payload = {
            "device_id": "vinaya",
            "temperature_c": float(values[0]),
            "humidity_pct": float(values[1]),
            "soil_moisture_pct": float(values[2])
        }

        response = requests.post(
            URL,
            json=payload,
            headers=headers
        )

        print("Uploaded:", payload)
        print("Status Code:", response.status_code)

        sample_count += 1

    time.sleep(1)

print("10 samples uploaded successfully!")