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
