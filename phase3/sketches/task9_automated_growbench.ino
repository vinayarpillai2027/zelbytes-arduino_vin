// ESP32 Auto Irrigation Firmware v1.0

#define SOIL_PIN 34
#define RELAY_PIN 26
#define BUTTON_PIN 27
#define LED_PIN 2

const int DRY_THRESHOLD = 600;   // Adjust after calibration

bool manualOverride = false;
bool pumpState = false;

bool lastButtonState = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup()
{
  Serial.begin(115200);

  pinMode(SOIL_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);

  Serial.println("Auto Irrigation Firmware v1.0 Started");
}

void loop()
{
  handleButton();

  // Automatic mode
  if (!manualOverride)
  {
    int soilValue = analogRead(SOIL_PIN);

    if (soilValue > DRY_THRESHOLD)
      pumpState = true;      // Dry soil → Pump ON
    else
      pumpState = false;     // Wet soil → Pump OFF
  }

  digitalWrite(RELAY_PIN, pumpState);
  digitalWrite(LED_PIN, pumpState);

  handleSerial();
}


// ---------- Push Button Manual Override ----------
void handleButton()
{
  bool reading = digitalRead(BUTTON_PIN);

  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (lastButtonState == HIGH && reading == LOW)
    {
      manualOverride = true;
      pumpState = !pumpState;

      Serial.print("Button Pressed: Pump ");
      Serial.println(pumpState ? "ON" : "OFF");
    }
  }

  lastButtonState = reading;
}


// ---------- Serial Commands ----------
void handleSerial()
{
  if (Serial.available())
  {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "FORCE_ON")
    {
      manualOverride = true;
      pumpState = true;

      Serial.println("Pump Forced ON");
    }

    else if (cmd == "FORCE_OFF")
    {
      manualOverride = true;
      pumpState = false;

      Serial.println("Pump Forced OFF");
    }

    else if (cmd == "STATUS")
    {
      int soilValue = analogRead(SOIL_PIN);

      Serial.println("----- STATUS -----");

      Serial.print("Mode: ");
      Serial.println(manualOverride ? "MANUAL" : "AUTO");

      Serial.print("Pump: ");
      Serial.println(pumpState ? "ON" : "OFF");

      Serial.print("Soil Value: ");
      Serial.println(soilValue);
    }

    else if (cmd == "AUTO")
    {
      manualOverride = false;
      Serial.println("Returned to AUTO mode");
    }
  }
}