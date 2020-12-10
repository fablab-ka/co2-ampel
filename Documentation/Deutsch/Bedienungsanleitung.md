# Bedienungsanleitung CO2-Ampel V2

Diese Bedienungsanleitung richtet sich an diejenigen Benutzer, die eine einsatzbereite CO2 Ampel V2 in Betrieb nehmen möchten oder die Fragen zum Betrieb des Geräts haben.

## Kurzanleitung

Die CO2-Ampel lässt sich in wenigen Schritten in Betrieb nehmen. Die einzelnen Schritte werden im den folgenden Kapiteln im Detail erklärt.

1. Gerät an der Wand befestigen
   * Gut sichtbare Stelle
   * Keine direkte Sonneneinstrahlung
   * Nicht direkt am Fenster
2. Stromversorgung anschließen
   * USB-Steckernetzgerät, 5V, mindestens 1A
   * USB-Kabel mit USB Stecker Typ B
3. Zur WLAN-Anbindung (optional):
   * Mit dem WLAN-Zugangspunkt verbinden, den die Ampel in den ersten zwei Minuten nach dem Einschalten aufmacht.
   * Adresse 192.168.4.1 im Browser öffnen.
   * Mit Passwort anmelden, das zusammen mit dem Gerät übergeben  wurde.
   * Internetzugang konfigurieren und speichern.
4. Den Farbcodes folgen:
   * *Grün*: Alles OK! Falls gerade gelüftet wurde, können die Fenster wieder geschlossen werden.
   * *Gelb*: Grenzwert überschritten. Schnellstmöglich lüften!
   * *Rot*: Grenzwert deutlich überschritten. Umgehend lüften!
5. Das Gerät kann bei Nichtbenutzung von Stromnetz getrennt werden, zum Beispiel über Nacht oder über das Wochenende.

## Installation und Stromversorgung
Zur Inbetriebnahme muss die Ampel an der Wand befestigt werden und über ein USB-Kabel mit Strom versorgt werden.

### Standort
Die Ampel sollte in ca. 1,5 m bis 2,2 m Höhe so an der Wand befestigt werden, dass sie für alle im Raum befindlichen Personen gut einsehbar ist. Bitte beachten Sie, dass sich eine Steckdose für die Stromversorgung in der Nähe befindet. Um das Messergebnis nicht zu verfälschen, sollte das Gerät keiner direkten Sonneneinstrahlung ausgesetzt sein. Außerdem sollte es sich nicht in der Nähe eines geöffneten Fensters befinden.
 Sofern eine WLAN-Anbindung gewünscht ist, muss darauf geachten werden, dass ein ausreichend starkes WLAN-Signal verfügbar ist.
Die Ampel ist ausschließlich für die Verwendung in trockenen Räumen konzipiert.

### Stromversorgung
Für die Stromversorgung der Ampel benögigen Sie ein USB-Steckernetzgerät und eine Kabel mit ausreichender Länge:

* USB Kabel Stecker Typ A auf Stecker Typ B
* USB Steckernetzgerät mit Buchse Typ A, 5V, mindestens 1A

### Montage
Zum Aufhängen der Ampel können Sie wahlweise und je nach Beschaffenheit der Wand einen Nagel (ca. 4 cm Länge), eine Schraube mit Dübel (S4 oder S5) verwenden. Falls nicht gebohrt oder genagelt werden kann, kann die optionale Wandhalterung mit Klebepads an der Wand fixiert werden und die Amplel darin eingeklickt werden. Das USB-Kabel kann bei Bedarf zusätzlich mit Kabelklemmen an der Wand befestigt werden.

### Einschalten
Die Ampel schalten sich automatisch ein, sobald sie mit der Stromversorgung verbunden wird. Zunächst sollten beide Ampelfelder kurz weiß aufleuchten, danach wird entsprechend dem CO2-Gehalt der Luft eine Farbe angezeigt. Ein Blinken der Ampel deutet auf einen Fehler hin. Siehe Abschnitt Fehlerbehebung unten.

### Konfiguration der WLAN-Verbindung (optional)

> 	Hinweis: Bitte beachten Sie die Hinweise zum Datenschutz unten, bevor Sie mit der Konfiguration der WLAN-Verbindung fortfahren!

Direkt nach dem Einschalten der Ampel versucht diese zunächst, sich mit einem bereits zuvor konfigurierten WLAN-Zugangspunkt zu verbinden. Gelingt dies nicht innerhalb dreißig Sekunden, oder war zuvor kein Zugangspunkt konfiguriert worden, so macht die Ampel einen für 2 Minuten eigenen Zugangspunkt auf, über den der WLAN-Zugriff im Anschluss konfiguriert werden kann. Gehen Sie folgendermaßen vor, um die WLAN-Verbindung zu konfigurieren:

