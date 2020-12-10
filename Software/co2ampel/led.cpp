/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/


#include "led.h"
#include "wifi.h"

uint8_t ledBrightnes;

#ifdef PCBV2
CRGB led1[NUMPIXELS1];
CRGB led2[NUMPIXELS2];
#endif

#ifdef PCBV1
void setupLED() {
  pinMode(GPIO_GREEN, OUTPUT);
  pinMode(GPIO_YELLOW, OUTPUT);
  pinMode(GPIO_RED, OUTPUT);
  digitalWrite(GPIO_GREEN,0);
  digitalWrite(GPIO_YELLOW,0);
  digitalWrite(GPIO_RED,0);
}

void ledSetColor(Color color) {
  uint8_t red=0;
  uint8_t green=0;
  uint8_t yellow=0;
  switch (color) {
    case RED: red=1; break;
    case YELLOW: yellow=1; break;
    case GREEN: green=1; break;
    case WHITE: green=1;yellow=1;red=1; break;
  }
  digitalWrite(GPIO_RED,red); digitalWrite(GPIO_YELLOW,yellow); digitalWrite(GPIO_GREEN,green);
}
#endif

#ifdef PCBV2
void setupLED() {
  // some boards have problems with the "WS2813" settings, so we use NEOPIXEL as they also support ws2813
  FastLED.addLeds<NEOPIXEL, GPIO_LED1>(led1, NUMPIXELS1);
  FastLED.addLeds<NEOPIXEL, GPIO_LED2>(led2, NUMPIXELS2);
  FastLED.show();
  FastLED.show();
}

void ledSetColor(Color color) {

  uint8_t brightnes=ledBrightnes;
  int switchState = digitalRead(GPIO_SWITCH);
  if(!switchState && isWifiConnected()) brightnes=0;

  FastLED.setBrightness(brightnes);

  switch (color) {
    case RED:
      fill_solid(led1,NUMPIXELS1,CRGB::Black);
      fill_solid(led2,NUMPIXELS2,CRGB::Red); 
      break;
    case YELLOW:
      fill_solid(led1,NUMPIXELS1,CRGB::Black);
      fill_solid(led2,NUMPIXELS2,CRGB(255,128,0)); 
      break;
    case GREEN: 
      fill_solid(led1,NUMPIXELS1,CRGB::Green);
      fill_solid(led2,NUMPIXELS2,CRGB::Black); 
      break;
    case BLUE:
      fill_solid(led1,NUMPIXELS1,CRGB::Black);
      fill_solid(led2,NUMPIXELS2,CRGB::Blue);
      break;
    case WHITE: 
      fill_solid(led1,NUMPIXELS1,CRGB::White);
      fill_solid(led2,NUMPIXELS2,CRGB::White);
      break;
    case RED2:
      fill_solid(led1,NUMPIXELS1,CRGB::Red);
      fill_solid(led2,NUMPIXELS2,CRGB::Red); 
      break;
    case YELLOW2:
      fill_solid(led1,NUMPIXELS1,CRGB(255,128,0));
      fill_solid(led2,NUMPIXELS2,CRGB(255,128,0));
      break;
    case GREEN2:
      fill_solid(led1,NUMPIXELS1,CRGB::Green);
      fill_solid(led2,NUMPIXELS2,CRGB::Green);
      break;
    case DARK:
      fill_solid(led1,NUMPIXELS1,CRGB::Black);
      fill_solid(led2,NUMPIXELS2,CRGB::Black);
      break;
  }

  FastLED.show();
}
#endif

void ledBlink(Color c1, Color c2, uint32_t time)
{
  uint32_t start=millis();
  while (abs(millis()-start) < time) {
    ledSetColor(c1);
    delay(500);
    ledSetColor(c2);
    delay(500);
  }
  ledSetColor(DARK);
}

void ledSetBrightnes(uint8_t brightness) { 
  ledBrightnes = brightness; 
}
