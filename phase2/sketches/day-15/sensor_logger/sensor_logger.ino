#include <DHT.h>

#define DHT_PIN 4
#define DHT_TYPE DHT22

#define SOIL_PIN A0
#define LDR_PIN A1

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  // Print CSV header once
  Serial.println("timestamp,temp,humidity,soil,light");
}

void loop() {

  // Read DHT11
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Read soil moisture sensor
  int soilValue = analogRead(SOIL_PIN);

  // Read LDR
  int lightValue = analogRead(LDR_PIN);

  // Print values in CSV format
  Serial.print(millis());
  Serial.print(",");

  Serial.print(temperature);
  Serial.print(",");

  Serial.print(humidity);
  Serial.print(",");

  Serial.print(soilValue);
  Serial.print(",");

  Serial.println(lightValue);

  // Take readings every 2 seconds
  delay(20000);
}