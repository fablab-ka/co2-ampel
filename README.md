# CO2-Ampel V2
![CO2-Ampel][co2ampel]

## Einleitung
Der CO2-Gehalt der Luft kann als Indikator benutzt werden, um das Raumklima zu überwachen und eine potentielle Virenlast in geschlossenen Räumen zu erkennen. In freier Natur und in frisch gelüfteten Räumen beträgt er ungefähr 400ppm (0,04%). In geschlossenen Räumen mit anwesenden Personen steigt er konstant an. Ab ca. 1500ppm wird das Raumklima schlecht, und es können Unbehaglichkeit, Müdigkeit und Konzentrationsschwächen auftreten. 

Da Viren, die als Aerosol übertragen werden, zusammen mit dem CO2 in den Raum gebracht werden, kann über den CO2-Gehalt der Raumluft als Indikator für das Ansteckungsrisiko dienen.

Mithilfe von CO2-Sensoren lässt sich der CO2-Gehalt der Raumluft überwachen. Viele vorhandenen Geräte erlauben zwar eine akkurate Messung, zeigen aber die Auswirkungen auf die Raumluft nur mit kleinen LED-Anzeigen oder überhaupt nicht an. Sie eignen sich daher nur bedingt für den Einsatz in Gruppenräumen.

## Zielsetzung
Die *CO2-Ampel V2* wurde speziell für Schulen und Kitas entwickelt. Sie zeigt das Raumklima spielerisch und gut sichtbar im Stil einer Verkehrsampel an. *Grün* bedeutet *alles in Ordnung*. Springt die Ampel auf *gelb*, wird es Zeit, die Fenster zu öffnen. Bei *rot* ist der Grenzwert überschritten. Ein akustisches Signal weist zusätzlich darauf hin, dass nunmehr umgehend gelüftet werden muss. Sobald der CO2-Gehalt sich normalisiert hat, springt die Ampel wieder auf *grün*. Ein lachender bzw. ein trauriger Smiley illustrieren das Messergebnis zusätzlich.

Das Gerät lässt sich leicht installieren und wird über ein gewöhnliches USB-Kabel mit Strom versorgt. Der eingebaute Sensor erlaubt präzise CO2-Messungen. Auf Wunsch lässt sich der Verlauf der Messwerte per WLAN in einem Web-Interface anzeigen und protokollieren.

Bei der CO2-Ampel V2 handelt es sich um ein gemeinsames Projekt des [FabLab Karlsruhe e.V.](https://fablab-karlsruhe.de) und des [FabLab Bruchsal e.V.](http://fablab-bruchsal.de) im Rahmen der Aktion [Corona-Hilfe Karlsruhe](https://coronahilfe-karlsruhe.de).

## Inbetriebnahme und Fehlerbehebung
Die [Bedienungsanleitung](Documentation/Deutsch/Bedienungsanleitung.md) der CO2-Ampel V2 erläutert alle erforderlichen Schritte zur Inbetriebnahme und zur Nutzung einer fertigen CO2-Ampel. Sie deckt die folgenden Aspekte ab:

* Installation und Stromversorgung
* Optische und akustische Signale
* Konfiguration der WLAN-Verbindung (optional)
* Zugriff auf die Messdaten und Protokolle (optional)
* Fehlerbehebung
* Technische Daten
* Entsorgung

## Aufbauanleitung (Bausatz)
Die bebilderte [Aufbauanleitung](Documentation/Deutsch/Aufbauanleitung.md) erklärt Schritt für Schritt, wie die CO2-Ampel aus den Einzelkomponenten zusammengesetzt wird. Dies umfasst die folgenden Schritte:

* Einstecken des Microcontrollers und des CO2-Sensors
* Einsetzen der Platine
* Zusammenstecken und Verschrauben des Geräts

## Beschaffung bzw. Herstellung der Komponenten
Die [Herstellungsanleitung](Documentation/Deutsch/Herstellungsanleitung.md) gibt einen Überblick, wie die Einzelkomponenten der CO2-Ampel basierend auf den Informationen in diesem GitHub-Repository hergestellt bzw. beschafft werden können. Die Anleitung umfasst die folgenden Abschnitte:

* Beschaffung der Bauteile
* Bestellung der Platine bei einem PCB-Haus
* Bestückung der Platine mit den SMD-Komponenten
* Einlöten der weiteren elektronischen Komponenten
* Kompilieren und Hochladen der Software
* Einrichtung des Webinterfaces für den Datenzugriff
* 3D-Druck des Gehäuses

In der bebilderten [Loetanleitung](Documentation/Deutsch/Loetanleitung) sind alle wichtigen Schritte zum Löten der Komponenten beschrieben. Wir haben uns hier auf das Einlöten der Through Hole Komponenten beschränkt.

## Weiterentwicklung des Projekts
Der gesamte Quellcode der CO2-Ampel V2 wurde in diesem  GitHub-Repository veröffentlicht. Er besteht aus den folgenden Komponenten:

* Platine ([Gerber](https://de.wikipedia.org/wiki/Gerber-Format))
* Software (c++)
* Gehäuse (Wahlweise [Autodesk Fusion 360](https://www.autodesk.de/products/fusion-360/overview) oder [OpenSCAD](https://www.openscad.org))

## Zusätzliche Ressourcen
  * https://wiki.fablab-karlsruhe.de/doku.php?id=projekte:2020:co2-ampel

[co2ampel]: images/co2ampel.jpg "CO2-Ampel"
