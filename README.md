# Gametrak Nr 2 

## Vom Golf-Playstation-controller zum Midicontroller
  
Der Gametrak ist ein Controller für die Playstation 2 aus den 2000ern, der für Golf- oder Boxspiele verkauft wurde.
Er wird nicht mehr hergestellt, ist aber zurzeit (stand 2019) erschwinglich bei Ebay & Co. zu haben.

Im Controller sind zwei ca. 2m lange Leinen auf Spulen mit einem Rückholmechanismus aufgewickelt (ähnlich einer Staubsaugerleine).
Durch Messwiederstände an Führungsröhrchen, die sich dem Neigungswinkel der Leine anpassen, und der Spule können Neigungswinkel und abgewickelte Länge der Leine gemessen werden.
Damit kann man dreidimensionale Bewegungen im Raum verfolgen, und zwar auf den Achsen vor-zurück, rechts-links und nach oben und unten.

Da dieser Controller so schön ganzkörperlich zu bedienen ist, eignet er sich auch als etwas ausgefallener Midi-controller.  

Es folg eine Bauanleitung, um einen Gametrak in einen Midicontroller umzubauen. 
Es gibt den Gametrak in zwei verschiedenen Ausführungen: 
Hier im Video ist eine kleine Performance mit einer älteren Gametrak (Version 1) zu sehen.

[![Watch the video](images/Gametrak%20Preview.png)](images/Gametrak.webm)


**Die folgende Bauanleitung** beschreibt den Umbau von einer neueren (Gametrak Version 2) Variante, bei dem man am Ende dann nur die Spulenbauteile mit den Schnüren aus dem Gametrak heraus nimmt und dann eine andere Box dazu bauen muss, da für zusätzliche Teile in der Gametrak 2 Version kein Platz ist.


Gametrak Version 1 | Gametrak Version 2
-------------------|-------------------
<img src="images/Gametrak1.jpeg" width=300> | <img src="images/Gametrak2.jpeg" width=300>


### Einkaufsliste:                                     

Item                                       | Preis (EUR)
-------------------------------------------|:----------:
Gametrak Version 2                         | 20 - 30
Experimentierboard                         | 7
Teensy 3.6                                 | 34 
Pins männlich und weiblich, je 2 Leisten   | 5
Kabel                                      | 3
Schrumpfschlauch                           | 0,10             


### Equipment:

* Lötkolben
* Lötzinn
* Platinenhalter/Schraubstock
* Abisolierzange
* Zange
* Schraubenzieher
* Feuerzeug
* Multimeter
* USB Kabel & Computer


### Bauanleitung:


Der Teensy wurde ohne Pins geliefert, deshalb werden als erstes die männlichen Pins so auf das Experimentierboard gesteckt, dass man den Teensy auf die Pins stecken kann und nun
die ersten 4 äußeren Pins an den Teensy löten kann. 
Dann den Teensy mit den Pins orgentlich einspannen und alle 


männliche Pins an den Teensy löten | _
-----------------------------------|---
Teensy ohne Pins, Experimetierboard mit männlichen Pins | ![images](images/IMG_0004.JPG)
Lötkolben und Teensy mit männlichen Pins angelötet | ![images](images/IMG_0006.JPG)
Alle Pins sind sauber am Teensy angelötet, auch unter der Lupe sind keine falschen Brücken. | ![images](images/IMG_0007.JPG)
**Gamtrak außeinander nehmen** | 
Gametrak Version 2, noch ganz | ![images](images/IMG_0009.JPG)
aufgeschraubt | ![images](images/IMG_0010.JPG)
Die 5 Kabel, die jeweils aus den beiden Potentiometern (Spule und Schnur vom Gamtrak) kommen, von der Gamtrak eigenen Platine abknipsen | ![images](images/IMG_0012.JPG)
dann hat man folgende lose Bauteile: Beide Spulen inklusive Schnur und Potentiometer mit Kabeln. | ![images](images/IMG_0015.JPG)
**Neue weibliche Verbinder anlöten** | 
Die 2x 5 abgeknipsten Kabel mit der Abisolierzange an den Enden ca 3mm abisolieren, | ![images](images/IMG_0016.JPG)
dann jedes Ende mit dem Lötkolben einzeln mit Lötzinn verzinnen und 10x1cm Schrumpfschlauchstücke abschneiden, jedes Schrumpfschlauchstück über ein Kabel ziehen | ![images](images/IMG_0021.JPG)
jedes Kabelende einzeln mit einem Ende eines weiblichen Pins verlöten | ![images](images/IMG_0019.JPG)
die Schrumpfschlauchstücke über die gelöteten Stellen ziehen, | ![images](images/IMG_0022.JPG) 
den Schrumpfschlauch mit dem Feuerzeug schrumpfen lassen | ![images](images/IMG_0023.JPG)
fertig! | ![images](images/IMG_0020.JPG)
Das Bauteil mit Spule und Potentiometer mit den fertig angelöteten weiblichen Pin | ![images](images/IMG_0024.JPG)
Das Bauteil Spule und Potentiometer des Gametraks in Nahaufnahme | ![images](images/IMG_0025.JPG)
* Da die Farbbelegung der Kabel irreführend/ungewöhnlich ist, mit dem Multimeter den Widerstand messen, 
um herauszufinden, wie die Kabel tatsächlich belegt sind, also welche Kabel mit + - belegt sind, und welche die Sensorenkabel sind.
(Sensorenkabel=Signalleitungen lesen den variablen Widerstand aus den beiden Potentiometern aus, d.h. wie weit die Schnur des Gametraks herausgezogen ist, und in welchem Winkel sie steht.)
Wenn wir zwischen zwei Kabeln den Widerstand messen und währenddessen die Potentioneter betätigen, sollte sich der Messwert ändern, wenn mindestens eins der Kabel ein Sensorkabel ist und der Messwert sollte gleich bleiben, wenn wir den Widerstand zwischen + und - messen.

