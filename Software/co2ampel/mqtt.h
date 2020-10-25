/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/

#ifndef MQTT_H
#define MQTT_H

#include <ESP8266WiFi.h>
#include <PubSubClient.h> // https://github.com/knolleary/pubsubclient
#include <WiFiClientSecure.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson

#include "ConfigManager.h"
#include "config.h"
#include "led.h"

void loopMQTT(ConfigManager &configManager);
void setupMQTT(ConfigManager &configManager);
void publishValues(ConfigManager &configManager, uint16_t co2, double hum ,double temp, double pressure, double temp2, Color color, float RssI, uint32_t runtime);

#endif
