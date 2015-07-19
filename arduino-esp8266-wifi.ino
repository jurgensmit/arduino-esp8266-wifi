/*
 * Arduino ESP8266 WiFi - Simple passthrough terminal for the ESP8266 WiFi module
 *
 * Connect a ESP8266 to the second serial port of the Arduino (Serial1). The sketch just
 * passes the characters it receives from the first serial port (Serial) to the second
 * serial port (Serial1) and vice versa.
 * 
 * Note: Make sure the terminal you are using is sending both a carriage return and
 * linefeed at the end of a line, i.e. "Both NL & CR" in the serial monitor of the
 * Arduino IDE. In Putty you have to add a CTRL+J after each line.
 *
 * (c) 2015 Jurgen Smit. All rights reserved.
 *
 * Circuit: 
 *
 * - ESP8266 Wifi Module connected to the second serial port of the Arduino.
 *
 */

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop() {
  // If something is available from the first serial port, passs it to the second serial port
  if(Serial.available()) {
    Serial1.write(Serial.read());
  }
    
  // If something is available from the second serial port, passs it to the first serial port
  if(Serial1.available()) {
    Serial.write(Serial1.read());
  }
}
