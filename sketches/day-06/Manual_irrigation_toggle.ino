#include "config.h"
// debounce + setValve from prior days — linked tabs

unsigned long lastEventMs = 0;

void setup() {
  pinMode(LED_STATUS, OUTPUT);
  pinMode(BTN_MANUAL, INPUT_PULLUP);
  pinMode(RELAY_VALVE, OUTPUT);
  setValve(false);
  Serial.begin(9600);
}

void loop() {
  bool pressed = debouncePressed(BTN_MANUAL);
  setValve(pressed);
  digitalWrite(LED_STATUS, pressed ? HIGH : LOW);
  if (Serial.available() && Serial.read() == 's') {
    Serial.print(F("valve=")); Serial.println(pressed ? F("OPEN") : F("CLOSED"));
    Serial.print(F("lastEventMs=")); Serial.println(lastEventMs);
  }
  if (pressed) lastEventMs = millis();
}
