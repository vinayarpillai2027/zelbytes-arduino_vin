#include <DHT.h>

// -----------------------------
// Sensor Configuration
// -----------------------------
const byte DHT_PIN = 4;
const byte DHT_TYPE = DHT22;

DHT dht(DHT_PIN, DHT_TYPE);

// -----------------------------
// Timing Configuration
// -----------------------------
const unsigned long READ_INTERVAL = 2000; // 2 seconds
unsigned long lastReadTime = 0;

// -----------------------------
// Setup
// -----------------------------
void setup()
{
    Serial.begin(9600);

    dht.begin();

    Serial.println("ms,temp_c,humidity_pct");
}

// -----------------------------
// Main Loop
// -----------------------------
void loop()
{
    unsigned long currentTime = millis();

    // Wait until next scheduled reading
    if (currentTime - lastReadTime < READ_INTERVAL)
    {
        return;
    }

    lastReadTime = currentTime;

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    // Handle failed sensor readings
    if (isnan(humidity) || isnan(temperature))
    {
        Serial.println("ERR,NaN,NaN");
        return;
    }

    // CSV Output
    Serial.print(currentTime);
    Serial.print(",");

    Serial.print(temperature, 1);
    Serial.print(",");

    Serial.println(humidity, 1);
}
