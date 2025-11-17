/*
Мигание светодиода по заданному массиву-паттерну.
*/

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
