#include <Timer.h>

Timer timer(2000);

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (timer.get()) {
    Serial.println("Hello, World! ");
  }
}
