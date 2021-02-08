const int recPin = 2;
const int playPin = 3;
const int irSensorPin = 4;
const int ledPin = 13;

void setup()
{
  pinMode(recPin, OUTPUT);
  pinMode(playPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(irSensorPin, INPUT);

  digitalWrite(recPin, LOW);
  digitalWrite(playPin, LOW);
  digitalWrite(ledPin, LOW);
  if (digitalRead(irSensorPin))
  {
    while (digitalRead(irSensorPin));
  }
}

void loop()
{

  if (digitalRead(irSensorPin))
  {
    digitalWrite(ledPin, HIGH);
    digitalWrite(recPin, HIGH);
    delay(5000);
    digitalWrite(ledPin, LOW);
    digitalWrite(recPin, LOW);
    delay(1000);
    digitalWrite(playPin, HIGH);
    delay(6000);
    digitalWrite(playPin, LOW);
    while (digitalRead(irSensorPin));
  }
}
