/*******
 
 All the resources for this project:
 https://randomnerdtutorials.com/

*******/

const int redLedPin = 12;
const int greenLedPin = 11;
const int buzzerPin = 10;
const int analogSignalPin = A0;
const int digitalSignalPin = 2;
//Variable to keep your threshold value
int sensorLimit = 400; //Comment it if you want to use digital signal instead

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(analogSignalPin, INPUT);
  pinMode(digitalSignalPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSignal = analogRead(analogSignalPin);
  int digitalSignal = digitalRead(digitalSignalPin);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  // Comment 
  if (analogSignal > sensorLimit)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  
 // Uncomment this if you want to use digital signal
 /*if (digitalSignal)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }*/
  delay(100);
}
