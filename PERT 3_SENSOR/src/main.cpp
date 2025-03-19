#include <Arduino.h>

// Deklarasi Variabel
int echoPin = D1;
int trigPin = D0;
int ledPin = D2;

// Deklarasi Waktu dan Jarak
long duration;
int distance;

void setup() {
  pinMode (echoPin, INPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (ledPin, OUTPUT);

  Serial.begin (9600);
}

void loop() {
 digitalWrite(trigPin,LOW);
 delayMicroseconds(5);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(5);
 digitalWrite (trigPin, LOW);

 // UNTUK MENGHITUNG WAKTU SINYAL DITERIMA
 duration = pulseIn(echoPin, HIGH);

 // Menghitung Jarak
 distance = duration*0.034/2;

 // Display serial monitor
 Serial.print("Distance");
 Serial.print(distance);
 Serial.print("cm");

 // Set LED berdasarkan kondisi
 if (distance>=10){
  digitalWrite(ledPin, HIGH);
 }
 else {
  digitalWrite(ledPin, LOW);
 }
 delay(1000);
}

