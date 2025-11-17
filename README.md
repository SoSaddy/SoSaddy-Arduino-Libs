# Таймер (облегчённый)
## Более продвинутый вариант [этой](https://github.com/SoSaddy/SoSaddy-Arduino-Libs/tree/Timer) библиотеки.

<details>
<summary>Библиотека</summary>

# Назначение библиотеки
Таймер не прерывает поток, как это делает delay().

# Свойства
Подключение библиотеки
```c++
#include <TimerLite.h>
```

Объявление экземпляра
```c++
TimerLite timer;
// или
TimerLite timer(2000); // аргументы [задержка]
```

Методы
```c++
// Возвращает состояние
bool get();

// Возвращает состояние (по указанной в аргументе задержке)
bool get(uint32_t& cooldown);

// Установка задержки
void setCooldown(uint32_t cooldown);

// Синхронизирует задержку (сброс)
void clear();
```

# Пример работы таймера
Таймер сообщений в последовательный порт.
<br>
```c++
#include <TimerLite.h>

TimerLite timer(2000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (timer.get()) {
    Serial.println("Hello, World!");
  }
}
```
</details>

<details>
<summary>Список обновлений</summary>
Тут пусто.
</details>
