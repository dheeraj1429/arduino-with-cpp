#include <Arduino.h>

const int relayFirstPin = 2;
const int relaySecondPin = 3;
const int relayThirdPin = 4;

void setup() {
    Serial.begin(9600);

    pinMode(relayFirstPin, OUTPUT);
    pinMode(relaySecondPin, OUTPUT);
    pinMode(relayThirdPin, OUTPUT);
}

void loop() {
    digitalWrite(relayFirstPin, HIGH);
    delay(1000);
    digitalWrite(relayFirstPin, LOW);
    delay(1000);

    digitalWrite(relaySecondPin, HIGH);
    delay(1000);
    digitalWrite(relaySecondPin, LOW);
    delay(1000);

    digitalWrite(relayThirdPin, HIGH);
    delay(1000);
    digitalWrite(relayThirdPin, LOW);
    delay(1000);
}