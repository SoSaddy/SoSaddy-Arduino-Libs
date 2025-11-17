# Назначение библиотеки
Управление мотором. Поддерживается управление через DC, PWM.

# Свойства
Подключение библиотеки
```c++
#include <Motor.h>
```

Объявление экземпляра
```c++
Motor motor;               // по умолчанию без привязки пинов
// или
Motor motor(PIN_A, PIN_B); // с привязкой пинов
```

Методы
```c++
// Установка пинов мотора
void setPins(uint8_t pin_a, uint8_t pin_b);

// Движение (DC)
void move(uint8_t direction);

// Движение (PWM)
void movePWM(uint8_t speed, uint8_t direction);

// Отключение мотора (плавный)
void stop();

// Тормоза (резко)
void breaks();
```

# Примеры работы с мотором

Пример 1. Движение DC.
<br>
Мотор меняет направление движения через встроенные константы FORWARD и BACKWARD.
```c++
#include <Motor.h>

#define PIN_MOTOR_A1 1
#define PIN_MOTOR_A2 2

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
```

Пример 2. Регулировка скорости и направления.
<br>
Вращением потенциометра в положении задаётся направление и скорость для движения через ШИМ.
```c++
#include <Motor.h>

// Пины
#define PIN_POT A0
#define PIN_MOTOR_A1 5
#define PIN_MOTOR_A2 6

Motor motor;

void setup() {
  pinMode(PIN_POT, INPUT);
  motor.setPins(PIN_MOTOR_A1, PIN_MOTOR_A2);
}

void loop() {

  int value;
  value = analogRead(PIN_POT);

  uint8_t speed;
  if (value < 512) {
    speed = map(value, 511, 0, 0, 255);
    motor.movePWM(speed, FORWARD);
  } else {
    speed = map(value, 512, 1023, 0, 255);
    motor.movePWM(speed, BACKWARD);
  }
  
}
```
