# BOM (Stückliste)

Alle Komponenten bzw. baugleiche Alternativen auch bei Digikey erhältlich. Die LEDs sind bei Digikey erheblich teurer. Der BMP280 ist nicht zwingend erforderlich, erhöht jedoch die Genauigkeit der CO2-Meßwerte.

Falls die WLAN Reichweite des D1 mini nicht ausreicht, kann alternativ der D1 mini pro mit externer Antenne eingesetzt werden. Meist muss dann der 0Ohm Widerstand auf dem D1-Board umgelötet werden. Mit den D1 mini von Aliexpress Händlern hatten wir trotz guter Bewertung teilweise sehr instabile WLAN Verbindungen.

| Nr  | MPN  | Anzahl  |Referenz |Wert|Hersteller|Footprint|LCSC-Nr|Digikey-Nr|
| ------------ | ------------ | ------------ | ------------ |------------ |------------ |------------ |------------ |------------ |
|01|DMG2302UK-7|1|Q7|N-Mosfet|Diodes Incorporated|SOT-23-3|[C460977][C460977]||
|02|TCC0805X7R104M500DT|29|C2, C5-C8, C10-C33|100n| CCTC|0805_C|[C360619][C360619]||
|03|1206L110THYR|1|F1|Fuse 1A|Littelfuse|1206|[C126818][C126818] ||
|04|0805W8F4700T5E|2|R10, R12|470R|UNI-ROYAL|0805_R|[C17710][C17710]||
|05|VZH102M0JTR-0810|1|C1|1000u|Lelon|SMD,8x10mm |[C134811][C134811]||
|06|0805W8F4701T5E|3|R1, R3, R11|4.7k|UNI-ROYAL|0805_R|[C17673][C17673]|| 
|07a|BME280|1|IC1|BME280|Bosch Sensortec|LGA-8 |[C92489][C92489]||
|07b|BMP280|1|IC1|BMP280|Bosch Sensortec|LGA-8 |[C83291][C83291]||
|07c|12239814426720|1|JP1|[GY-BMP280][GY-BMP280]|AZ-Delivery|Through Hole|||
|08|SN74AHCT125DR|1|IC2|SN74AHCT125DR|Texas Instruments|SOIC-14_150mil|[C155176][C155176]||
|09|SS24|1|D1|Diode 2A| MDD(Microdiode Electronics)|SMB(DO-214AA)|[C35501][C35501]||
|10|WS2813C|28|LED1-LED28| WS2813C|Worldsemi|SMD,5x5mm |[C194323][C194323]||
|11|SK-12D02VG4|1|SW1|Switch|SOFNG SK-12D02VG4|Through Hole|[C239529][C239529]|[A107673-ND][A107673-ND]|
|12|C46392|1|J1|USB-B| Jing Extension of the Electronic Co.|Through Hole|[C46392][C46392]|[102-3999-ND][102-3999-ND]|
|13|YS-MBZ12085C05R42|1|SG1|Buzzer 5V|Fengming| 	Through Hole,12x8.5mm|[C409842][C409842]|[433-1028-ND][433-1028-ND]|
|14|SCD30|1|U$1|CO2-Sensor| Sensirion AG|Through Hole||[1649-1098-ND][1649-1098-ND]|
|15|MTF185-107SY1|1|SCD30 Header|7pin|MINTRON|Through Hole,P=2.54mm|[C358721][C358721]|[PPTC071LFBN-RC][PPTC071LFBN-RC]|
|16|28983931346|1|D1|[d1][d1] |AZDelivery|Through Hole|||
|17|[PCB-V4.1](../PCB/Gerber/jlcpcb)|1|PCB||jlcpcb||||
|18|[Case](../Case/Fusion360/Case.stl)|1|Gehäuse|PLA 0.2mm|3D-Druck||||
|19|[Lid](../Case/Fusion360/Lid.stl)|1|Deckel|PLA 0.2mm|3D-Druck||||
|20|Diffusor|2|Diffusor|[3mm Akryl opal 70% Lichtdurchlässigkeit](../Case/Laser/diffusor.svg) / [PETG transparent](../Case/Fusion360/glass_top.stl)|Lasercutter/3D-Druck||||
|21|[Smiley](../Case/SilhouetteStudio/smiley.svg)|1|Smiley|Vinyl Folie|Plotter/ausschneiden||||
|22|Netzteil|1|USB-Netzteil 5V/1A|Netzteil|diverse Hersteller||||
|23|USB-B-Kabel|1|USB-A Stekcer auf USB-B Buchse|USB-B-Kabel|diverse Hersteller||||

