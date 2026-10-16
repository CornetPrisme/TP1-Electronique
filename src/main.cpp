#include <Arduino.h>
// TP1 - Capteur de proximite infrarouge Pololu
// Lecture tout-ou-rien de la sortie OUT
const int PIN_OUT = 2; // Sortie numerique du capteur (active a l’etat bas)
const int PIN_LED = 13; // LED integree de l’Arduino Uno

void setup() {
  pinMode(PIN_OUT, INPUT);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int etat = digitalRead(PIN_OUT);
  if (etat == LOW) { // LOW = objet detecte
  digitalWrite(PIN_LED, HIGH);
  Serial.println("Objet detecte");
  } else {
  digitalWrite(PIN_LED, LOW);
  Serial.println("Rien en vue");
  }
  delay(100);
}