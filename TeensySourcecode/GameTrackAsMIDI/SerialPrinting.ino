void printRawTSV() {
  Serial.print(analogRead(pin_x_l)); Serial.print("\t");
  Serial.print(analogRead(pin_y_l)); Serial.print("\t");
  Serial.print(analogRead(pin_z_l)); Serial.print("\t");
  Serial.print(analogRead(pin_x_r)); Serial.print("\t");
  Serial.print(analogRead(pin_y_r)); Serial.print("\t");
  Serial.print(analogRead(pin_z_r)); Serial.println();
}

void printRawBar(int pin, int scale) {
  int v = analogRead(pin) / scale;
  Serial.print(pin);
  Serial.print(":\t");
  for (; v > 0; v--) Serial.print("#");
  Serial.println();
}

void printRawASCIIGUI() {
  int scale = 100;
  printRawBar(pin_x_l, scale);
  printRawBar(pin_y_l, scale);
  printRawBar(pin_z_l, scale);
  printRawBar(pin_x_r, scale);
  printRawBar(pin_y_r, scale);
  printRawBar(pin_z_r, scale);
  Serial.print(pin_foot); Serial.print("\t");
  if (digitalRead(pin_foot) == LOW)
    Serial.println("#");
  else
    Serial.println("");
  Serial.println();
}
