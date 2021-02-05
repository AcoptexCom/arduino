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
  Serial.println(analogSignal);
  Serial.print("Pin D2: ");
  Serial.println(digitalSignal);
  // Checks if it has reached the threshold value
  // Comment if else block if you want to use digital signal instead
  if (analogSignal > sensorLimit)
  {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    tone(buzzerPin, 1000, 200);
  }
  else
  {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    noTone(buzzerPin);
  }
  
 // Uncomment this if you want to use digital signal
 /*if (digitalSignal==1)
  {
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    tone(buzzerPin, 1000, 200);
  }
  else
  {
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    noTone(buzzerPin);
  }*/
  delay(100);
}
