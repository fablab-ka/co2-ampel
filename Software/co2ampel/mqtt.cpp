/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/

#include "mqtt.h"


WiFiClientSecure wifiClient;
PubSubClient mqttClient(wifiClient);
long lastMQTTReconnectAttempt = 0;

uint8_t failedCounter;
uint8_t mqttFirstConnect=0;


void setupMQTT(ConfigManager &configManager) 
{
  wifiClient.setFingerprint(configManager.getCharValue("ssl_fingerprint", SSL_FINGERPRINT));
  mqttClient.setServer(configManager.getCharValue("mqtt_host", MQTT_HOST),configManager.getUintValue("mqtt_port", MQTT_PORT));
  
}


bool reconnectMQTT(ConfigManager &configManager) {
  mqttClient.connect(configManager.getCharValue("mqtt_username", "\0"), configManager.getCharValue("mqtt_username", "\0"), configManager.getCharValue("mqtt_password", "\0"));
  return mqttClient.connected();
}

void loopMQTT(ConfigManager &configManager)
{
  if (!mqttClient.connected()) {
    if (millis() - lastMQTTReconnectAttempt > 5000) {
      lastMQTTReconnectAttempt = millis();
      if (WiFi.status() == WL_CONNECTED) {
        if (reconnectMQTT(configManager)) {
          Serial.println("mqtt connected");
          lastMQTTReconnectAttempt = 0;
          failedCounter=0;
          if(!mqttFirstConnect) {
            mqttFirstConnect=1;
            ledBlink(WHITE,DARK,2000);
          }
        } else {
          Serial.println("mqtt connect failed");
        }
      } else {
        Serial.println("wlan not connected");
      }
    }
  } else { // connected
    mqttClient.loop();
  }
}

void publishValues(ConfigManager &configManager, uint16_t co2, double hum, double temp, double pressure, double temp2, Color color, float RssI, uint32_t runtime) {
  if (!mqttClient.connected()) {
    Serial.print("MQTT not connected, cant publish!");
    return;
  }
  StaticJsonDocument<256> root;
  root["sensor"] = configManager.getCharValue("mqtt_username", "UNKNOWN");
  JsonObject data = root.createNestedObject("data");
  data["co2"] = co2;
  data["humidity"] = hum;
  data["temp"] = temp;
  data["pressure"] = pressure;
  data["temp2"] = temp2;
  data["color"] = int(color);
  data["rssi"] = RssI;
  data["runtime"] = runtime;
  char buffer[512];
  serializeJson(root, buffer);
  String topic = "sensors/"+String(configManager.getCharValue("mqtt_organisation", MQTT_ORGANISATION))+"/"+String(configManager.getCharValue("mqtt_username", "UNKNOWN"));
  if (!mqttClient.publish(topic.c_str(), buffer))  {
    Serial.print(F("Sensor value publish Failed!"));
    failedCounter++;
  } else {
    Serial.print(F("Sensor value publish OK! "));
  }
  Serial.println(buffer);
  if(failedCounter > 100) {
    while (1) // freeze
      ;
  }
}