* Die Widerstandsmessungen haben folgendes ergeben: Die 5 Kabel, sind in diesem Gamtrak folgendermaßen belegt: Die beiden äußeren Kabel (hier braun und grün) sind für plus und minus, die 3 inneren Kabel (hier rot, orange,gelb) sind die Signalleitungen der drei Potis. 

* Nun den Teensy mit den angelöteten männlichen Pins in die weiblichen Pins - und dadurch ins Experimentierboard - stecken, daneben noch extra männliche Pins stecken, um die Kabel vom Teensy zum Board zu verbinden. (Dafür sich vorher den Pinbelegungsplan anschauen, wie man am besten die Siglalleitungen und die Plus und Minus Kabel legen möchte.)

`TODO:Tabelle gleichgroße Bilder wie zuvor` 

Teensy Pinbelegungen und Experimentierboard | _
--------------------------------------------|---
Teensy Pinbelegung, beide Seiten | ![images](images/Teensy.jpeg)
Teensy auf dem Experimentierboard | ![images](images/IMG_0026.JPG) 
Verwendete Ansicht der Pinbelegungen des Teensy | ![images](images/IMG_0030.JPG)


In diesem Fall wird der Analog GND (GND= Ground = Minus) mit 2 männlichen Steckern auf dem Board verdoppelt, sowie auch das Plus (hier 3.3V) mit 2 Steckern auf dem Board verdoppelt wird.
Um die Sensorenkabel zu verbinden werden hier die Belegungen der Analogpins 16=A2, 17=A3 und 18=A4 für die erste Spule mit Potentiometer gewählt, und die Belegungen 20=A6, 21=A7 und 22=A8. 
Natürlich können die Belegungen auch anders gewählt werden, in diesem Fall ist die Belegung aber schön kompakt und man muss relativ wenige Kabel löten.

* die Kabel vom Potentiometer im Experimentierboard mit dem Teensy verbinden: Jeweils die Plus und Minus Kabel mit dem GND und 3.3 V vom Teensy durch Stecken verbinden, und die jeweils 3 Sensorenkabel mit jeweils 3 Analoge-Pins vom Teensy durch Stecken verbinden. (Z.B. A0-A6, Nr 14-20 am Teensy).

Verbindung zwischen Potis und Teensy | _
-------------------------------------|---
Die erste Hälfte des Gametraks ist verbunden. Links die drei Sensor-Leitungen (gelb, orange, rot) und rechts die beiden Pole (braun = -, grün = +).| ![images](images/IMG_0027.JPG)
Die zweite Hälfte ist verbunden. Diese gesteckte Version kann später natürlich gelötet werden oder durch stabilere Stecksysteme ersetzt werden. | ![images](images/IMG_0029.JPG)
Gesamtansicht von Teensy und den beiden Gametrak-Hälften. | ![images](images/IMG_0031.JPG).

Jetzt muss der Teensy mit der richtigen Firmware bespielt werden. Dafür
1. Die Arduino IDE herunterladen auf [arduino.cc](https://www.arduino.cc/en/Main/Software)
1. Das Teensy Plugin für die Arduino herunterladen auf [teensy.com](https://www.pjrc.com/teensy/td_download.html)
1. In der Arduino IDE die Firmware öffnen unter TeensySourcecode/GameTrakAsMIDI/GameTrakAsMIDI.ino`.
1. Die Pinbelegung eintragen
1. Teensy per USB mit dem Computer verbinden
1. Unter `Tools > Port` den Teensy auswählen
1. Unter `Tools > USB Type > Serial + MIDI` einstellen
1. Auf "Upload" klicken (strg+u)

vor der ersten Benutzung muss Kalibriert werden:
1. Teensy per USB mit dem Computer verbinden
1. Arduino IDE starten
1. `Tools > Serial Monitor` auswählen
1. sich nicht von den vielen Zahlen verwirren lassen und `h` in das obere Textfeld eingeben (bestätigen mit Enter)
1. `c`+`Enter` eingeben um die Kalibrierung zu starten
1. Beide Führungsröhrichen nach rechts/links/vorne/hinten bewegen jeweils bis zum Anschlag.
1. Beide Leinen bis zur maximalen Länge, bei der sie benutzt werden sollen, herausziehen.
1. `c` + `Enter` um die Kalibrierung abzuschließen. 

Die Kalibrierung wird gespeichert und muss bei der nächsten Benutzung nur dann neu ausgeführt werden, wenn der Gametrak mit einer neuen maximalen Leinenlänge benutzt werden soll.  

Jetzt nur noch mit dem Computer verbinden und schauen ob es schon funktioniert,
das heißt:
* mit dem USB Kabel den Teensy mit dem Computer verbinden und entweder einen beliebigen Open-Source Synthesizer starten (z.B. [Helm](https://tytel.org/helm/)),
* oder PureData auf dem Rechner starten und den neuen Gametrak2.0- Midicontroller mit den Patches von PureData testen `TODO: willst du die PD patches auch noch ins repository packen?`
* TADAAA es funktioniert, jetzt nur noch eine Box für den Gametrak bauen und viel Spaß mit dem neuen Midicontroller!
* (Zum Beispiel mit LibreCAD eine speziefische Box für die Teile des Gametraks zeichnen und dann mit dem Lasercutter die Teile aus Holz oder Plexiglas ausschneiden und zusammenstecken/kleben.)