1. Verbinden Sie die Ampel mit der Stromversorgung.
2. Öffnen Sie an Ihrem PC oder auf Ihrem Smartphone die WLAN-Konfiguration und warten Sie ab, bis ein Zugangspunkt *CO2Ampel-XXXXXXXX* in der Liste der verfügbaren Zugangspunkte erscheint.
3. Verbinden Sie Ihren PC bzw. Ihr Smartphone mit diesem Zugangspunkt um sich direkt mit der Ampel zu verbinden.
4. Geben Sie die IP-Adresse *192.168.4.1* in die Adresszeile Ihres Browsers ein und laden Sie die Seite.
5. Melden Sie sich mit dem Passwort an, das Sie zusammen mit der CO2-Ampel erhalten haben.
6. Tragen Sie nun die Details des Zugangspunkts ein, mit dem die Ampel verbunden werden soll. Es handelt sich um die selben Daten, die Sie auch auf Ihrem PC oder Smartphone eintragen würden, um sich mit dem Internet zu verbinden.
7. Speichern Sie die Eintragungen und warten Sie die Bestätigung ab.

Bei einer bestehenden WLAN-Verbindung wird empfohlen, die Ampel dauerhaft am gleichen Ort zu betreiben, da die protokollierten Messwerte ansonsten wenig aussagekräftig sein werden.

## Optische und akustische Signale

