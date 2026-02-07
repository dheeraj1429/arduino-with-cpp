#include <Arduino.h>
#include <ArduinoBLE.h>
#include <DHT11.h>

#define DHT_PEN 2

// Temperature and humidity setup
BLEService temperatureService("33955990-7c98-41ac-aaed-dbf9d17bcba7");
BLEIntCharacteristic temperatureChar("a2e655b6-f452-4974-9798-7757be7c7b52", BLERead | BLENotify);
BLEIntCharacteristic humidityChar("5bdf3285-1514-46c0-80fb-89140999810c", BLERead | BLENotify);
DHT11 dht11(DHT_PEN);

void setup() {
    Serial.begin(9600);

    if (!BLE.begin()) {
        Serial.println("Starting BLE failed!");
        while (1);
    }

    Serial.println("DHT11 sensor found..");
    BLE.setLocalName("Arduino-Weather");
    BLE.setAdvertisedService(temperatureService);
    temperatureService.addCharacteristic(temperatureChar);
    temperatureService.addCharacteristic(humidityChar);
    BLE.addService(temperatureService);

    BLE.advertise();
    Serial.println("Arduino-Weather Ble Peripheral Active...");
}

void loop() {
    BLEDevice central = BLE.central();

    if (central && central.connected()) {
        Serial.print("Connected device: ");
        Serial.println(central.address());

        int temperature;
        int humidity;

        int result = dht11.readTemperatureHumidity(temperature, humidity);

        if (result != DHT11::ERROR_CHECKSUM && result != DHT11::ERROR_TIMEOUT) {
            Serial.print("Humidity: ");
            Serial.print(temperature);
            Serial.print("%  Temperature: ");
            Serial.print(humidity);
            Serial.println("°C");

            temperatureChar.writeValue(temperature);
            humidityChar.writeValue(humidity);

            delay(200);
        } else {
            Serial.println(dht11.getErrorString(result));
        }

    } else {
        Serial.println("No device connected...");
    }
}