
#include "web_server.h"
#include "sensor.h"

ESP8266WebServer server(80);
float lastTemp = 0.0;
float lastHum = 0.0;
bool lastMotion = false;

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>Smart Home Monitor</h1>";
  html += "<p>Temperature: " + String(lastTemp) + "°C</p>";
  html += "<p>Humidity: " + String(lastHum) + "%</p>";
  html += "<p>Motion: " + String(lastMotion ? "Detected" : "None") + "</p>";
  html += "<a href=\"/led/on\">Turn LED On</a><br>";
  html += "<a href=\"/led/off\">Turn LED Off</a>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleLedOn() {
  digitalWrite(LED_PIN, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLedOff() {
  digitalWrite(LED_PIN, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void initWebServer() {
  server.on("/", handleRoot);
  server.on("/led/on", handleLedOn);
  server.on("/led/off", handleLedOff);
  server.begin();
  Serial.println("Web server started");
}

void handleWebServer() {
  server.handleClient();
}

void updateSensorData(float temp, float hum, bool motion) {
  lastTemp = temp;
  lastHum = hum;
  lastMotion = motion;
}