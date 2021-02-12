const int ledPin=13;
const int sensorPin=7;

void setup(){
  pinMode(ledPin, OUTPUT);// Set LED pin as OUTPUT
  pinMode(sensorPin, INPUT);// Set sensor pin as an INPUT
}
  
void loop (){
   // Read Sound sensor
int sensorValue =digitalRead(sensorPin);
  // If pin goes LOW, sound is detected
  if (sensorValue==LOW) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
