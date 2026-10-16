#include <Arduino.h>

// TP1 - Manipulation 6a : temps de reponse du capteur
const int PIN_OUT = 2;
const int PIN_ENABLE = 3;
void setup() {
  pinMode(PIN_OUT, INPUT);
  pinMode(PIN_ENABLE, OUTPUT);
  digitalWrite(PIN_ENABLE, LOW); // emetteur eteint au depart
  Serial.begin(9600);
}

void loop() {
  // 1) Emetteur eteint : on attend que OUT soit revenue a HIGH
  digitalWrite(PIN_ENABLE, LOW);
  delay(10);
  if (digitalRead(PIN_OUT) == LOW) {
    Serial.println("OUT deja a LOW emetteur eteint : signal IR parasite ?");
    delay(500);
  return;
  }
  // 2) On allume l’emetteur et on chronometre jusqu’au passage a LOW
  unsigned long t0 = micros();
  digitalWrite(PIN_ENABLE, HIGH);
  while (digitalRead(PIN_OUT) == HIGH) {
  if (micros() - t0 > 5000) break; // abandon au bout de 5 ms
  }
  unsigned long dt = micros() - t0;
  if (dt > 5000) {
    Serial.println("Pas de detection (aucun objet ?)");
  } else {
    Serial.print("Temps de reponse : ");
    Serial.print(dt);
    Serial.println(" us");
  }
  delay(500);
}