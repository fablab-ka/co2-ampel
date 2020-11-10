#include "led.h"

double ledBrightnes;

#ifdef PCBV2
Adafruit_NeoPixel led1 = Adafruit_NeoPixel(NUMPIXELS, GPIO_GREEN, NEO_GRB + NEO_KHZ400);
Adafruit_NeoPixel led2 = Adafruit_NeoPixel(NUMPIXELS, GPIO_RED, NEO_GRB + NEO_KHZ400);
#endif
/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/



#ifdef PCBV1
void setupLED(ConfigManager &configManager) {
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
  led1.begin();
  led1.show();
  led1.show();
  led2.begin();
  led2.show();
  led2.show();
}

void ledSetColor(Color color) {

  double brightnes=ledBrightnes;
  int switchState = digitalRead(GPIO_SWITCH);
  if(!switchState) brightnes=0;
  
  uint8_t red1=0;
  uint8_t green1=0;
  uint8_t blue1=0;
  uint8_t red2=0;
  uint8_t green2=0;
  uint8_t blue2=0;
  switch (color) {
    case RED: red2=255*brightnes; break;
    case YELLOW: red2=255*brightnes; green2=128*brightnes;  break;
    case GREEN: green1=255*brightnes;  break;
    case BLUE: blue2=255*brightnes; break;
    case WHITE: red1=255*brightnes;green1=255*brightnes;blue1=255*brightnes;red2=255*brightnes;green2=255*brightnes;blue2=255*brightnes; break;
    case RED2: red1=255*brightnes; red2=255*brightnes; break;
    case YELLOW2: red1=255*brightnes; green1=128*brightnes; red2=255*brightnes; green2=128*brightnes;  break;
    case GREEN2: green1=255*brightnes; green2=255*brightnes;  break;
    case DARK: break;
  }
  
  for(int i=0;i<NUMPIXELS;i++){
    led1.setPixelColor(i, led1.Color(red1,green1,blue1)); 
  }
  led1.show();  
  for(int i=0;i<NUMPIXELS;i++){
    led2.setPixelColor(i, led2.Color(red2,green2,blue2)); 
  }
  led2.show(); 
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

void ledSetBrightnes(double brightness) { 
  ledBrightnes = brightness; 
}
