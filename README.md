# ESP32 Distributed Temperature Monitoring System

Sistem pemantauan suhu terdistribusi berbasis mikrokontroler **ESP32** dan sensor analog **LM35** dengan rangkaian pengondisi sinyal (*op-amp* & *low-pass filter*), terintegrasi ke **Firebase Realtime Database** serta *dashboard* web visualisasi.

## Arsitektur Sistem
1. **Sensor & Pengondisi Sinyal:** Pembacaan tegangan analog LM35 yang diperkuat dan difilter untuk mengurangi *noise* frekuensi tinggi.
2. **Node Mikrokontroler (ESP32):** Akuisisi ADC, kalibrasi suhu, dan pengiriman data berkala melalui Wi-Fi.
3. **Cloud & Visualisasi:** Penyimpanan *real-time* di Firebase dan tampilan grafik/peta spasial berbasis HTML/JavaScript.
