#include <TimerLite.h>

// Конструктор
Timer::Timer(uint32_t cooldown) {
	clear();
	this->_cooldown = cooldown;
}

// Получить состояние
bool Timer::get() {
	return _getState(this->_cooldown);
}
bool Timer::get(uint32_t& cooldown) {
	return _getState(cooldown);
}

// Получить состояние (приватный метод)
bool Timer::_getState(const uint32_t& cooldown) {
	if (millis() - this->_time >= cooldown) {
		clear();
		return true;
	}
	return false;
}

// Установка задержки
void Timer::setCooldown(uint32_t cooldown) {
	this->_cooldown = cooldown;
}

// Обнуление задержки
void Timer::clear() {
	this->_time = millis();
}