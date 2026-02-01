#include <Arduino.h>

const int readPin = A0;
const int redPin = 4;
const int yellowPin = 3;
const int greenPin = 2;
const int bluePin = 1;

float maxVoltage = 5.0;
float maxAnalogValue = 1023.0;

void setup() {
    Serial.begin(9600);

    // Set the pin mode to OUTPUT
    pinMode(redPin, OUTPUT);
    pinMode(yellowPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
}

void resetLights() {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
}

void loop() {
    int readValue = analogRead(readPin);
    float voltage = readValue * (maxVoltage / maxAnalogValue);
    // TMP36: (V - 0.5V) * 100
    float tempC = (voltage - 0.5) * 100.0;

    Serial.print("Temp: ");
    Serial.print(tempC);
    Serial.print(" °C | Voltage: ");
    Serial.print(voltage);
    Serial.print(" V | ADC: ");
    Serial.println(readValue);

    int voltageCalc = map(readValue, 0, 358, 0, 100);

    Serial.print("Voltage calc: ");
    Serial.println(voltageCalc);

    if (voltageCalc < 10) {
        resetLights();
        digitalWrite(bluePin, HIGH);
    } else if (voltageCalc > 10 && voltageCalc < 30) {
        resetLights();
        digitalWrite(bluePin, HIGH);
        digitalWrite(greenPin, HIGH);
    } else if (voltageCalc > 30 && voltageCalc < 70) {
        resetLights();
        digitalWrite(bluePin, HIGH);
        digitalWrite(greenPin, HIGH);
        digitalWrite(yellowPin, HIGH);
    } else if (voltageCalc > 70) {
        resetLights();
        digitalWrite(redPin, HIGH);
        digitalWrite(bluePin, HIGH);
        digitalWrite(greenPin, HIGH);
        digitalWrite(yellowPin, HIGH);
    } else {
        resetLights();
        Serial.print("No more conditions");
    }

    delay(1000);
}