/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/

#ifndef CONFIG_H
#define CONFIG_H

/******************************* Version **************************************/
#define VERSION 7

/******************************* MQTT **************************************/

#define MQTT_HOST "co2-mqtt.fablab-karlsruhe.de" // overriden by mqtt_host from config.json 
#define MQTT_PORT 443 // overriden by mqtt_port from config.json 

#define SSL_FINGERPRINT "06 d8 e3 d2 f7 5c 57 69 45 29 f6 4e 8c 3e 19 95 32 39 b4 6e" // overriden by ssl_fingerprint from config.json 
#define MQTT_INTERVAL 4000 // overriden by mqtt_interval from config.json 


/******************************* WIFI **********************SCD30_MEASUREMENT_INTERVAL****************/

#define WIFI_ENABLED 1 // overriden by wifi_enabled from config.json 
#define WIFI_AP_SSID "CO2Ampel" // overriden by wifi_ap_ssid from config.json 
#define WIFI_AP_PASSWORD "CHANGEME" // overriden by wifi_ap_password from config.json 
#define WIFI_PORTAL_TIMEOUT 120 //seconds // overriden by wifi_portal_timeout from config.json 
#define WIFI_CONNECT_TIMEOUT 60 //seconds // overriden by wifi_connect_timeout from config.json 

/******************************* Colors **************************************/
enum Color {GREEN, YELLOW, RED, BLUE, DARK, WHITE, GREEN2, YELLOW2, RED2};


/******************************* scd30 **************************************/
#define SCD30_AUTOCALIBRATION 0
#define SCD30_CALIBRATION_MIN_RUNTIME 180 //seconds
#define SCD30_MEASUREMENT_INTERVAL 2 // seconds (recalibrate, if you change this value)
#define SCD30_MIN_PPM 350
#define SCD30_CALIBRATION_PPM 450 // overriden by calibration_ppm from config.json 

/******************************* thresholds **************************************/
#define TH_GREEN 800 //overriden by th_green from config.json
#define TH_YELLOW_LOW 1000 //overriden by th_yellow_low from config.json
#define TH_YELLOW_HIGH 1500 //overriden by th_yellow_high from config.json
#define TH_RED 2000 //overriden by th_red from config.json

/******************************* MISC **************************************/
#define CONFIGMANAGER_DEBUG 1

/* ***************************** PCB Revision *************************/
#define PCBV2



/************************* ESP8266 PCB V2*********************************/
/* esp8266 D1 mini PINOUT
 *  A0 ununsed
 *  D0 GPIO16 Switch 
 *  D1 GPIO5  I2C SCL
 *  D2 GPIO4  I2C SDA
 *  D3 GPIO0  LED_DATA 2 (sad face)
 *  D4 GPIO2 unused
 *  D5 GPIO14 Buzzer
 *  D6 GPIO12 LED_DATA 1 (happy face)
 *  D7 GPIO13 SCD30 Ready
 *  D8 GPIO15 unused
 *  TX GPIO1 unused
 *  RX GPIO3 unused
 */

#ifdef PCBV2
// LEDS
#define NUMPIXELS1 14
#define NUMPIXELS2 14
#define GPIO_LED1 12
#define GPIO_LED2 0
#define LED_BRIGHTNES 128 // % (0=dark, 255=full) overriden by led_brightness from config.json
//SCD30
#define GPIO_SCD30_RDY 13
#define SCD30_TEMP_OFFSET 7.0
// Switch
#define GPIO_SWITCH 16
// BUZZER
#define GPIO_BUZZER 14
#define BUZZER_ENABLED 1 //overriden by buzzer_enabled from config.json
// BM(E/P)280
#define BMX_ENABLED 1 //overriden by bmx_enabled from config.json
// self test
#define SELFTEST_ENABLED 1 //overriden by selftest_enabled from config.json 
#define SELFTEST_BUZZER 0 //overriden by selftest_buzzer from config.json 

#endif



/************************* ESP8266 PCB V1*********************************/
/* esp8266 D1 mini PINOUT
 *  A0 unused
 *  D0 GPIO16  
 *  D1 GPIO5  I2C SCL
 *  D2 GPIO4  I2C SDA
 *  D3 GPIO0  
 *  D4 GPIO2  BUZZER
 *  D5 GPIO14 LED RED
 *  D6 GPIO12 LED YELLOW
 *  D7 GPIO13 LED GREEN
 *  D8 GPIO15 SCD30 Ready
 *  TX GPIO1  unused
 *  RX GPIO3  unused
 */
#ifdef PCBV1
// LEDS
#define GPIO_GREEN 13
#define GPIO_YELLOW 12
#define GPIO_RED 14
#define LED_BRIGHTNES 255
//SCD30
#define GPIO_SCD30_RDY 15
#define SCD30_TEMP_OFFSET 3.0
// BUZZER
#define GPIO_BUZZER 2
#define BUZZER_ENABLED 1 //overriden by buzzer_enabled from config.json
// BME280
#define BMX_ENABLED 0 //overriden by bmx_enabled from config.json
// self test
#define SELFTEST_ENABLED 1 //overriden by selftest_enabled from config.json
#define SELFTEST_BUZZER 1 //overriden by selftest_buzzer from config.json 
#endif

#endif
