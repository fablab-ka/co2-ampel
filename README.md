# co2-ampel
![CO2-Ampel][co2ampel]

## Motivation
Um das Raumklima und potentielle Virenlasten in geschlossenen Räumen zu überwachen, kann der CO2-Gehalt der Raumluft benutzt werden. In freier Natur und frisch gelüfteten Räumen beträgt er ~400ppm (0,04%), in geschlossenen Räumen mit anwesenden Personen steigt er konstant an. Ab ~1500ppm ist das Raumklima schlecht, Unbehaglichkeit, Müdigkeit und Konzentrationsschwächen können auftreten. 
Da potentielle Viren, die als Aerosol übertragen werden, zusammen mit dem CO2 in den Raum gebracht werden, kann der Gehalt vielleicht auch als Indikator für das Ansteckungsrisiko dienen.

Um den CO2-Gehalt zu überwachen, können CO2-Sensoren verwendet werden. Viele vorhandenen Geräten können zwar den CO2-Gehalt akkurat messen, aber zeigen die Auswirkungen auf die Raumluft nur mit kleinen LED-Anzeigen oder garnicht an. Deshalb soll diese CO2-Ampel folgende Features aufweisen:
  * Genaue Messung des CO2-Gehalts
  * großflächige visuelle Anzeige des Raumklimas
  * optionale akkustische Warnung bei schlechtem Klima
  * plug-and-play standalone-Lösung
  * einfache Installation und Benutzung

## Benötigtes Werkzeug
  * 3D Drucker
  * Lötkolben
  * optionnal: Reflow Ofen (falls das PCB selbst bestückt werden soll)
  * optional: Lasercutter (falls der Diffusor aus Acryl gelasert statt gedruckt werden soll)

## Anleitung zum Nachbau
Da das Projekt noch im Prototypen-Statium ist, gibt es leider noch wenig Dokumentation. Folgende Schritte müssen zum Nachbau unternommen werden:
  * Bestellen der Platine mit den Gerber-Dateien in PCB/Gerber bei einem PCB-Haus. Zu empfehlen ist auch der Kauf eines Stencils.
  * Bestellen der Bauteile, Warenkörbe sind in [BOM](PCB/BOM/) zu finden.
  * Bestücken der PCBs
  * Upload des Sourcecodes
  * 3D-Druck des Gehäuses

## Anleitung zur Weiterentwicklung
Das Projekt wurde in Autodesk Fusion 360 entworfen, alle .f3d-Dateien können dort importiert werden.

## Zusätzliche Ressourcen
  * https://wiki.fablab-karlsruhe.de/doku.php?id=projekte:2020:co2-ampel

[co2ampel]: images/co2ampel.jpg "CO2-Ampel"
