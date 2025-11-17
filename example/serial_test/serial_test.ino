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
