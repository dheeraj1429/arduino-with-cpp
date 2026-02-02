#include <Arduino.h>
#include <Servo.h>

#define TRIG_PIN 8
#define ECHO_PIN 7
#define SERVO_PWM_PIN 3

Servo arm;
const double servoRotation = 90;

void setup() {
    Serial.begin(9600);

    arm.attach(SERVO_PWM_PIN);
    arm.write(servoRotation);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}

void loop() {
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    int duration = pulseIn(ECHO_PIN, HIGH);
    int distanceInCm = duration / 58;
    int distanceInInches = duration / 148;

    if (distanceInCm < 50) {
        arm.write(0);
    } else {
        delay(1000);
        arm.write(servoRotation);
    }

    // Serial.print("Distance in CM: ");
    // Serial.println(distanceInCm);
    // Serial.print("Distance in inches: ");
    // Serial.println(distanceInInches);

    // delay(1000);
}