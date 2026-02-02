#include <Arduino.h>

int potPin = A0;
int ledPin = 11;

void setup() {
    Serial.begin(9600);
}

void loop() {
    int potValue = analogRead(potPin);
    int brightness = map(potValue, 0, 1023, 0, 255);

    Serial.println(brightness);

    analogWrite(ledPin, brightness);

    delay(100);
}