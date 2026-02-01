#include <Arduino.h>

#define VERT_PIN A0
#define HORZ_PIN A1
#define SEL_PIN 2

int xValue;
int yValue;
int buttonState;

void setup() {
    Serial.begin(9600);

    pinMode(VERT_PIN, INPUT);
    pinMode(HORZ_PIN, INPUT);
    pinMode(SEL_PIN, INPUT_PULLUP);
}

void loop() {
    int vert = analogRead(VERT_PIN);
    int hort = analogRead(HORZ_PIN);
    bool selPressed = digitalRead(SEL_PIN) == LOW;

    Serial.print("VERT: ");
    Serial.print(vert);
    Serial.print(" | HORT : ");
    Serial.print(hort);
    Serial.print(" | Pressed : ");
    Serial.println(selPressed);

    delay(1000);
}