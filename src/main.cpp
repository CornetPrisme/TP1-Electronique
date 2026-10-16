#include <Arduino.h>

const int PIN_OUT = 2;
const int PIN_LED = 13;
int etatPrecedent = HIGH;
unsigned long compteur = 0;

void setup() {
  pinMode(PIN_OUT, INPUT);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int etatActuel = digitalRead(PIN_OUT);
  if (etatActuel != etatPrecedent){
    compteur++;
    Serial.println(compteur);
  }
  etatPrecedent = etatActuel;
}