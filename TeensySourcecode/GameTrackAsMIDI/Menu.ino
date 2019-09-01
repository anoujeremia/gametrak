void updateMenu() {
  int v = Serial.read();

  if (v != -1) {
    if (v == 'h') {
      Serial.println(
        "Commands are:\n"
        "h: display this help and go to idle\n"
        "i: go to idle state\n"
        "r: send TSV raw data on serial\n"
        "g: send ASCII gui on serial\n"
        "c: toggle calibration mode\n"
        "l: toggle learning mode\n"
        "o: report the calibration configuration\n"
      );
      state = 'i';
    }
    if (v == 'i') state = 'i';
    if (v == 'r') state = 'r';
    if (v == 'g') state = 'g';
    if (v == 'c') {
      if (state == 'c') {
        Serial.println("Calibration Done");

        x_l.stopCalibration();
        y_l.stopCalibration();
        z_l.stopCalibration();

        x_r.stopCalibration();
        y_r.stopCalibration();
        z_r.stopCalibration();

        state = 'i';
      } else {
        Serial.println("Starting Calibration");

        x_l.startCalibration();
        y_l.startCalibration();
        z_l.startCalibration();

        x_r.startCalibration();
        y_r.startCalibration();
        z_r.startCalibration();
        state = 'c';
      }
    }

    if (v == 'l') AnalogValueSource::lowSensitivityModeEnabled = !AnalogValueSource::lowSensitivityModeEnabled;

    if (v == 'o') {
      x_l.reportConfiguration();
      y_l.reportConfiguration();
      z_l.reportConfiguration();

      x_r.reportConfiguration();
      y_r.reportConfiguration();
      z_r.reportConfiguration();
      state = 'i';
    }
  }
}
