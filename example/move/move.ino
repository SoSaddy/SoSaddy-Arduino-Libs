/*
Движение мотора в два направления через логические уровни.
*/

// Библиотека
#include <Motor.h>

// Пины
#define PIN_MOTOR_A1 1
#define PIN_MOTOR_A2 2

// Экземпляр
Motor motor;

void setup() {
  motor.setPins(PIN_MOTOR_A1, PIN_MOTOR_A2);
}

void loop() {
  motor.move(FORWARD);
  delay(1000);
  motor.move(BACKWARD);
  delay(1000);
}
