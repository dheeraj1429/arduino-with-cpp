#include <Adafruit_BMP085.h>
#include <Arduino.h>
#include <Wire.h>

/**
 * SDA (Serial Data): This is the lane where the actual information (the "talk") travels.
 * It carries the temperature and pressure data from the BMP180 to your Arduino.
 * SCL (Serial Clock): This is the "metronome" or heartbeat.
 * It ensures that both the Arduino and the sensor are perfectly synchronized so they know exactly when to read the bits of data moving on the SDA line.
 */

Adafruit_BMP085 bmp;

void setup() {
    Serial.begin(9600);

    if (!bmp.begin()) {
        Serial.println("BMP180 not found!");
        while (1);
    }

    Serial.println("BMP180 ready!");
}

void loop() {
    float temperature = bmp.readTemperature();
    int32_t pressure = bmp.readPressure();
    float altitude = bmp.readAltitude();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" Pa");

    Serial.print("Altitude: ");
    Serial.print(altitude);
    Serial.println(" m");

    Serial.println();
    delay(1000);
}