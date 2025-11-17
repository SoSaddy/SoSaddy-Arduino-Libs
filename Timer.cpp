#include "Timer.h"

// Конструктор
Timer::Timer(uint32_t cooldown, uint8_t mode) {
	this->_time = millis();
	this->_cooldown = cooldown;
	this->_mode = mode;
}

// Получить состояние
bool Timer::get() {
	return _getState(this->_cooldown);
}
bool Timer::get(uint32_t& cooldown) {
	return _getState(cooldown);
}
bool Timer::get(uint32_t* pattern, size_t size) {
	if (size == 0) return false;
	bool state = (millis() - this->_time >= pattern[this->_pattern_index]);
	if (this->_mode == AS_TRIGGER) {
		if (state) {
			this->_time = millis();
			this->_pattern_index++;
			this->_pattern_index = _rangeLoop(this->_pattern_index, 0, size - 1);
		}
		return state;
	} else if (this->_mode == AS_SWITCH) {
		if (state) {
			this->_switched = !this->_switched;
			this->_time = millis();
			if (!this->_switched) {
				this->_pattern_index++;
				this->_pattern_index = _rangeLoop(this->_pattern_index, 0, size - 1);
			}
		}
		return this->_switched;
	}
	return false;
}

// Получить состояние (приватный метод)
bool Timer::_getState(const uint32_t& cooldown) {
	bool state = (millis() - this->_time >= cooldown);
	if (this->_mode == AS_TRIGGER) {
		if (state) {
			this->_time = millis();
		}
		return state;
	} else if (this->_mode == AS_SWITCH) {
		if (state) {
			this->_switched = !this->_switched;
			this->_time = millis();
		}
		return this->_switched;
	}
	return false;
}

// Установка задержки
void Timer::setCooldown(uint32_t cooldown) {
	this->_cooldown = cooldown;
}

// Установка модификатора
void Timer::setMode(uint8_t mode) {
	this->_mode = mode;
}

// Обнуление задержки
void Timer::clear() {
	this->_time = millis();
}