/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/

#ifndef LED_H
#define LED_H

//#include <Adafruit_NeoPixel.h> //https://github.com/adafruit/Adafruit_NeoPixel (1.6.0)
#include <FastLED.h>

#include "config.h"

void setupLED();
void ledSetColor(Color color);
void ledBlink(Color c1, Color c2, uint32_t time);
void ledSetBrightnes(uint8_t brightness);

#endif
