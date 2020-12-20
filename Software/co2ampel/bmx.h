/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 16.12.2020
  License: MIT
*/
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_BMP280.h>

#ifndef BMX_H
#define BMX_H

extern Adafruit_Sensor *bmxTemp;
extern Adafruit_Sensor *bmxPressure;


void bmxSetup();
uint8_t bmxReadID(uint8_t i2caddr);
bool isBmxReady();

#endif
