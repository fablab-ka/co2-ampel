/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/

#include "ConfigManager.h"

ConfigManager::ConfigManager():
  m_status(255)
{}

int8_t ConfigManager::readConfig(const char *fileName) 
{
  if (!LittleFS.begin()) {
    Serial.print(F("Mounting LittleFS failed"));
    m_status=3;
    return m_status;
  }
  File file = LittleFS.open(fileName, "r");
  if(file) {
    DeserializationError error = deserializeJson(m_doc, file);
    if (error) {
      Serial.print(F("Failed to parse config file: "));
      Serial.println(fileName);
      file.close();
      m_status=2;
      return m_status;
    }
  } else {
      Serial.print(F("Failed to open config file: "));
      Serial.println(fileName);
      m_status=1;
      return m_status;
  }
  file.close();
  m_status=0;
  Serial.print(F("SUCCESS: parsed config file: "));
  Serial.println(fileName);

  if(CONFIGMANAGER_DEBUG) {
    serializeJson(m_doc, Serial);
    Serial.println("");
  }
  
  return m_status;
}

const char* ConfigManager::getCharValue(const char* key, const char *defaultValue)
{
  if(m_status==0) return m_doc[key] | defaultValue;
  return defaultValue;
}

uint16_t ConfigManager::getUintValue(const char* key, uint16_t defaultValue)
{
  if(m_status==0) return m_doc[key] | defaultValue;
  return defaultValue;
}
