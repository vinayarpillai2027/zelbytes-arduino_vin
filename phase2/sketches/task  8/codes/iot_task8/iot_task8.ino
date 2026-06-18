void setup() {
  Serial.begin(115200);
}

void loop() {

  float temperature = random(200,350)/10.0;
  float humidity = random(400,800)/10.0;
  float soil = random(300,700)/10.0;

  Serial.print(temperature);
  Serial.print(",");
  Serial.print(humidity);
  Serial.print(",");
  Serial.println(soil);

  delay(5000);
}