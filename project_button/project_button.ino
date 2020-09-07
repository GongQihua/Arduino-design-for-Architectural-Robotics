#include <Stepper.h>
#define STEPS 2038
  Stepper stepper(STEPS,8,10,9,11);
  const int buttonPin = 2;     // the number of the pushbutton pin
  const int ledPin =  13;      // the number of the LED pin
  int buttonState = 0;         // variable for reading the pushbutton status
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);// turn LED on:
    stepper.setSpeed(10);
    stepper.step(2038);
    digitalWrite(ledPin, LOW);// turn LED off:
    delay(5000);
  } else {
    digitalWrite(ledPin, HIGH);// turn LED on:
    stepper.setSpeed(10);
    stepper.step(-638);
    digitalWrite(ledPin, LOW);// turn LED off:
    delay(5000);
    delay(5000);
  }
}
