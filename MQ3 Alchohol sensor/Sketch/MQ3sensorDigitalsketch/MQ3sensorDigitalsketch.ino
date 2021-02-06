const int sensorPin = 2;

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bps
  Serial.println("MQ3 sensor warming up!");
  delay(20000); // allow the MQ3 to warm up
}

void loop() {
  int sensorValue = digitalRead(sensorPin); // variable to hold sensor value
  Serial.print("Digital Output: ");
  Serial.print(sensorValue);
  
  // Determine the status
  if (sensorValue) {
    Serial.println("  |  Alcohol: -");
  } else {
    Serial.println("  |  Alcohol: Detected!");
  }
  
  delay(2000); // delay for two seconds
}
