#include <Arduino.h>

// TP1 - Manipulation 6b : detection synchronisee
// A COMPLETER : cherchez les commentaires "TODO"
const int PIN_OUT = 2;
const int PIN_ENABLE = 3;
const int PIN_LED = 13;
void setup() {
  pinMode(PIN_OUT, INPUT);
  pinMode(PIN_ENABLE, OUTPUT);
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

// Renvoie 1 : objet reellement detecte
// 0 : rien
// -1 : perturbation IR exterieure
int mesureSynchronisee() {
  digitalWrite(PIN_ENABLE, HIGH); // emetteur allume
  delay(2); // TODO (Q22) : justifier cette attente
  int outOn = digitalRead(PIN_OUT);
  digitalWrite(PIN_ENABLE, LOW); // emetteur eteint
  delay(2);
  int outOff = digitalRead(PIN_OUT);
  if (outOff == LOW){return -1;}
  else if (outOn == LOW){return 1;}
  return 0;
// TODO : renvoyer -1 si outOff vaut LOW
// renvoyer 1 si outOn vaut LOW (et outOff vaut HIGH)
// renvoyer 0 dans tous les autres cas
}

void loop() {
  int r = mesureSynchronisee();
  if (r==1){
    digitalWrite(PIN_LED, HIGH);
    Serial.println("Objet");
  }
  else if (r==0) {
    digitalWrite(PIN_LED, LOW);
    Serial.println("Rien");
  }
  else {
    digitalWrite(PIN_LED, LOW);
    Serial.println("Pertubation IR");
  }
  // TODO : allumer PIN_LED uniquement si r vaut 1, et afficher
  // "Objet", "Rien" ou "Perturbation IR !" dans le moniteur serie
  delay(100);
}