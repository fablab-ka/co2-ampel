/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/
#include "bmx.h"

Adafruit_BME280* bme=0;
Adafruit_BMP280* bmp=0;

Adafruit_Sensor *bmxTemp=0;
Adafruit_Sensor *bmxPressure=0;

uint8_t bmxAddress=0x76;
uint8_t bmxId=255;

void bmxSetup() {
  bmxId=bmxReadID(bmxAddress);
  if(bmxId==255) {
    bmxAddress+=1;
    bmxId=bmxReadID(bmxAddress);
  }
  if(bmxId==0x60) {
    bme = new Adafruit_BME280;
    if (bme->begin(bmxAddress, &Wire)) {
      bmxTemp = bme->getTemperatureSensor();
      bmxPressure = bme->getPressureSensor();
      bme->setSampling(Adafruit_BME280::MODE_NORMAL,
        Adafruit_BME280::SAMPLING_X16, // Temp. oversampling
        Adafruit_BME280::SAMPLING_X16, // Pressure oversampling
        Adafruit_BME280::SAMPLING_X16, // Hum oversampling
        Adafruit_BME280::FILTER_OFF, // Filtering.
        Adafruit_BME280::STANDBY_MS_0_5 // Standby time.
      ); 
      Serial.print("Found bme280 at address ");
      Serial.println(bmxAddress);
    } 
  } else if(bmxId==BMP280_CHIPID) {
     bmp = new Adafruit_BMP280;
    if (bmp->begin(bmxAddress, BMP280_CHIPID)) {
      bmxTemp = bmp->getTemperatureSensor();
      bmxPressure = bmp->getPressureSensor();
      bmp->setSampling(Adafruit_BMP280::MODE_NORMAL,    // Operating Mode. 
        Adafruit_BMP280::SAMPLING_X16,     // Temp. oversampling
        Adafruit_BMP280::SAMPLING_X16,     // Pressure oversampling
        Adafruit_BMP280::FILTER_OFF,      // Filtering.
        Adafruit_BMP280::STANDBY_MS_4000  // Standby time.
      ); 
      Serial.print("Found bmp280 at address ");
      Serial.println(bmxAddress);
    }    
  }
}

uint8_t bmxReadID(uint8_t i2caddr) 
{
  Wire.beginTransmission(i2caddr);
  Wire.write(BME280_REGISTER_CHIPID);
  Wire.endTransmission();
  Wire.requestFrom(i2caddr, (byte)1);
  return Wire.read();
}

bool isBmxReady()
{ 
  return bmxTemp&&bmxPressure; 
}
