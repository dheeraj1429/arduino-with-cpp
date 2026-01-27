const int redLightPin = 6;
const int greenLightPin = 7;
const int yellowLightPin = 8;

int counter = 10;

void resetLights() {
  digitalWrite(redLightPin, LOW);
  digitalWrite(greenLightPin, LOW);
  digitalWrite(yellowLightPin, LOW);
}

void setup() {
  pinMode(redLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  counter--;
  delay(1000);

  if (counter >= 7) {
    resetLights();
    digitalWrite(redLightPin, HIGH);
    Serial.println("Blink the red light...");
  } else if (counter >= 4) {
    resetLights();
    digitalWrite(greenLightPin, HIGH);
    Serial.println("Blink the green light...");
  } else if (counter >= 0) {
    resetLights();
    digitalWrite(yellowLightPin, HIGH);
    Serial.println("Blink the yellow light...");
  } else {
    resetLights();
    counter = 10;
    Serial.println("Rest...");
  }
}