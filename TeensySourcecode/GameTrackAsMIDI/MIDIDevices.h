#include <Bounce.h>


template<int channel>
class ContinuousKeyboard {
  public:
    int lastNote, lastVelocity;
    ValueSource* pitchValueSource, *velocityValueSource;

  public:
    ContinuousKeyboard(ValueSource& pitchValueSource, ValueSource& velocityValueSource) :
      lastNote(-1), pitchValueSource(&pitchValueSource), velocityValueSource(&velocityValueSource) {}

    void update() {
      int note = round(pitchValueSource->read());
      int targetVelocity = round(velocityValueSource->read());

      if (note != lastNote) {
        //        Serial.println(note);
        usbMIDI.sendNoteOn(note, targetVelocity, channel);
        usbMIDI.sendNoteOff(lastNote, 0, channel);
      }

      if (lastVelocity == 0 && targetVelocity != 0) {
        usbMIDI.sendNoteOn(note, targetVelocity, channel);
      }

      lastNote = note;
      lastVelocity = targetVelocity;
    }
};

template<int channel>
class PedalKeyboard {
  public:
    Bounce pedal;
    ValueSource* pitchValueSource, *velocityValueSource;
    int lastNote;

  public:
    PedalKeyboard(ValueSource& pitchValueSource, ValueSource& velocityValueSource, int pedalPin) :
      pedal(pedalPin, 5), pitchValueSource(&pitchValueSource), velocityValueSource(&velocityValueSource), lastNote(-1) {}

    void update() {
      pedal.update();
      if (pedal.fallingEdge()) {
        Serial.print("Note On");
        int targetVelocity = round(velocityValueSource->read());
        lastNote = round(pitchValueSource->read());
        usbMIDI.sendNoteOn(lastNote, targetVelocity, channel);
        Serial.println(lastNote);
      }

      if(pedal.risingEdge()) {
        Serial.println("Note OFFF");
        int targetVelocity = round(velocityValueSource->read());
        usbMIDI.sendNoteOff(lastNote, targetVelocity, channel);
      }
    }
};

template< int control, int channel >
class Control {
  private:
    ValueSource* valueSource;
    int lastValue;
  public:
    Control(ValueSource& valueSource) : valueSource(&valueSource), lastValue(-1) {}

    void update() {
      
      int value = round(valueSource->read());
//      Serial.print("UPDATE CONTROL ");
//      Serial.print(lastValue);
//      Serial.print(" ");
//      Serial.println(value);
      if (lastValue != value) {
        Serial.print(control); Serial.print(" "); Serial.println(value);
        usbMIDI.sendControlChange(control, value, channel);
        lastValue = value;
      }

    }
};

template<int channel >
class PitchBend {
  private:
    ValueSource* valueSource;
    int lastValue;
  public:
    PitchBend(ValueSource& valueSource) : valueSource(&valueSource), lastValue(-1) {}

    void update() {
      int value = round(valueSource->read());
      if (lastValue != value) {
        usbMIDI.sendPitchBend(value, channel);
        lastValue = value;
      }

    }
};

template<int channel >
class AfterTouch {
  private:
    ValueSource* valueSource;
    int lastValue;
  public:
    AfterTouch(ValueSource& valueSource) : valueSource(&valueSource), lastValue(-1) {}

    void update() {
      int value = round(valueSource->read());
      if (lastValue != value) {
        usbMIDI.sendAfterTouch(value, channel);
        lastValue = value;
      }

    }
};