Die CO2-Ampel misst laufend den CO2-Gehalt der Raumluft und zeigt durch optische und akustisches Signale an, falls der Messwert [den vom Bundesumweltamt empfohlenen Grenzwert](https://www.umweltbundesamt.de/sites/default/files/medien/2546/dokumente/irk_stellungnahme_lueften_sars-cov-2_0.pdf) überschreitet. Da der CO2-Gehalt der Raumluft ein Indikator für eine mögliche Virenbelastung der Raumluft darstellt, deutet er auf ein erhöhtes Ansteckungsrisiko mit durch über Aerosole übertragene Infektionskrankheiten hin. Das tatsächliche Ansteckungsrisiko hängt jedoch von einer Vielzahl von Faktoren ab. Die Verwendung der CO2-Ampel kann helfen, das Ansteckungsrisiko zu reduzieren, sie garantiert jedoch keinerlei Schutz vor einer Ansteckung!

### Optische Signale
Die folgende Tabelle gibt die Bedeutung der Farben und die empfohlenen Handlungen an. 

|Farbcode|Bedeutung|Empfohlene Aktion|
|---|---|---|
|GRÜN<p>(unteres&nbsp;Feld)|CO2-Grenzwert unterschritten.|Fenster können geschlossen werden, sofern gerade gelüftet wurde.|
|GELB<p>(oberes&nbsp;Feld)|CO2-Grenzwert **überschritten**.|Es sollte **schnellstmöglich** gelüftet werden!|
|ROT<p>(oberes&nbsp;Feld)|CO2-Grenzwert **deutich überschritten**.|Es muss **umgehend** gelüftet werden!|

Zum effizienten Lüften des Raumes würd eine **Sturmlüftung** empfohlen. Das heißt, es sollten möglichst alle Fenster komplett geöffnet werden. Die Ampel ist so konzipiert, dass sie beim Lüften erst dann auf grün umschaltet, wenn der CO2-Grenzwert **deutlich unterschritten** wird. Die Fenster können also gleich im Anschluss geschlossen werden.

### Akustische Signale
Bei ansteigendem CO2-Wert ertönt bei jedem Wechsel der Farben ein **akustisches Signal**. Beim fallendem CO2-Wert ertönt beim Wechsel auf grün ebenfalls ein Signal, das angibt, dass die Fenster nun geschlossen werden können.

## Datenschutz

Nach erfolgreicher WLAN-Konfiguration wird die Ampel in regelmäßigen Abständen Messdaten an einen Server im Internet übertragen. Diese umfassen den CO2-Gehalt der Raumluft, die Temperatur und die Luftfeuchtigkeit. Die Daten erlauben Rückschlüsse auf die Anzahl der im Raum befindlichen Personen, auf die Häufigkeit des Lüftens und insbesondere auf die Einhaltung der Empfehlungen zum regelmäßigen Lüften.

Der Server zur Protokollierung der Messwerte ist in der Software des Geräts hinterlegt. Wenn Sie die Ampel vom FabLab Karlsruhe e.V. erhalten haben, bedeutet dies:

* Die Daten werden auf den Server co2-ampel.fablab-karlsruhe.de übertragen. Es handelt sich dabei um einen virtuellen Server, den wir in Deutschland bei der Fa. Hetzner hosten. Betreiber ist der Verein FabLab Karlsruhe e.V.
* Um Zugriff auf die Daten bzw. das Dashboard zu erhalten, schreiben Sie uns bitte eine E-Mail an kontakt@coronahilfe-karlsruhe.de 
* Auf die Werte ihrer Ampeln haben nur von Ihnen genannte Personen Zugriff. Zusätzlich haben noch unsere Systemadministratoren Zugriff.
* Die Daten werden zur Darstellung in dem von uns bereitgestellten Dashboard verarbeitet. Weiterhin werden sie in anonymisierter Form zur bedarfsgerechten Gestaltung, der Weiterentwicklung und der Optimierung des Dashboards durch unsere Systemadministratoren genutzt. Eine Weitergabe an Dritte erfolgt nicht.


## Fehlerbehebung
Falls die Ampel nicht leuchtet oder ein blinkender Farbcode angezeigt wird, liegt womöglich ein Fehler vor. Die folgende Tabelle beschreibt einige typische Fehlerursachen.

|Symptom|Ursache|Behebung|
|---|---|---|
|Ampel leuchtet nicht|Kein Strom| Sitzen die Stecker fest? Hat die Steckdose Strom? Funktioniert die Ampel mit einem anderen Kabel bzw. einem anderen Steckernetzgerät?|
|Ampel leuchtet nicht|LEDs sind ausgeschaltet| Der kleine Schiebeschalter seitlich unten and er Ampel muss nach oben zeigen, damit die Ampel leuchtet. Bitte überprüfen Sie die Position des Schalters!|
|Ampel blinkt *gelb*|CO2-Wert zu niedrig|Der gemessene CO2-Wert ist unrealistisch niedrig. Gerät muss überprüft werden.|
|Ampel blinkt abwechselnd *gelb* und *rot*|CO2-Sensor nicht erkannt|Ein Problem mit dem CO2-Sensor ist aufgetreten. Gerät muss überprüft werden.|
|Ampel blinkt *blau*|Gemessener Luftdruck zu gering|Der gemessene Luftdruck istt unrealistisch gering. Gerät für 10 Sekunden von Stromversorgung trennen. Bei wiederholtem Auftreten Gerät überprüfen.|
|Ampel blinkt abwechselnd *blau* und *rot*|Luftdrucksensor nicht erkannt|Ein Problem mit dem Luftdrucksensor (BMP280) ist aufgetreten. Gerät muss überprüft werden.|

## Technische Daten
In diesem Kapitel werden die wichtigsten technischen Daten der CO2-Ampel V2 zusammengefasst.

### Stromversorgung

|Merkmal|Wert|
|---|---|
|Betriebsspannung|5 V Gleichspannung|
|Stromaufnahme|ca. 500 mA|
|Leistungsaufnahme|ca. 2,5 W|

### CO2-Grenzwerte
Steigender CO2-Wert (Fenster geschlossen):

|CO2-Gehalt|Farbe|
|---|---|
|<=&nbsp;1000&nbsp;ppm|GRÜN|
|>&nbsp;1000&nbsp;ppm<p><=&nbsp;2000&nbsp;ppm|GELB|
|>&nbsp;2000&nbsp;ppm|ROT|

Fallender CO2-Wert (während des Lüftens):

|CO2-Gehalt|Farbe|
|---|---|
|<=&nbsp;800&nbsp;ppm|GRÜN|
|>&nbsp;800&nbsp;ppm<p><=&nbsp;1500&nbsp;ppm|GELB|
|>&nbsp;1500&nbsp;ppm|ROT|

## Entsorgung

Wie alle elektronischen Geräte darf die CO2-Ampel nicht im Hausmüll entsorgt werden. Wir empfehlen, defekte oder nicht mehr benötigte Geräte an den Hersteller zurückzugeben.

Zur Entsorgung kann das Gehäuse der Ampel zerlegt werden, indem die Schraube an der Rückseite entfernt und der Deckel abgezogen wird. Das Gehäuse und die Schreiben können dann im Hausmüll entsorgt werden. Die Platine, das Netzgerät und das Kabel müssen bei einer Sammelstelle für Elektroschrott abgegeben werden.
