#include <Arduino.h>
#include <ArduinoBLE.h>

BLEService ledBleService("4260b278-ccb1-454a-afac-019cba25b4c3");
BLEByteCharacteristic ledBleCharacteristic("368486e1-8dce-4235-bebe-8b76c7c825c5", BLERead | BLEWrite);

const int ledPin = 13;

void setup() {
    Serial.begin(9600);

    pinMode(ledPin, OUTPUT);

    if (!BLE.begin()) {
        Serial.println("Starting BLE failed!");
        while (1);
    }

    BLE.setLocalName("UnoR4_LED");
    BLE.setAdvertisedService(ledBleService);
    ledBleService.addCharacteristic(ledBleCharacteristic);
    BLE.addService(ledBleService);

    // Start advertising
    BLE.advertise();
    Serial.println("BLE LED Peripheral Active");
}

void loop() {
    BLEDevice central = BLE.central();

    if (central.connected()) {
        Serial.print("Device connect with address: ");
        Serial.println(central.address());

        if (ledBleCharacteristic.written()) {
            int inComingValue = ledBleCharacteristic.value();
            Serial.print("in coming value: ");
            Serial.println(inComingValue);

            if (inComingValue == 1) {
                digitalWrite(ledPin, HIGH);
            } else {
                digitalWrite(ledPin, LOW);
            }
        }
    } else {
        Serial.println("No device connected...");
    }

    delay(100);
}