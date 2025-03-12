#include <Arduino.h>

int led1 = D0;
int led2 = D2;
int led3 = D4;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  delay(5000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(3000);
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(2000);
  digitalWrite(led3, LOW);
}

