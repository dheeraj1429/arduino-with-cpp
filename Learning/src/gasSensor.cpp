#include <Arduino.h>

const int sensorDOutPin = 8;

int sensorValue;

void setup() {
    Serial.begin(9600);
    Serial.println("MQ2 warming up");
    delay(200);  // allow the MQ2 to warm up
}

void loop() {
    sensorValue = digitalRead(sensorDOutPin);

    Serial.print("Digital Output: ");
    Serial.print(sensorValue);

    if (sensorValue) {
        Serial.println("  |  Smoke: -");
    } else {
        Serial.println("  |  Smoke: Detected!");
    }

    delay(2000);  // wait 2s for next reading
}