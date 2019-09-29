/////////////////////////////////
/// ENTER THE PINS ON WHICH YOU
/// CONNECTED THE SENSOR WIRES HERE
/// X = RIGHT-LEFT
/// Y = FRONT-BACK
/// Z = IN-OUT
////////////////////////////////
// Left Line
const int pin_x_l = 22;
const int pin_y_l = 20;
const int pin_z_l = 21;

// Right Line
const int pin_x_r = 18;
const int pin_y_r = 16;
const int pin_z_r = 17;

const int pin_foot = 0; // optional
////////////////////////////////

#include <EEPROM.h>
#include "ValueSources.h"
#include "MIDIDevices.h"


AnalogValueSource x_l(pin_x_l, 0, 127);
AnalogValueSource y_l(pin_y_l, 0, 127);
AnalogValueSource z_l(pin_z_l, 0, 127);
//
AnalogValueSource x_r(pin_x_r, 0, 127);
AnalogValueSource y_r(pin_y_r, 0, 127);
AnalogValueSource z_r(pin_z_r, 0, 127);

DigitalValueSource foot(pin_foot, 50, 127);

ConstantValueSource velocityConstant(127);

Control<1, 1> ctrl1(x_l);
Control<2, 1> ctrl2(y_l);
Control<3, 1> ctrl3(z_l);
Control<4, 1> ctrl4(x_r);
Control<5, 1> ctrl5(y_r);
Control<6, 1> ctrl6(z_r);

void setup() {
  Serial.begin(9600);
  analogReadResolution(13);
  pinMode(pin_foot, INPUT_PULLUP);
}

/*
   States are:
   i: idle
   r: send raw values on serial
   g: send ASCII gui on serial
   c: calibrate
   l: learning
*/
int state = 'r';
void loop() {

  updateMenu();

  ctrl1.update();
  ctrl2.update();
  ctrl3.update();
  ctrl4.update();
  ctrl5.update();
  ctrl6.update();

  switch (state) {
    case 'r':
      printRawTSV();
      break;
    case 'g':
      printRawASCIIGUI();
      delay(50);
      break;
    case 'c':
      x_l.read();
      y_l.read();
      z_l.read();

      x_r.read();
      y_r.read();
      z_r.read();
      break;
    default:
      break;
  }

  while (usbMIDI.read()) {
    // ignore incoming midi messages
  }

  delay(5);
}
