/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/

#ifndef BUZZER_H
#define BUZZER_H

#include "ConfigManager.h"
#include "config.h"

void beep(ConfigManager &configManager, int count, bool ignoreSwitch=false);
void beepOK(ConfigManager &configManager);
void beepFailure(ConfigManager &configManager);

#endif
