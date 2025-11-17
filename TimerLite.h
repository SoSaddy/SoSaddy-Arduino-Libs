#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer {

	public:

		// === Конструктор ===
		Timer(uint32_t cooldown = 1000);

		// === Методы ===

		// Получить результат срабатывания
		bool get();
		bool get(uint32_t& cooldown);

		// Установить задержку
		void setCooldown(uint32_t cooldown);

		// Обнулить задержку
		void clear();

	private:

		// Время и задржка
		uint32_t _time;
		uint32_t _cooldown;

		// === Методы ===

		// Получить состояние
		bool _getState(const uint32_t& cooldown);

};

#endif