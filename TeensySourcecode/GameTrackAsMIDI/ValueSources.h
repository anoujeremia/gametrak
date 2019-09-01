float mapf(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


class ValueSource {
  public:
    virtual float read() = 0;
};

class ConstantValueSource: public ValueSource {
  private:
    float value;
  public:
    ConstantValueSource(float value): value(value) { }
    float read() {
      return value;
    }
};

class AnalogValueSource: public ValueSource {
  public:
    static bool lowSensitivityModeEnabled;
    static int numInstances;
  private:
    int pin;
    float minOut, maxOut;
    int minRaw, maxRaw;
    bool isCalibrating;
    int eepromOffset;

  public:
    AnalogValueSource(int pin, float minOut, float  maxOut, int minRaw, int maxRaw) :
      pin(pin), minOut(minOut), maxOut(maxOut), minRaw(minRaw), maxRaw(maxRaw), isCalibrating(false), eepromOffset(numInstances) {
      numInstances++;
      storeCalibration();
    }

    AnalogValueSource(int pin, float minOut, float  maxOut) : pin(pin), minOut(minOut), maxOut(maxOut), isCalibrating(false), eepromOffset(numInstances) {
      numInstances++;
      restoreCalibration();
    }

    float read() {
      if (isCalibrating) {
        int a = analogRead(pin);
        minRaw = min(a, minRaw);
        maxRaw = max(a, maxRaw);
      }

      if (lowSensitivityModeEnabled) {
        return map(round(map(constrain(analogRead(pin), minRaw, maxRaw), minRaw, maxRaw, 0, 2)), 2, 4, minOut, maxOut);
      }

      return mapf(constrain(analogRead(pin), minRaw, maxRaw), minRaw, maxRaw, minOut, maxOut);
    }

    void startCalibration() {
      minRaw = 1e6;
      maxRaw = -1;
      isCalibrating = true;
    }

    void stopCalibration() {
      isCalibrating = false;
      reportConfiguration();
      storeCalibration();
    }

    void storeCalibration() {
      EEPROM.put(eepromOffset * sizeof(int) * 2, minRaw);
      EEPROM.put(eepromOffset * sizeof(int) * 2 + sizeof(int), maxRaw);
    }

    void restoreCalibration() {
      EEPROM.get(eepromOffset * sizeof(int) * 2, minRaw);
      EEPROM.get(eepromOffset * sizeof(int) * 2 + sizeof(int), maxRaw);
    }

    void reportConfiguration() {
      Serial.print("(");
      Serial.print(pin); Serial.print(", ");
      Serial.print(minOut); Serial.print(", ");
      Serial.print(maxOut); Serial.print(", ");
      Serial.print(minRaw); Serial.print(", ");
      Serial.print(maxRaw); Serial.println(")");
    }
};

bool AnalogValueSource::lowSensitivityModeEnabled = false;
int AnalogValueSource::numInstances = 0;


class DigitalValueSource: public ValueSource {
  private:
    int pin;
    float onValue, offValue;
  public:
    DigitalValueSource(int pin) : pin(pin), onValue(1.), offValue(0.) {}
    DigitalValueSource(int pin, float onValue, float offValue) : pin(pin), onValue(onValue), offValue(offValue) {}

    float read() {
      if (digitalRead(pin) == HIGH)
        return onValue;
      else
        return offValue;
    }
};
