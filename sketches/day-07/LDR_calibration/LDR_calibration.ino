
// Pin definition
#define LDR_PIN A0

// Circuit constants
const float VREF = 5.0;
const float FIXED_RESISTOR = 10.0; // 10kΩ

void setup() {
  Serial.begin(9600);
  Serial.println("=== Day 7: LDR Calibration ===");
  Serial.println("Circuit: LDR + 10kΩ to GND");
  Serial.println("Observe values in Serial Monitor\n");
  
  // Print CSV header
  Serial.println("Time_ms,Raw_ADC,Voltage_V,Resistance_kOhm,Light_Level");
}

void loop() {
  // Read LDR
  int ldrRaw = analogRead(LDR_PIN);
  
  // Calculate voltage: Vout = (ADC * Vref) / 1024
  float voltage = (ldrRaw * VREF) / 1024.0;
  
  // Calculate LDR resistance using voltage divider formula
  // R_LDR = R_fixed * (Vref/Vout - 1)
  float resistance = 0;
  if (ldrRaw > 0) {
    resistance = FIXED_RESISTOR * ((VREF / voltage) - 1.0);
  }
  
  // Classify light level
  String lightLevel;
  if (ldrRaw >= 900) lightLevel = "PITCH_DARK";
  else if (ldrRaw >= 750) lightLevel = "DARK";
  else if (ldrRaw >= 500) lightLevel = "DIM";
  else if (ldrRaw >= 300) lightLevel = "AMBIENT";
  else if (ldrRaw >= 150) lightLevel = "BRIGHT";
  else lightLevel = "VERY_BRIGHT";
  
  // Print CSV data
  Serial.print(millis());
  Serial.print(",");
  Serial.print(ldrRaw);
  Serial.print(",");
  Serial.print(voltage, 3);
  Serial.print(",");
  Serial.print(resistance, 1);
  Serial.print(",");
  Serial.println(lightLevel);
  
  delay(500); // 2 readings per second
}