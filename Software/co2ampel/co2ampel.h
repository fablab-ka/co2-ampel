/*
  CO2 Ampel - PCB v2.0 + v1.0
  By: FabLab Karlsruhe e.V., Nils Roßmann
  https://github.com/fablab-ka/co2-ampel/
  Date: 13.10.2020
  License: MIT
*/

#ifndef CO2AMPEL_H
#define CO2AMPEL_H

void scd30ForceRecalibration(uint16_t concentration);
void setThresholdGreen(uint16_t th);
void setConfig(String& jsonString);

#endif
