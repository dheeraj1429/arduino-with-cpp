const int redLightPin = 12;
const int yellowLightPin = 11;
const int greenLightPin = 10;

void setup() {
  Serial.begin(9600);
  
  pinMode(redLightPin, OUTPUT);
  pinMode(yellowLightPin, OUTPUT);
  pinMode(greenLightPin, OUTPUT);

  Serial.println("--- Traffic Light System Online ---");
}

void loop() {
  // 1 ( GREEN LIGHT )
  digitalWrite(greenLightPin, HIGH);
  runCoundown("GREEN", 10);
  digitalWrite(greenLightPin, LOW);

  // 2 ( YELLOW LIGHT )
  digitalWrite(yellowLightPin, HIGH);
  runCoundown("YELLOW", 3);
  digitalWrite(yellowLightPin, LOW);

  // 1 ( GREEN LIGHT )
  digitalWrite(redLightPin, HIGH);
  runCoundown("RED", 5);
  digitalWrite(redLightPin, LOW);
}


void runCoundown(String color, int seconds) {
  for (int i = 0; i < seconds; i ++) {
    Serial.println(color);
    Serial.print(" Light: ");
    Serial.print(i);
    Serial.println(" seconds remaining...");
    delay(1000); // 1 second loop dealy
  }
}