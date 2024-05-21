#include <Arduino.h>

const int pinTrig = DD2;
const int pinEcho = DD3;
unsigned long duration;
float total, cm;

void setup() {
  Serial.begin(9600);
  pinMode(pinTrig,OUTPUT);
  pinMode(pinEcho,INPUT);
}

void loop() {
// uS / 58 = centimeters

// range = high level time * velocity (340M/S) / 2;
  digitalWrite(pinTrig, LOW);
    delayMicroseconds(5);
    digitalWrite(pinTrig, HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig, LOW);

    duration = pulseIn(pinEcho,HIGH);
    total = (float)duration * 340.0 / 2.0 / 10000.0; // cm
    Serial.println(total);
    delay(4000);
    // delayMicroseconds(10);
    // digitalWrite(pinTrig, LOW);
    
    
    // cm = duration / 29 / 2;
    // Serial.print(cm);
    // Serial.print("cm");
    // Serial.println();
    // delay(100);
  
  
}