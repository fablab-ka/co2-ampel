# BOM (Stückliste)

Alle Komponenten bzw. baugleiche Alternativen auch bei Digikey erhältlich. Die LEDs sind bei Digikey erheblich teurer. Der BMP280 ist nicht zwingend erforderlich, erhöht jedoch die Genauigkeit der CO2-Meßwerte.

Falls die WLAN Reichweite des D1 mini nicht ausreicht, kann alternativ der D1 mini pro mit externer Antenne eingesetzt werden. Meist muss dann der 0Ohm Widerstand auf dem D1-Board umgelötet werden. Mit den D1 mini von Aliexpress Händlern hatten wir trotz guter Bewertung teilweise sehr instabile WLAN Verbindungen.

| Nr  | MPN  | Anzahl  |Referenz |Wert|Hersteller|Footprint|LCSC-Nr|Digikey-Nr|
| ------------ | ------------ | ------------ | ------------ |------------ |------------ |------------ |------------ |------------ |
| 01 | AZ1117EH-2.5TRG1 |1   |VR1 |LDO 2.5V|Diodes Incorporated|SOT-223 |[C92106][C92106] ||
| 02 | DMG2302UK-7 | 5 | Q1, Q2, Q3, Q4, Q7 |N-Mosfet|Diodes Incorporated|SOT-23-3|[C460977][C460977] ||
|03| TCC0805X7R104M500DT |30|C2, C5-C33|100n| CCTC|0805_C|[C360619][C360619] ||
|04|RS-05K103JT|9|R1, R2, R3, R4, R6, R7, R8, R9, R11|10k|FH(Guangdong Fenghua Advanced Tech)|0805_R|[C115295][C115295]||
|05|CC1206ZRY5V6BB106|2|C3, C4|10u| YAGEO|1206_C|[C113914][C113914] ||
|06|1206L110THYR|1|F1|Fuse 1A|	Littelfuse|1206|[C126818][C126818] ||
|07|RS-05K103JT|2|R10, R12|1k|FH(Guangdong Fenghua Advanced Tech)|0805_R|[C115295][C115295]|| 
|08|RT1A102M0810|1|C1|1000u| ROQANG|SMD,8x10.2mm |[C280406][C280406] ||
|09|BMP280|1|IC2|BMP280| Bosch Sensortec|LGA-8 |[C83291][C83291] ||
|10|SS24|1|D1|Diode 2A| MDD(Microdiode Electronics)|SMB(DO-214AA)|[C35501][C35501] ||
|11|WS2813C|28|LED1-LED28| WS2813C|Worldsemi|SMD,5x5mm |[C194323][C194323] ||
|12|SK-12E12-G5|1|SW1|Switch|Korean Hroparts Elec|Through Hole|[C136720][C136720]||
|13|C46392|1|J1|USB-B| Jing Extension of the Electronic Co.|Through Hole|[C46392][C46392]||
|14|YS-MBZ12085C05R42|1|SG1|Buzzer 5V|Fengming| 	Through Hole,12x8.5mm|[C409842][C409842]||
|15|SCD30|1|U$1|CO2-Sensor| Sensirion AG|Through Hole|| [1649-1098-ND][1649-1098-ND] |
|16|28983931346|1|D1|[d1][d1] |AZDelivery|Through Hole|||
|17|PCB-V2|1|PCB||jlcpcb||||
|18|[Case](../Case/OpenSCAD/case.stl)|1|Gehäuse|PLA 0.2mm|3D-Druck||||
|19|[Lid](../Case/OpenSCAD/lid.stl)|1|Deckel|PLA 0.2mm|3D-Druck||||
|20|Diffusor|2|Diffusor|3mm Akryl opal / PETG transparent|Lasercutter/3D-Druck||||
|21|[Smiley](../Case/SilhouetteStudio/smiley.svg)|1|Smiley|Vinyl Folie|Plotter/ausschneiden||||
|22|Netzteil|1|USB-Netzteil 5V/1A|Netzteil|diverse Hersteller||||
|23|USB-B-Kabel|1|USB-A Stekcer auf USB-B Buchse|USB-B-Kabel|diverse Hersteller||||

[C194323]: https://lcsc.com/product-detail/Light-Emitting-Diodes-LED_Worldsemi-WS2813C_C194323.html "C194323"
[C35501]: https://lcsc.com/product-detail/Schottky-Barrier-Diodes-SBD_MDD-Microdiode-Electronics-SS24_C35501.html "C35501"
[C83291]: https://lcsc.com/product-detail/Gas-Sensors_Bosch-Sensortec-BMP280_C83291.html "C83291"
[C280406]: https://lcsc.com/product-detail/Aluminum-Electrolytic-Capacitors-SMD_ROQANG-RT1A102M0810_C280406.html "C280406"
[C115295]: https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_FH-Guangdong-Fenghua-Advanced-Tech-RS-05K103JT_C115295.html "C115295"
[C126818]: https://lcsc.com/product-detail/PTC-Resettable-Fuses_Littelfuse-1206L110THYR_C126818.html "C126818"
[C113914]: https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_YAGEO-CC1206ZRY5V6BB106_C113914.html "C113914"
[C115295]: https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_FH-Guangdong-Fenghua-Advanced-Tech-RS-05K103JT_C115295.html "C115295"
[C360619]: https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_CCTC-TCC0805X7R104M500DT_C360619.html "C360619"
[C460977]: https://lcsc.com/product-detail/MOSFET_Diodes-Incorporated-DMG2302UK-7_C460977.html "C460977"
[C92106]: https://lcsc.com/product-detail/Dropout-Regulators-LDO_Diodes-Incorporated-AZ1117EH-2-5TRG1_C92106.html "C92106"
[C136720]: https://lcsc.com/product-detail/Toggle-Switches_Korean-Hroparts-Elec-SK-12E12-G5_C136720.html "C136720"
[C46392]: https://lcsc.com/product-detail/USB-Connectors_Jing-Extension-of-the-Electronic-Co-C46392_C46392.html "C46392"
[C409842]: https://lcsc.com/product-detail/Buzzers_Fengming-YS-MBZ12085C05R42_C409842.html "C409842"
[1649-1098-ND]: https://www.digikey.de/product-detail/de/sensirion-ag/SCD30/1649-1098-ND/8445334 "1649-1098-ND"
[d1]: https://www.az-delivery.de/products/d1-mini?variant=28983931346 "D1 Mini NodeMcu mit ESP8266-12F"

