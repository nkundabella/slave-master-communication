#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11); // RX, TX
const int ledPin = 8;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);      // FIX #1: Start Serial Monitor
  bluetooth.begin(9600);   // FIX #2: Default HC-05 speed for normal mode
  Serial.println("Bluetooth Ready...");
}
void loop() {
  if (bluetooth.available()) {
    char command = bluetooth.read();
    Serial.print("Received: ");
    Serial.println(command);
    if (command == '1') {
      digitalWrite(ledPin, !digitalRead(ledPin));
      Serial.println("LED toggled");
    }
  }
}