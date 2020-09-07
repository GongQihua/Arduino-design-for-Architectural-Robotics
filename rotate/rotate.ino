#include <Stepper.h>
 #define STEPS 2038
  Stepper stepper(STEPS,8,10,9,11);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  stepper.setSpeed(10);
  stepper.step(2038);
  delay(1000);
  stepper.setSpeed(10);
  stepper.step(-638);
}
