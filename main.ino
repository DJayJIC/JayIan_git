#include <ESP8266WiFi.h>
#include "sensor.h"
#include "wifi_config.h"
#include "web_server.h"

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  initSensors();
  connectWiFi();
  initWebServer();
}

void loop() {
  handleWebServer();
  float temp = readTemperature();
  float hum = readHumidity();
  bool motion = readMotion();
  
  Serial.print("Temperature: "); Serial.print(temp); Serial.println("°C");
  Serial.print("Humidity: "); Serial.print(hum); Serial.println("%");
  Serial.print("Motion: "); Serial.println(motion ? "Detected" : "None");
  
  updateSensorData(temp, hum, motion);
  delay(2000);
}