[C460977]: https://lcsc.com/product-detail/MOSFET_Diodes-Incorporated-DMG2302UK-7_C460977.html "C460977"
[C360619]: https://lcsc.com/product-detail/Multilayer-Ceramic-Capacitors-MLCC-SMD-SMT_CCTC-TCC0805X7R104M500DT_C360619.html "C360619"
[C126818]: https://lcsc.com/product-detail/PTC-Resettable-Fuses_Littelfuse-1206L110THYR_C126818.html "C126818"
[C17710]: https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-0805W8F4700T5E_C17710.html "C17710"
[C134811]: https://lcsc.com/product-detail/Aluminum-Electrolytic-Capacitors-SMD_Lelon-VZH102M0JTR-0810_C134811.html "C134811"
[C17673]: https://lcsc.com/product-detail/Chip-Resistor-Surface-Mount_UNI-ROYAL-Uniroyal-Elec-0805W8F4701T5E_C17673.html "C17673"
[C92489]: https://lcsc.com/product-detail/Humidity-Sensors_Bosch-Sensortec-BME280_C92489.html "C92489"
[C83291]: https://lcsc.com/product-detail/Gas-Sensors_Bosch-Sensortec-BMP280_C83291.html "C83291"
[GY-BMP280]: https://www.az-delivery.de/en/collections/alle-produkte/products/azdelivery-bmp280-barometrischer-sensor-luftdruck-modul-fur-arduino-und-raspberry-pi "GY-BMP280"
[C155176]: https://lcsc.com/product-detail/Logic-Buffers-Drivers-Receivers-Transceivers_Texas-Instruments-SN74AHCT125DR_C155176.html "C155176"
[C35501]: https://lcsc.com/product-detail/Schottky-Barrier-Diodes-SBD_MDD-Microdiode-Electronics-SS24_C35501.html "C35501"
[C194323]: https://lcsc.com/product-detail/Light-Emitting-Diodes-LED_Worldsemi-WS2813C_C194323.html "C194323"
[C239529]: https://lcsc.com/product-detail/Lack-of-specifications_SOFNG-SK-12D02VG4_C239529.html "C239529"
[A107673-ND ]: https://www.digikey.de/product-detail/de/1825232-1/A107673-ND/4021554/?itemSeq=347804695 "A107673-ND "
[C46392]: https://lcsc.com/product-detail/USB-Connectors_Jing-Extension-of-the-Electronic-Co-C46392_C46392.html "C46392"
[102-3999-ND]: https://www.digikey.de/product-detail/de/UJ2-BH-1-TH/102-3999-ND/6187914/?itemSeq=347804690 "102-3999-ND"
[C409842]: https://lcsc.com/product-detail/Buzzers_Fengming-YS-MBZ12085C05R42_C409842.html "C409842"
[433-1028-ND]: https://www.digikey.de/product-detail/de/WT-1205/433-1028-ND/479674/?itemSeq=347804693 "433-1028-ND"
[1649-1098-ND]: https://www.digikey.de/product-detail/de/sensirion-ag/SCD30/1649-1098-ND/8445334 "1649-1098-ND"
[C358721]: https://lcsc.com/product-detail/Pin-Header-Female-Header_MINTRON-MTF185-107SY1_C358721.html "C358721"
[PPTC071LFBN-RC]: https://www.digikey.de/product-detail/de/sullins-connector-solutions/PPTC071LFBN-RC/S7005-ND/810146 "PPTC071LFBN-RC"
[d1]: https://www.az-delivery.de/products/d1-mini?variant=28983931346 "D1 Mini NodeMcu mit ESP8266-12F"

