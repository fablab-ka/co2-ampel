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
    Serial.print("Mounting LittleFS failed");
    m_status=3;
    return m_status;
  }
  File file = LittleFS.open(fileName, "r");
  if(file) {
    DeserializationError error = deserializeJson(m_doc, file);
    if (error) {
      Serial.print("Failed to parse config file: ");
      Serial.println(fileName);
      file.close();
      m_status=2;
      return m_status;
    }
  } else {
      Serial.print("Failed to open config file: ");
      Serial.println(fileName);
      m_status=1;
      return m_status;
  }
  file.close();
  m_status=0;
  Serial.print("SUCCESS: parsed config file: ");
  Serial.println(fileName);

  if(CONFIGMANAGER_DEBUG) {
    serializeJson(m_doc, Serial);
    Serial.println("");
  }
  LittleFS.end();
  return m_status;
}

int8_t ConfigManager::writeConfig(const char *fileName) {
  if(m_status) {
    Serial.print("previous read failed, abort write");
    return m_status;
  }
  if (!LittleFS.begin()) {
    Serial.print("Mounting LittleFS failed");
    return 3;
  }
  LittleFS.remove(fileName);
  
  File file = LittleFS.open(fileName, "w");
  if(file) {
    serializeJson(m_doc, file);
  }
  delay(2000);
  file.close();
  
  LittleFS.end();
  return 0;
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


int8_t ConfigManager::writeConfig(const String jsonString, const char *fileName) {
  StaticJsonDocument<1024> doc;
  DeserializationError error = deserializeJson(doc, jsonString);
  if (error) {
    Serial.print("Failed to parse new config; ");
    Serial.println(jsonString);
    return 1;
  }
  m_doc=doc;
  return writeConfig(fileName);
}
