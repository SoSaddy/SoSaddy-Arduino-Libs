/*
Управление скоростью мотора через ШИМ в два направления при помощи потенциометра.
*/

// Библиотека
#include <Motor.h>

// Пины
#define PIN_POT A0      // потенциометр
#define PIN_MOTOR_A1 5  // мотор (на ШИМ)
#define PIN_MOTOR_A2 6  // мотор (на ШИМ)

// Экземпляр
Motor motor;

// Глобальные переменные
int value;              // напряжение на потенциометре
uint8_t speed;          // скорость

void setup() {
  pinMode(PIN_POT, INPUT);
  motor.setPins(PIN_MOTOR_A1, PIN_MOTOR_A2);
}

void loop() {

  // Напряжение на потенциометре (0-1023)
  value = analogRead(PIN_POT);

  // Отсечка направления
  if (value < 512) {

    // Ускорение вперёд, где: 511 - мин.скорость, 0 - макс.скорость
    speed = map(value, 511, 0, 0, 255);
    motor.movePWM(speed, FORWARD);

  } else {

    // Ускорение назад, где: 512 - мин.скорость, 1023 - макс.скорость
    speed = map(value, 512, 1023, 0, 255);
    motor.movePWM(speed, BACKWARD);

  }
  
}
