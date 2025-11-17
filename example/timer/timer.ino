/*
Мигание светодиода каждые 2000мс по переключению внутреннего состояния.
*/

#include <Timer.h>

Timer timer(2000, AS_SWITCH);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, timer.get());
}
