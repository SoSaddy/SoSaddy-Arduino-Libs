#include <Motor.h>

// Конструктор
Motor::Motor(uint8_t pin_a, uint8_t pin_b) {
	setPins(pin_a, pin_b);
};

// Движение (DC)
void Motor::move(uint8_t direction) {
	if (direction == FORWARD) {
		digitalWrite(this->_pinA, HIGH);
		digitalWrite(this->_pinB, LOW);
	} else {
		digitalWrite(this->_pinA, LOW);
		digitalWrite(this->_pinB, HIGH);
	}
};

// Движение (PWM)
void Motor::movePWM(uint8_t speed, uint8_t direction) {
	speed = clamp(speed, 0, 255);
	if (direction == FORWARD) {
		analogWrite(this->_pinA, speed);
		digitalWrite(this->_pinB, LOW);
	} else {
		digitalWrite(this->_pinA, LOW);
		analogWrite(this->_pinB, speed);
	}
};

// Остановка (с инерцией)
void Motor::stop() {
	digitalWrite(this->_pinA, LOW);
	digitalWrite(this->_pinB, LOW);
};

// Остановка (резкая)
void Motor::breaks() {
	digitalWrite(this->_pinA, HIGH);
	digitalWrite(this->_pinB, HIGH);
};

// Установка пинов
void Motor::setPins(uint8_t pin_a, uint8_t pin_b) {
	stop();
	this->_pinA = pin_a;
	this->_pinB = pin_b;
	pinMode(pin_a, OUTPUT);
	pinMode(pin_b, OUTPUT);
	digitalWrite(pin_a, LOW);
	digitalWrite(pin_b, LOW);
};