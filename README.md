<details>
<summary>Библиотека</summary>

# Назначение библиотеки
Таймер не прерывает поток, как это делает delay().

# Свойства
Подключение библиотеки
```c++
#include <Timer.h>
```

Объявление экземпляра
```c++
Timer timer;                  // по умолчанию: задержка 1000мс, режим AS_TRIGGER
// или
Timer timer(2000, AS_SWITCH); // аргументы [задержка, режим]
```

Методы
```c++
// Возвращает состояние
bool get();

// Возвращает состояние (по указанной в аргументе задержке)
bool get(uint32_t& cooldown);

// Возвращает состояние (по ссылке в аргументе на массив-паттерн)
bool get(uint32_t* pattern, size_t size);

// Сстановка режима: AS_SWITCH, AS_TRIGGER
void setMode(uint8_t mode);

// Установка задержки
void setCooldown(uint32_t cooldown);

// Синхронизирует задержку (сброс)
void clear();
```

# Примеры работы таймера

Пример 1. Мигание светодиода.
<br>
Таймер по срабатыванию переключает состояние переменной state, которая затем используется для передачи логического уровня на пин со светодиодом.
```c++
#include <Timer.h>

Timer timer;  // по умолчанию: задержка 1000мс, режим AS_TRIGGER
bool state = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (timer.get()) state = !state;
  digitalWrite(LED_BUILTIN, state);
}
```

Пример 2. Мигание светодиода - альтернативный.
<br>
Таймер по срабатыванию переключает внутреннее состояние каждые 2000мс.
```c++
#include <Timer.h>

Timer timer(2000, AS_SWITCH);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, timer.get());
}
```

Пример 3. Гибкая настройка.
```c++
#include <Timer.h>

Timer timer;

void setup() {
  timer.setCooldown(5000);
  timer.setMode(AS_TRIGGER);
}

void loop() {
  if (timer.get()) {
    timer.setCooldown(3000);
    // ...
  } else {
    // ...
  }
}
```

Пример 4. Паттерны.
<br>
Задаётся массив с интервалами времени (паттерн) и передаётся в метод .get() для мигания встроенного светодиода.
Переключение по паттерну происходит циклично - после конца к началу. Работает для двух режимов AS_SWITCH и AS_TRIGGER.
```c++
#include <Timer.h>

// Инициализация глобального массива с фиксированным размером.
// Паттерн мигания: 1000мс -> 500мс -> 250мс -> 100мс
const size_t pattern_size = 4;
uint32_t pattern[pattern_size] = {1000, 500, 250, 100};

Timer timer;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  timer.setMode(AS_SWITCH);
}

void loop() {
  digitalWrite(LED_BUILTIN, timer.get(pattern, pattern_size));
}
```
</deatails>

<details>
<summary>Список обновлений</summary>
Тут пусто.
</details>
