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

String mqttUsername="";
String mqttOrg="";

void setupMQTT(ConfigManager &configManager) 
{
  mqttUsername = configManager.getCharValue("mqtt_username", "");
  wifiClient.setFingerprint(configManager.getCharValue("ssl_fingerprint", SSL_FINGERPRINT));
  mqttClient.setBufferSize(1100);
  mqttClient.setServer(configManager.getCharValue("mqtt_host", MQTT_HOST),configManager.getUintValue("mqtt_port", MQTT_PORT));
  mqttClient.setCallback(mqttCallback);
  
}


bool reconnectMQTT(ConfigManager &configManager) {
  Serial.print("mqtt connect with username: ");
  Serial.println(mqttUsername);
  mqttClient.connect(mqttUsername.c_str(), mqttUsername.c_str(), configManager.getCharValue("mqtt_password", "\0"));
  if (mqttClient.connected() && mqttUsername!="") {
    String topic = String("config/")+mqttUsername+String("/#");
    mqttClient.subscribe(topic.c_str());
  }
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
  if (mqttOrg=="") {
    Serial.print("MQTT org unknown, cant publish!");
    return;
  }
  StaticJsonDocument<256> root;
  root["sensor"] = mqttUsername;
  JsonObject data = root.createNestedObject("data");
  data["co2"] = co2;
  data["humidity"] = hum;
  data["temp"] = temp;
  data["pressure"] = pressure;
  data["temp2"] = temp2;
  data["color"] = int(color);
  data["rssi"] = RssI;
  data["runtime"] = runtime;
  data["version"] = String(VERSION)+"."+String(configManager.getCharValue("version", "0"));
  char buffer[512];
  serializeJson(root, buffer);
  String topic = "sensors/"+mqttOrg+"/"+mqttUsername;
  if (!mqttClient.publish(topic.c_str(), buffer))  {
    Serial.print("Sensor value publish Failed!");
    failedCounter++;
  } else {
    Serial.print("Sensor value publish OK! ");
  }
  Serial.println(buffer);
  if(failedCounter > 100) {
    while (1) // freeze
      ;
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  String messageTemp;
  for (int i = 0; i < length; i++) {
    messageTemp += (char)payload[i];
  }
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  Serial.println(messageTemp);
  if (String(topic) == "config/"+mqttUsername+"/org") {
    mqttOrg=messageTemp;
  } else if (String(topic) == "config/"+mqttUsername+"/calibrate") {
    uint16_t concentration = messageTemp.toInt();
    Serial.println(concentration);
    if(concentration >= 400 && concentration <= 2000 && millis() > SCD30_CALIBRATION_MIN_RUNTIME*1000) {
      scd30ForceRecalibration(concentration);
    }
  } else if (String(topic) == "config/"+mqttUsername+"/json") {
    setConfig(messageTemp);
  }
}
