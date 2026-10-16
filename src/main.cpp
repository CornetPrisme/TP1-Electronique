#include <Arduino.h>

// TP1 - Pilotage de l’emetteur IR (broche ENABLE)
const int PIN_OUT = 2;
const int PIN_ENABLE = 3;
const int PIN_LED = 13;

void setup() {
  pinMode(PIN_OUT, INPUT);
  pinMode(PIN_ENABLE, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Emetteur actif pendant 2 s
  digitalWrite(PIN_ENABLE, HIGH);
  Serial.println("Emetteur ON");
  delay(100);
  digitalRead(PIN_OUT);
  delay(2000);

  // Emetteur eteint pendant 2 s
  digitalWrite(PIN_ENABLE, LOW);
  Serial.println("Emetteur OFF");
  delay(100);
  digitalRead(PIN_OUT);
  delay(2000);
}