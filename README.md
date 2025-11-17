# Переменный резистор
## Облегчённый вариант этой библиотеки можно посмотреть [здесь](https://github.com/SoSaddy/SoSaddy-Arduino-Libs/tree/Variable-Resistor-Lite).

<details>
<summary>Библиотека</summary>

# Назначение библиотеки
Удобное обращение с переменным резистором и дополнительный функционал.

# Свойства
Подключение библиотеки
```c++
#include <VariableResistor.h>
```

Объявление экземпляра
```c++
VariableResistor potentiometr;
// или
VariableResistor potentiometr(A0); // аргументы [GPIO]
```

Методы
```c++
// Взять значение
int get();  // от 0 до 1023
int getMapped(int fromLow, int fromHigh, int toLow, int toHigh);  // преобразованное от 0 до 1023, по аналогии с функцией map()
uint8_t getPercent();  // в процентах

// Границы
void setBounds(int lower, int upper);  // установить верхнюю и нижнюю границы
void setLower(int lower);  // установить нижнюю границу
void setUpper(int upper);  // установить верхнюю границу
int getLower();  // взять значение нижней границы
int getUpper();  // взять значение верхней границы

// Калибровка
void calibrate();

// Сброс откалиброванных параметров
void resetCalibration();

// Установить пин
void setPin(uint8_t pin);

```

# Примеры работы таймера

Пример 1. Вывод значений.
<br>
Вывод значения напряжения на потенциометре в последовательный порт. 
```c++
#include <VariableResistor.h>

#define PIN_POT A0

VariableResistor pot(PIN_POT);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(pot.get());
  delay(10);
}
```

Пример 2. Калибровка.
<br>
Калибровка нижней и верхней допустимой границы значений.
Также допускается ручная калибровка через методы .setBounds() .setLower() .setUpper()
```c++
#include <VariableResistor.h>

#define PIN_POT A0

VariableResistor pot(PIN_POT);

void setup() {
  Serial.begin(9600);
}

void loop() {
  pot.calibrate();
  Serial.print("Lower: " + string(pot.getLower()));
  Serial.println(" Upper: " + string(pot.getUpper()));
  delay(10);
}
```

Пример 3. Управление севроприводом.
<br>
Задание угла поворота сервопривода через преобразование в угловые градусы.
```c++
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
  int q = pot.getMapped(pot.getLower(), pot.getUpper(), 0, 180);
  servo.write(q);
}
```

Пример 4. Процентное значение.
<br>

```c++
#include <VariableResistor.h>

#define PIN_POT A0

VariableResistor pot;

void setup() {
  Serial.begin(9600);
  pot.setPin(PIN_POT);
  pot.setBounds(64, 1000); // Границы: нижняя-64, верхняя-1000
}

void loop() {
  Serial.print("Percent: ");
  Serial.print(pot.getPercent());
  Serial.println("%");
  delay(250);
}
```
</details>

<details>
<summary>Список обновлений</summary>
Тут пусто.
</details>
