#include <Arduino.h>

int analogReadPin = A0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int value = analogRead(analogReadPin);
    Serial.println(value);
    delay(100);
}