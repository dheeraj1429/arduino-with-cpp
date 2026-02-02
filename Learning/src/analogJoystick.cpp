#include <Arduino.h>
#include <Servo.h>

#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN 2

int xValue;
int yValue;
int buttonState;

const int servoPin = 11;
double servoPos = 0.0;
double servoStep = 1.0;

Servo arm;

void setup() {
    Serial.begin(9600);

    pinMode(VERT_PIN, INPUT);
    pinMode(HORZ_PIN, INPUT);
    pinMode(SEL_PIN, INPUT_PULLUP);

    // setup servo
    arm.attach(servoPin);
    arm.write(servoPos);
}

void loop() {
    int vert = analogRead(VERT_PIN);
    int hort = analogRead(HORZ_PIN);
    bool selPressed = digitalRead(SEL_PIN) == LOW;

    // converting the hort value to from 0 - 1023 to 0 - 180;
    int rotation = map(hort, 0, 1023, 0, 180);
    Serial.print("Rotation: ");
    Serial.print(rotation);
    Serial.print(" | Vertical: ");
    Serial.println(vert);

    arm.write(rotation);

    // delay(1000);
}