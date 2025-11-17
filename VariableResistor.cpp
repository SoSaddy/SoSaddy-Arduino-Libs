#include <VariableResistor.h>

// Конструктор
VariableResistor::VariableResistor(uint8_t pin) {
	this->_value = 0;
    this->_lower = 0;
    this->_upper = 1023;
    this->_lower_min = 1023;
    this->_upper_max = 0;
	setPin(pin);
	resetCalibration();
	get();
}

// Получить состояние
int VariableResistor::get() {
	this->_value = analogRead(this->_pin);
	return this->_value;
}
int VariableResistor::getMapped(int fromLow, int fromHigh, int toLow, int toHigh) {
	get();
	return map(this->_value, fromLow, fromHigh, toLow, toHigh);
}
uint8_t VariableResistor::getPercent() {
    if (this->_upper == this->_lower) return 0;
   	int per = map(get(), this->_lower, this->_upper, 0, 100);
    return static_cast <uint8_t>(constrain(per, 0, 100));
}

// Границы
void VariableResistor::setBounds(int lower, int upper) {
	this->_lower = lower;
	this->_upper = upper;
}
void VariableResistor::setLower(int lower) {
	this->_lower = lower;
}
void VariableResistor::setUpper(int upper) {
	this->_upper = upper;
}
int VariableResistor::getLower() {
	return this->_lower;
}
int VariableResistor::getUpper() {
	return this->_upper;
}

// Калибровка
void VariableResistor::calibrate() {
	if (this->_value < this->_lower_min) {
		this->_lower_min = this->_value;
	}
	if (this->_value > this->_upper_max) {
		this->_upper_max = this->_value;
	}
	setBounds(this->_lower_min, this->_upper_max);
}
void VariableResistor::resetCalibration() {
	this->_lower_min = 1023;
	this->_upper_max = 0;
	setBounds(0, 1023);
}

// Установить пин
void VariableResistor::setPin(uint8_t pin) {
	this->_pin = pin;
	pinMode(pin, INPUT);
}