/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/


#include "buzzer.h"

void beep(ConfigManager &configManager, int count, bool ignoreSwitch) {
  if(!configManager.getUintValue("buzzer_enabled", BUZZER_ENABLED)) return;
  
  #ifdef GPIO_SWITCH
  int switchState = digitalRead(GPIO_SWITCH);
  if(!switchState && !ignoreSwitch) return;
  #endif
  
  for (int i=0; i<count; i++) {
    Serial.println("buzzer");
    if(i>0) delay(500);
    tone(GPIO_BUZZER,2093);
    delay(500);
    noTone(GPIO_BUZZER);
  }
}

void beepOK(ConfigManager &configManager) {
  if(!configManager.getUintValue("buzzer_enabled", BUZZER_ENABLED)) return;
  int okMelody[] = {440,554,659};
  int okNoteDurations[] = {150,150,300};

  for (int note=0; note < 3; note++){
    tone(GPIO_BUZZER, okMelody[note]);
    delay(okNoteDurations[note]);
  
    noTone(GPIO_BUZZER);
    delay(20);
  }
}

void beepFailure(ConfigManager &configManager) {
  if(!configManager.getUintValue("buzzer_enabled", BUZZER_ENABLED)) return;
  int failureMelody[] = {220,208,196,185};
  int failureNoteDurations[] = {200,200,200,400};

  for (int note=0; note < 4; note++){
    tone(GPIO_BUZZER, failureMelody[note]);
    delay(failureNoteDurations[note]);
  
    noTone(GPIO_BUZZER);
    delay(10);
  }
}
