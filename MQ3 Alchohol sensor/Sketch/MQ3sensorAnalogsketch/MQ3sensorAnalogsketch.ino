/*
Based on the calibration values, the program below defines the
following ranges to determine the alcohol concentration:

< 120 is sober
120-400 is drinking – but within legal limits
> 400 is drunk

*/
const int sensorPin = A0;
/* Change these values based on your calibration values */
#define Sober 120   // Define max value that we consider sober
#define Drunk 400   // Define min value that we consider drunk

void setup() {
  Serial.begin(9600); // initialize serial communication at 9600 bps
  Serial.println("MQ3 sensor warming up!");
  delay(20000); // allow the MQ3 to warm up
}

void loop() {
  float sensorValue = analogRead(sensorPin);//variable to store sensor value
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue); 
  // Determine the status
  if (sensorValue < Sober) {
    Serial.println("  |  Status: Stone Cold Sober");
  } else if (sensorValue >= Sober && sensorValue < Drunk) {
    Serial.println("  |  Status: Drinking but within legal limits");
  } else {
    Serial.println("  |  Status: DRUNK");
  }
  delay(2000); // delay for two seconds
}
