#include <Arduino.h>

const int irPin = 7;

void setup() {
    Serial.begin(9600);

    pinMode(irPin, INPUT);
}

void loop() {
    if (digitalRead(irPin) == LOW) {
        Serial.println("Object Detected!");
    } else {
        Serial.println("No object detected...");
    }
}