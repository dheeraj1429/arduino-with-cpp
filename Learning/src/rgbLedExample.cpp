#include <Arduino.h>

const int redPin = 3;
const int bluePin = 5;
const int greenPin = 6;

void setup() {
    Serial.begin(9600);

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

    Serial.println("Please input your colour name.");
}

/**
 * Colors
 * Red: R - 205, G - 28, B - 24;
 * Yellow: R - 255, G - 255, B - 197;
 * Green: R - 80, G - 200, B - 120;
 */

void redLight() {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
}

void yellowLight() {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 197);
}

void greenLight() {
    analogWrite(redPin, 80);
    analogWrite(greenPin, 200);
    analogWrite(bluePin, 120);
}

void loop() {
    if (Serial.available() > 0) {
        String input = Serial.readString();
        input.trim();

        if (input == "red") {
            redLight();
        } else if (input == "yellow") {
            yellowLight();
        } else if (input == "green") {
            greenLight();
        } else {
            Serial.println("No color match.");
        }
    }

    delay(1000);
}