#include <VariableResistor.h>

#define PIN_POT A0

VariableResistor pot;

void setup() {
  Serial.begin(9600);
  pot.setPin(PIN_POT);
  pot.setBounds(64, 1000); // Границы: нижняя-64, верхняя-1000
}

void loop() {
  Serial.print("Percent: ");
  Serial.print(pot.getPercent());
  Serial.println("%");
  delay(250);
}
