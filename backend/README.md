# ESP32 + LM35 Telemetry Backend & Dashboard

Backend Python di backend/server.py menyediakan endpoint JSON di /api/telemetry (suhu, tegangan raw LM35, tegangan output op-amp + LPF, dan status NORMAL/WARNING/ALERT) serta melayani dashboard interaktif di dashboard/index.html.

    python3 backend/server.py
