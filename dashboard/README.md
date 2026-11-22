# ESP32 + LM35 Telemetry Dashboard

Antarmuka simulasi pemantauan suhu real-time berbasis HTML/SVG untuk sensor LM35 (10 mV/C) dengan pengkondisi sinyal (Op-Amp gain 2.0x dan Low-Pass Filter) serta kontrol ambang batas peringatan.

    python3 -m http.server 8080 --bind 127.0.0.1 --directory dashboard
