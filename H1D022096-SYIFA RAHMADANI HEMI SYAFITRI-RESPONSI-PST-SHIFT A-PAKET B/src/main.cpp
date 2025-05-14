#include <Arduino.h>
#include <Servo.h>


int TRIG_PIN = D5;
int ECHO_PIN = D6;
int SERVO_PIN =  D7;

Servo palang; 

long readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH); 
  long distance = duration * 0.034 / 2;
  return distance;
}

void setup() {
  Serial.begin(9600); 
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  palang.attach(SERVO_PIN); 
  palang.write(0);           
  delay(1000);
}

void loop() {
  long jarak = readDistanceCM();
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");

  if (jarak > 0 && jarak <= 15) {
    Serial.println("Palang terbuka karena ada kendaraan");
    palang.write(90); 
    delay(3000);      
  } else {
   
    Serial.println("Palang tertutup karena tidak ada kendaraan");
    palang.write(0);
  }

  delay(500);
}