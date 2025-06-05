#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <ESP8266WebServer.h>

extern ESP8266WebServer server;
void initWebServer();
void handleWebServer();
void updateSensorData(float temp, float hum, bool motion);

#endif