import json
import math
import random
import time
from http.server import SimpleHTTPRequestHandler, ThreadingHTTPServer

START_TIME = time.time()
CURRENT_TEMP = 29.8


class TelemetryHandler(SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, directory="/home/bmbngsh/iot-backend", **kwargs)

    def do_GET(self):
        global CURRENT_TEMP
        if self.path.startswith("/api/telemetry"):
            elapsed = time.time() - START_TIME
            wave = math.sin(elapsed / 8.0) * 1.4
            noise = random.uniform(-0.45, 0.45)
            CURRENT_TEMP = max(22.0, min(75.0, (CURRENT_TEMP * 0.85) + ((29.8 + wave + noise) * 0.15)))

            raw_volt = round(CURRENT_TEMP * 0.01, 4)
            filtered_volt = round(raw_volt * 2.0, 4)
            status = "ALERT" if CURRENT_TEMP >= 45.0 else ("WARNING" if CURRENT_TEMP >= 41.0 else "NORMAL")

            payload = {
                "timestamp": time.strftime("%Y-%m-%dT%H:%M:%S%z"),
                "uptime_sec": int(elapsed),
                "sensor": "LM35 + Op-Amp (2.0x) + LPF",
                "temperature_c": round(CURRENT_TEMP, 2),
                "raw_voltage_v": raw_volt,
                "filtered_voltage_v": filtered_volt,
                "status": status,
            }
            body = json.dumps(payload).encode("utf-8")
            self.send_response(200)
            self.send_header("Content-Type", "application/json; charset=utf-8")
            self.send_header("Cache-Control", "no-store")
            self.send_header("Content-Length", str(len(body)))
            self.end_headers()
            self.wfile.write(body)
            return

        return super().do_GET()

    def log_message(self, format, *args):
        pass


if __name__ == "__main__":
    server = ThreadingHTTPServer(("127.0.0.1", 8080), TelemetryHandler)
    print("IoT backend listening on http://127.0.0.1:8080")
    server.serve_forever()
