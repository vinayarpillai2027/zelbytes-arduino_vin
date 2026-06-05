const byte LDR_PIN = A0;

const float VREF = 5.0;

// Replace these after calibration
const int DARK_REF = 120;
const int BRIGHT_REF = 850;

int readAveraged(byte pin, byte samples = 8)
{
  long total = 0;

  for (byte i = 0; i < samples; i++)
  {
    total += analogRead(pin);
    delay(2);
  }

  return total / samples;
}

String getLightLevel(int value)
{
  int range = BRIGHT_REF - DARK_REF;

  int darkLimit = DARK_REF + range * 0.30;
  int brightLimit = DARK_REF + range * 0.70;

  if (value < darkLimit)
    return "DARK";

  if (value > brightLimit)
    return "BRIGHT";

  return "AMBIENT";
}

void setup()
{
  Serial.begin(9600);

  Serial.println("Raw\tVoltage\tLevel");
}

void loop()
{
  int raw = readAveraged(LDR_PIN);

  float voltage = raw * (VREF / 1023.0);

  String level = getLightLevel(raw);

  Serial.print(raw);
  Serial.print("\t");

  Serial.print(voltage, 3);
  Serial.print(" V\t");

  Serial.println(level);

  delay(5000);
}
