#include <Arduino.h>

const int ledAPin = 2;
const int ledBPin = 3;
const int ledCPin = 4;
const int ledDPin = 5;
const int ledEPin = 6;
const int ledFPin = 7;
const int ledGPin = 8;

// Seven segment digit patterns (common cathode)
// Index: 0=A, 1=B, 2=C, 3=D, 4=E, 5=F, 6=G
const bool digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},  // 0
    {0, 1, 1, 0, 0, 0, 0},  // 1
    {1, 1, 0, 1, 1, 0, 1},  // 2
    {1, 1, 1, 1, 0, 0, 1},  // 3
    {0, 1, 1, 0, 0, 1, 1},  // 4
    {1, 0, 1, 1, 0, 1, 1},  // 5
    {1, 0, 1, 1, 1, 1, 1},  // 6
    {1, 1, 1, 0, 0, 0, 0},  // 7
    {1, 1, 1, 1, 1, 1, 1},  // 8
    {1, 1, 1, 1, 0, 1, 1}   // 9
};

void displayDigit(int digit) {
    if (digit < 0 || digit > 9) return;

    digitalWrite(ledAPin, digits[digit][0]);
    digitalWrite(ledBPin, digits[digit][1]);
    digitalWrite(ledCPin, digits[digit][2]);
    digitalWrite(ledDPin, digits[digit][3]);
    digitalWrite(ledEPin, digits[digit][4]);
    digitalWrite(ledFPin, digits[digit][5]);
    digitalWrite(ledGPin, digits[digit][6]);
}

void setup() {
    pinMode(ledAPin, OUTPUT);
    pinMode(ledBPin, OUTPUT);
    pinMode(ledCPin, OUTPUT);
    pinMode(ledDPin, OUTPUT);
    pinMode(ledEPin, OUTPUT);
    pinMode(ledFPin, OUTPUT);
    pinMode(ledGPin, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    for (int i = 0; i <= 9; i++) {
        displayDigit(i);
        Serial.print("Displaying number: ");
        Serial.println(i);
        delay(3000);
    }
}