/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/

#include "wifi.h"

// wifi manager
WiFiManager* wm = new WiFiManager;
WiFiEventHandler wifiConnectedHandler;

uint32_t wifiLastPrint=0;
uint32_t wifiPortalStartTime=0;
uint8_t wifiPortalStarted=0;
uint8_t wifiConnected=0;
uint32_t wifiBeginnTime=0;
uint8_t wifiUsePortal=0;
uint8_t wifiFirstConnect=0;

void setupWifi(ConfigManager &configManager) {
    
  // connect wifi
  Serial.println();

  
  WiFi.hostname(configManager.getCharValue("mqtt_username", "ESP"));
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  WiFi.forceSleepWake();
  wifiConnectedHandler = WiFi.onStationModeGotIP(connectedCallback);
  delay( 1 );
  WiFi.setOutputPower(20.5);
  WiFi.mode(WIFI_STA);

  wm->setConfigPortalBlocking(false);
  wm->setAPCallback(startPortalCallback);
  wm->setConnectTimeout(configManager.getUintValue("wifi_connect_timeout", WIFI_CONNECT_TIMEOUT) );

  if(WiFi.SSID() != "" && WiFi.psk() != "") {
    WiFi.begin(); 
    Serial.println("connect with saved credentials");
    wifiBeginnTime=millis();
  } else {
    Serial.println("start config portal");
    wm->startConfigPortal(configManager.getCharValue("wifi_ap_ssid", WIFI_AP_SSID), configManager.getCharValue("wifi_ap_password", WIFI_AP_PASSWORD));
    wifiPortalStartTime=millis();
    wifiUsePortal=1;
  }
}


void loopWifi(ConfigManager &configManager) {
    if(wm && !wifiConnected && !wifiPortalStarted && abs(millis() - wifiBeginnTime) >  configManager.getUintValue("wifi_connect_timeout", WIFI_CONNECT_TIMEOUT)*1000) {
      Serial.println("wifi connect timeout reached, start portal");
      wm->startConfigPortal(configManager.getCharValue("wifi_ap_ssid", WIFI_AP_SSID),configManager.getCharValue("wifi_ap_password", WIFI_AP_PASSWORD));
      wifiPortalStartTime=millis();    
      wifiBeginnTime=0;
      wifiUsePortal=1;
  }
  if(wm) wm->process();
  if (wm && wifiPortalStarted && abs(millis() - wifiPortalStartTime) >= configManager.getUintValue("wifi_portal_timeout", WIFI_PORTAL_TIMEOUT)*1000 && !WiFi.softAPgetStationNum()) {
    Serial.print("disable WiFiManager, wifi status: ");
    delete wm;
    wm=0;
    Serial.print("wifimanager deaktiviert: ");
    wifiPortalStarted=0;
    Serial.println(WiFi.status());
    if(WiFi.SSID() != "" && WiFi.psk() != "") {
      WiFi.mode( WIFI_STA );
      WiFi.begin(); 
    } else {
      WiFi.mode( WIFI_OFF );
    }
  }

  if(wm && wifiConnected) {
    delete wm;
    wm=0;
    if(wifiUsePortal) {
      wifiUsePortal=0;
      beepOK(configManager);
    }
    Serial.println("connectedCallback wifimanager deaktiviert: ");
  }

  if(wifiConnected && !wifiFirstConnect) {
    wifiFirstConnect=1;
    ledBlink(WHITE,DARK,1000);
  }
  
  if(abs(millis() - wifiLastPrint) >= 1000) {
     Serial.println(WiFi.status());
     wifiLastPrint=millis();
  }
}


void startPortalCallback(WiFiManager* wm) {
  Serial.println("AP MODE GESTARTET: ");
  wifiPortalStartTime=millis();
  wifiPortalStarted=1;
}

void connectedCallback(const WiFiEventStationModeGotIP& event) {
  wifiConnected=1;
  Serial.print("VERBUNDEN: ");
  Serial.println(event.ip);
}

uint8_t isWifiConnected() {
  return wifiConnected;
}
