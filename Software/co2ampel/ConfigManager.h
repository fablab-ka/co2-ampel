/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/

#ifndef ConfigManager_h
#define ConfigManager_h

#include <LittleFS.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson (6.16.1, don't install 6.17.0)

#include "config.h"

class ConfigManager {
 public:
  ConfigManager();
  int8_t readConfig(const char *fileName);
  int8_t readConfig(const String file) {
    return readConfig(file.c_str());
  };
  const char *getCharValue(const char* key, const char *defaultValue = '\0');
  uint16_t getUintValue(const char* key, uint16_t defaultValue = 0);

  private:
    StaticJsonDocument<1024> m_doc;
    uint8_t m_status;
  
};
#endif
