/*
 * ESP32 LM35 Temperature Acquisition (Draft / Baseline)
 * Catatan:
 * - Sesuaikan PIN_LM35, OPAMP_GAIN, dan VREF sesuai rangkaian aktual.
 * - Jangan hardcode password Wi-Fi atau kredensial Firebase di file publik.
 */

const int PIN_LM35 = 34;         // Pin ADC1 pada ESP32
const float VREF = 3.3;          // Tegangan referensi ADC ESP32
const float ADC_RESOLUTION = 4095.0;
const float OPAMP_GAIN = 1.0;    // Ubah sesuai faktor penguatan op-amp (misal 1.5, 2.0, dll.)
const int SAMPLE_COUNT = 16;     // Jumlah sampel untuk perata-rataan (averaging)
const unsigned long INTERVAL_MS = 2000;

unsigned long lastReadTime = 0;

float readFilteredVoltage() {
  long sumAdc = 0;
  for (int i = 0; i < SAMPLE_COUNT; i++) {
    sumAdc += analogRead(PIN_LM35);
    delay(5);
  }
  float avgAdc = sumAdc / (float)SAMPLE_COUNT;
  float measuredVolt = (avgAdc / ADC_RESOLUTION) * VREF;
  return measuredVolt / OPAMP_GAIN;
}

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
  delay(500);
  Serial.println("ESP32 LM35 Reader initialized.");
}

void loop() {
  unsigned long now = millis();
  if (now - lastReadTime >= INTERVAL_MS) {
    lastReadTime = now;

    float sensorVolt = readFilteredVoltage();
    // LM35 memiliki skala tipikal 10 mV per derajat Celsius (0.01 V/C)
    float tempC = sensorVolt / 0.01;

    Serial.print("Sensor Voltage (V): ");
    Serial.print(sensorVolt, 4);
    Serial.print(" | Estimated Temp (C): ");
    Serial.println(tempC, 2);
  }
}
