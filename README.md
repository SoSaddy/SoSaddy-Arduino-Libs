# Кнопка

<details>
<summary>Библиотека</summary>

# Назначение библиотеки
Удобное управление кнопкой, включающее в себе унифицированные функции и защиту от дребезга.

# Свойства
Подключение библиотеки
```c++
#include <Button.h>
```

Объявление экземпляра
```c++
Button(uint8_t pin = 0, bool toggle = false, uint8_t dd = 50);
```
```c++
Button button;                   // по умолчанию без привязки пинов и режима переключения
// или
Button button(PIN, TOGGLE, 25);  // оционально: [пин, режим переключения, задержка дребезга]
```

Методы
```c++
// Очистка всех параметров (кроме пина)
void reset();

// Зажатие
bool isCheck();

// Разовое срабатывание по отжатию (передний фронт)
bool isReleased();

// Разовое срабатывание по зажатию (задний фронт)
bool isPressed();

// Установить пин
void setPin(uint8_t pin);

// Установить режим переключения
void setToggleMode(bool toggle);

// Получить переключённое состояние
bool getToggled();

// Защитная здержка от дребезга
void setDebounceDelay(uint8_t debounce_delay);
```

## **Важно**
Метод .isCheck не работает в режиме переключателя (toggle).

# Примеры работы с кнопкой

Пример 1. Включение светодиода по зажатию.
<br>
Мотод .isCheck получает постоянный сигнал зажатой кнопки, по которому происходит проверка и включение светодиода.
```c++
#include <Button.h>

Button btn;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  if (btn.isCheck()) digitalWrite(LED_BUILTIN, HIGH);
}
```

Пример 2. Переключение состояний.
<br>
Режим работы кнопки, как переключателя состояния. В примере используется режим TOGGLE. При отпускании кнопки происходит переключение состояния кнопки. Демонстрация работы на светодиоде.
```c++
#include <Button.h>

Button btn;

void setup() {
  btn.setPin(5);            // установка пина
  btn.setDebounceDelay(25); // установка защитной задержки от дребезга 25мс
  btn.setToggleMode(true);  // включить режим переключения
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  if (btn.isReleased()) digitalWrite(LED_BUILTIN, HIGH);
}
```
</details>

<details>
<summary>Список обновлений</summary>
Тут пусто.
</details>
