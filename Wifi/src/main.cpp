#include <Arduino.h>
#include <ArduinoHttpClient.h>
#include <WiFiS3.h>

char ssid[] = "NAME_OF_YOUR_WIFI";
char pass[] = "PASSWORD_OF_YOUR_WIFI";

char serverAddress[] = "google.com";
int port = 80;

WiFiClient wifi;
HttpClient client = HttpClient(wifi, serverAddress, port);

void setup() {
    Serial.begin(9600);
    while (!Serial);

    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);

    while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
        Serial.println("Attempt to connect to Wi-Fi network...");
        delay(500);
    }

    Serial.println("\nConnected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    Serial.println("Starting request...");

    client.get("/");

    int statusCode = client.responseStatusCode();
    String response = client.responseBody();

    Serial.print("Status code: ");
    Serial.println(statusCode);
    Serial.print("Response: ");
    Serial.println(response);

    delay(3000);
}