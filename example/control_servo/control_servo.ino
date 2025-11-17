#include <VariableResistor.h>
#include <Servo.h>

#define PIN_POT A0
#define PIN_SERVO 5

VariableResistor pot;
Servo servo;

void setup() {
  pot.setPin(PIN_POT);
  servo.attach(PIN_SERVO);
}

void loop() {
  pot.calibrate();
  int q = pot.getMapped(pot.getLower(), pot.getUpper(), 0, 255);
  servo.write(q);
}
