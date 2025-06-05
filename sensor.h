#ifndef SENSOR_H
#define SENSOR_H

#include <DHT.h>

#define DHT_PIN D4
#define PIR_PIN D5
#define LED_PIN D6
#define DHT_TYPE DHT11

void initSensors();
float readTemperature();
float readHumidity();
bool readMotion();

#endif