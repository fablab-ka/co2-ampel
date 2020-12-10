/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/

#ifndef WIFI_H
#define WIFI_H

#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager (2.0.3-alpha)

#include "config.h"
#include "ConfigManager.h"
#include "buzzer.h"
#include "led.h"


void loopWifi(ConfigManager &configManager);
void setupWifi(ConfigManager &configManager);
void startPortalCallback(WiFiManager*);
void connectedCallback(const WiFiEventStationModeGotIP&);
uint8_t isWifiConnected();


#endif
