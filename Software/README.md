# Arduino Sketch
## Voraussetzungen
In Klammern steht jeweils die von uns getestete Version.
- [Arduino IDE(1.8.13)][IDE]
- [Arduino core for ESP8266 WiFi chip (2.7.4)][esp8266core], siehe [Installationsanleitung von heise][esp8266heise]
- Arduino Libaries
  - [SparkFun SCD30 Arduino Library (1.0.8)][scd30lib]
  - [Adafruit BMP280 Library (2.1.0)][bmp280lib]
  - [Adafruit BME280 Library (2.1.1)][bme280lib]
  - [ArduinoJson (6.17.1)][arduinojsonlib] **HINWEIS**: Die [Version 6.17.0 hat einen Bug][arduinojsonbug] und ist daher aktuell nicht kompatibel. Bitte achtet darauf, die Version 6.17.1 oder 6.16.1 zu installieren.
  - [FastLED (3.3.3)][FstLED]
  - [PubSubClient (2.8.0)][pubsubclientlib]
  - [WiFiManager (2.0.3-alpha)][wifimanagerlib]

[IDE]: https://www.arduino.cc/en/software "aktuelle Arduino IDE(1.8.13)"
[esp8266core]: https://github.com/esp8266/Arduino "Arduino core for ESP8266 WiFi chip"
[esp8266heise]: https://www.heise.de/ct/artikel/Arduino-IDE-installieren-und-fit-machen-fuer-ESP8266-und-ESP32-4130814.html "Installationsanleitung von heise"
[scd30lib]: https://github.com/sparkfun/SparkFun_SCD30_Arduino_Library "SparkFun SCD30 Arduino Library (1.0.8)"
[bmp280lib]: https://github.com/adafruit/Adafruit_BMP280_Library "Adafruit BMP280 Library (2.1.0)"
[bme280lib]: https://github.com/adafruit/Adafruit_BME280_Library "Adafruit BMP280 Library (2.1.0)"
[arduinojsonlib]: https://github.com/bblanchon/ArduinoJson "ArduinoJson (6.16.1)"
[arduinojsonbug]: https://github.com/bblanchon/ArduinoJson/issues/1411 "Version 6.17.0 hat einen Bug"
[FstLED]: https://github.com/FastLED/FastLED "FastLED (3.3.3)"
[pubsubclientlib]: https://github.com/knolleary/pubsubclient/ "PubSubClient (2.8.0)"
[wifimanagerlib]: https://github.com/tzapu/WiFiManager "WiFiManager (2.0.3-alpha)"
[fsuploader]: https://github.com/earlephilhower/arduino-esp8266littlefs-plugin "Arduino ESP8266 LittleFS Filesystem Uploader"
## Installation
- Oben aufgeführte Libraries und Boards unter Arduino installieren
- LittleFS Uploader in <home_dir>/Arduino/tools entpacken
- Arduino Board auswählen: LOLIN(WEMOS) D1 R2 & mini

## Mikrocontroller flashen
- config.json im data Verzeichnis anpassen (MQTT Server, MQTT Zugangsdaten)
- Sketch compilieren und auf Board laden
- ESP8266 LittleFS Data Upload starten (kopiert die config.json und backup.json auf das Board). Der serielle Monitor muss dazu vorher geschlossen werden.
