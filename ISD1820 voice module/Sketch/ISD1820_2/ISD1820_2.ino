const int recPin = 2;
const int playEPin = 3;
const int irSensorPin = 4;
const int playLPin = 5;

void setup(){
 pinMode(recPin, INPUT);
 pinMode(irSensorPin, OUTPUT);
 Serial.begin(9600);
}

void loop(){
 if(digitalRead(irSensorPin) == 0)
 {
   Serial.println("HELLO!!! LET'S RECORD THE MESSAGE.");
   digitalWrite(recPin, 1);
   delay(10000);
   digitalWrite(recPin, 0);
    delay(1000);
    digitalWrite(playEPin, 1);
   delay(10000);
   digitalWrite(playEPin, 0);
 }
}
