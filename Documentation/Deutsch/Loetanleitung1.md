# CO2-Ampel Lötanleitung - PCB v4.1

## Teil I: Stiftleisten, Sockel und Buzzer

### Benötigte Bauteile
1. Buchse 8pin (2x): Diese findet ihr beim D1 Mikrocontroller
2. Buchse 7pin (1x)
3. Stiftleiste 6pin (1x): Diese findet ihr bei der bmp280 Platine
4. Buzzer (1x)
5. SMD bestückte Platine

### Benötigtes Werkzeug
* 3D-gedruckte Löthilfe für die Platine
* Lötstation (temperaturgeregelt)
* Lötrauchabsaugung
* Lötzinn (bleifrei 0.5-0.75mm Durchmesser)

![Bauteile und Werkzeug Teil I](../images/loeten/teil1_material.jpg)

### Arbeitsschritte
1. Setzt die beiden 8pin Buchsen in die Löthilfe ein (a+b)
2. Setzt die 7pin Buchse in die Löthilfe ein (c)
3. Setzt die 6pin Stiftleiste in die Löthilfe ein (d). **WICHTIG:** Die kurzen Beinchen schauen nach oben raus.
4. Buzzer (e) auf die Platine stecken (auf der Seite **ohne** LEDs). Falls der Buzzer beim Drehen der Platine abfällt, dann die Beinchen leicht zusammen drücken und dann nochmals einstecken. **WICHTIG:** Achtet hier auf die richtige Polarität. (+ auf dem Buzzer zu + auf der Platine).

![Teil1 Bauteile eingesetzt](../images/loeten/teil1_eingesetzt.jpg)

5. Platine vorsichtig auf die Löthilfe stecken. Evtl. etwas rütteln, so dass die Stiftleisten in die Löcher der Platine rutschen. Wenn alles passt, dann die Platine fest in die Löthilfe drücken, so dass die Ränder bündig sind. 

![Teil1 alles vorbereitet zum Löten](../images/loeten/teil1_vorbereitet.jpg)

6. Jetzt könnt ihr alle Pins anlöten. Achtet darauf, dass ihr den Lötkolben nur max 2-3 Sekunden an die Lötstelle haltet. 
7. **Qualitätskontrolle:** Das ist der wichtigste Schritt und erspart euch später viel Zeit bei der Fehlersuche. Prüft nochmals alle Lötstellen und schaut nochmal, ob ihr wirklich **kein Bauteil oder Pin vergessen** habt. Die **Lötstellen** sollten **glatt und leicht konisch** sein. Wenn sie rau sind, habt ihr vermutlich eine kalte Lötstelle. Dann solltet ihr das Lötzinn nach einer kurzen Abkühlphase nochmals erhitzen. Prüft zur Sicherheit noch einmal, dass **keine Lötstellen miteinander verbunden** sind. Das kann später einen Kurzschluss verursachen und im schlimmsten Fall die Bauteile zerstören.

![Teil1 Qualitätskontrolle](../images/loeten/teil1_qm.jpg)

