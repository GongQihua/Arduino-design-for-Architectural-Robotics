#include <Stepper.h>
#define STEPS 2038
  Stepper stepper(STEPS,8,10,9,11);
  const int buttonPin = 2;     // the number of the pushbutton pin
  const int ledPin =  13;      // the number of the LED pin
  int buttonState = 0;         // variable for reading the pushbutton status
  int flag = 0;
  int button = 0;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin);
  int sensorValue = analogRead(A0);
  Serial.println("data:");
  Serial.println(sensorValue);
  delay(1000);
  
  if ((buttonState == HIGH)&&(flag == 0)) {
    digitalWrite(ledPin, HIGH);// turn LED on:
    stepper.setSpeed(10);
    stepper.step(638);
    digitalWrite(ledPin, LOW);// turn LED off:
    button = 1;
    flag = 1;
    Serial.println("button1:");
    Serial.println(button);
    delay(10000);
  } 

  if ((buttonState == HIGH)&&(flag == 1)){
    digitalWrite(ledPin, HIGH);// turn LED on:
    stepper.setSpeed(10);
    stepper.step(-638);
    digitalWrite(ledPin, LOW);// turn LED off:
    button = 0;
    flag = 0;
    Serial.println("button2:");
    Serial.println(button);
    delay(10000);
  }
    
  if ((sensorValue >= 600)&&(flag == 0)&&(button == 0)){
    digitalWrite(ledPin, HIGH);// turn LED on:
    stepper.setSpeed(10);
    stepper.step(638);
    digitalWrite(ledPin, LOW);// turn LED off:
    flag = 1;
   }  
  else if ((sensorValue < 600)&&(flag == 1)&&(button == 0)){
    digitalWrite(ledPin, HIGH);// turn LED on:
    stepper.setSpeed(10);
    stepper.step(-638);
    digitalWrite(ledPin, LOW);// turn LED off:
    flag = 0;
  }
  Serial.println("flag:");
  Serial.println(flag);  
}
