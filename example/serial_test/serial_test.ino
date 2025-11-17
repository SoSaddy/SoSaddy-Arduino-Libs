#include <VariableResistorLite.h>

VariableResistorLite pot(A0);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(pot.get());
  delay(10);
}
