/*
 * Template pembacaan sensor suhu analog LM35 pada ESP32
 * Catatan: Kalibrasikan faktor konversi ADC dan penguatan op-amp sesuai rangkaian aktual.
 */

const int SENSOR_PIN = 34; // Gunakan pin ADC1 pada ESP32
const float VREF = 3.3;
const int ADC_MAX = 4095;
const float OPAMP_GAIN = 1.0; // Sesuaikan dengan gain rangkaian pengondisi sinyal

void setup() {
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
  int rawAdc = analogRead(SENSOR_PIN);
  float voltage = (rawAdc / (float)ADC_MAX) * VREF;
  float sensorVoltage = voltage / OPAMP_GAIN;
  float temperatureC = sensorVoltage * 100.0; // LM35: 10 mV per derajat Celsius

  Serial.print("ADC: ");
  Serial.print(rawAdc);
  Serial.print(" | Temp (C): ");
  Serial.println(temperatureC, 2);

  delay(2000);
}
