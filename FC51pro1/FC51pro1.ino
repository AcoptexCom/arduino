int LED = 13; // we will use the onboard LED of Arduino Nano
int sensorPin = 7; //sensor attached to digital pin 7 of the Arduino Nano
int sensorValue=HIGH; //By default, HIGH means that there are no obstracle

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(sensorPin, INPUT);
    Serial.begin(9600);
}

void loop() {
    sensorValue = digitalRead(sensorPin);
    if (sensorValue == LOW) {
        Serial.println("OBSTACLE!!, OBSTACLE!!");

        digitalWrite(LED, HIGH);
    } else {
        Serial.println("clear");
        digitalWrite(LED, LOW);
    }
    delay(200);
}
