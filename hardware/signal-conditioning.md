# Analog Signal Conditioning Notes (LM35 + ESP32)

Dokumen ini merangkum catatan perancangan dan kalibrasi jalur sinyal analog pada node pemantauan suhu:

- **Sensor:** LM35 (keluaran tegangan linier terhadap suhu dalam satuan Celsius).
- **Op-Amp Stage:** Digunakan untuk penguatan/penyesuaian level tegangan sinyal sebelum masuk ke pin ADC ESP32.
- **Low-Pass Filter (LPF):** Digunakan untuk meredam *noise* frekuensi tinggi agar pembacaan ADC lebih stabil.
- **Kalibrasi Lapangan:** Bandingkan hasil pembacaan ADC/suhu dengan termometer referensi atau multimeter, lalu catat faktor koreksi/offset aktualnya di sini.
