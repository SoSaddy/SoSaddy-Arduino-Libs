#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

// Константы модификаторов
const uint8_t AS_SWITCH = 0;
const uint8_t AS_TRIGGER = 1;

class Timer {

	public:

		// === Конструктор ===
		Timer(uint32_t cooldown = 1000, uint8_t mode = AS_TRIGGER);

		// === Методы ===

		// Получить результат срабатывания
		bool get();
		bool get(uint32_t& cooldown);
		bool get(uint32_t* pattern, size_t size);

		// Установить задержку
		void setCooldown(uint32_t cooldown);

		// Установить модификатор срабатывания
		void setMode(uint8_t mode);

		// Обнулить задержку
		void clear();

	private:

		// Время и задржка
		uint32_t _time;
		uint32_t _cooldown;

		// Текущий модификатор
		uint8_t _mode;

		// Состояние для модификатора AS_SWITCH
		bool _switched = false;

		// Паттерны
		uint8_t _pattern_index = 0;

		// === Методы ===

		// Получить состояние
		bool _getState(const uint32_t& cooldown);

		// Циклический диапазон
		uint8_t _rangeLoop(uint8_t& value, uint8_t x, uint8_t y) {
			if (value < x) {
				return y;
			} else if (value > y) {
				return x;
			}
			return value;
		}

};

#endif