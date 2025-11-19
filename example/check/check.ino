#include <Button.h>

Button btn(5);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  if (btn.isCheck()) digitalWrite(LED_BUILTIN, HIGH);
}
