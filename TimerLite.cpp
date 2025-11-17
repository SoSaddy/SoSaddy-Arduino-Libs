#include <TimerLite.h>

// Конструктор
TimerLite::TimerLite(uint32_t cooldown) {
	clear();
	this->_cooldown = cooldown;
}

// Получить состояние
bool TimerLite::get() {
	return _getState(this->_cooldown);
}
bool TimerLite::get(uint32_t& cooldown) {
	return _getState(cooldown);
}

// Получить состояние (приватный метод)
bool TimerLite::_getState(const uint32_t& cooldown) {
	if (millis() - this->_time >= cooldown) {
		clear();
		return true;
	}
	return false;
}

// Установка задержки
void TimerLite::setCooldown(uint32_t cooldown) {
	this->_cooldown = cooldown;
}

// Обнуление задержки
void Timer::clear() {
	this->_time = millis();

}
