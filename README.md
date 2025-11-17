# Переменный резистор (облегчённый)
## Более продвинутый вариант [этой](https://github.com/SoSaddy/SoSaddy-Arduino-Libs/tree/Variable-Resistor) библиотеки.

<details>
<summary>Библиотека</summary>

# Назначение библиотеки
Удобное обращение с переменным резистором.

# Свойства
Подключение библиотеки
```c++
#include <VariableResistorLite.h>
```

Объявление экземпляра
```c++
VariableResistorLite potentiometr;
// или
VariableResistorLite potentiometr(A0); // аргументы [GPIO]
```

Методы
```c++
// Взять значение от 0 до 1023
int get();

// Установить пин
void setPin(uint8_t pin);
```

# Пример работы

Пример. Вывод значения.
<br>
Вывод значения напряжения на потенциометре в последовательный порт. 
```c++
#include <VariableResistorLite.h>

VariableResistorLite pot(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(pot.get());
  delay(10);
}
```
</details>

<details>
<summary>Список обновлений</summary>
Тут пусто.
</details>
