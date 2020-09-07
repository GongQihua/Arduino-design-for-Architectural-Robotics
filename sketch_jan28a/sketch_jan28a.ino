void setup(){
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println("data:");
  Serial.println(sensorValue);
  delay(1000);
}
