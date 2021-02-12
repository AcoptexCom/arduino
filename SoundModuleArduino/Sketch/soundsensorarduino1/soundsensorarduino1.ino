const int ledPin=13;
const int sensorPin=7;

// Variable to store the time when last event happened
unsigned long lastEvent = 0;

void setup() {
pinMode(sensorPin, INPUT);  // Set sensor pin as an INPUT
pinMode(ledPin, OUTPUT); // Set LED pin as OUTPUT
}

void loop() {
  // Read Sound sensor
  int sensorValue = digitalRead(sensorPin);

  // If pin goes LOW, sound is detected
  if (sensorValue == LOW) {
    
    // If 25ms have passed since last LOW state, it means that
    // the clap is detected and not due to any spurious sounds
    if (millis() - lastEvent > 25) {
      digitalWrite(ledPin, HIGH);
    }
    
    // Remember when last event happened
    lastEvent = millis();
  }
  digitalWrite(ledPin, LOW);
}
