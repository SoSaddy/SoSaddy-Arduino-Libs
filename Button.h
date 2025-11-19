#ifndef BUTTON
#define BUTTON

#include <Arduino.h>

const bool TOGGLE = true;
const uint8_t DEBOUNCE_DELAY_DEFAULT = 50;

class Button {

	public:

		// Конструктор
		Button(uint8_t pin = 0, bool toggle = false, uint8_t dd = DEBOUNCE_DELAY_DEFAULT);

		// = = = Методы = = =

		// Очистка всех параметров
		void reset();

		// Зажатие
		bool isCheck();

		// Разовое срабатывание по отжатию (передний фронт)
		bool isReleased();

		// Разовое срабатывание по зажатию (задний фронт)
		bool isPressed();

		// Установить пин
		void setPin(uint8_t pin);

		// Установить режим переключения
		void setToggleMode(bool toggle);

		// Получить переключённое состояние
		bool getToggled();

		// Защитная здержка от дребезга
		void setDebounceDelay(uint8_t debounce_delay);

	private:
		uint8_t _pin;

		bool _toggle;
		bool _toggle_flag;

		bool _flag;
		bool _state_prev;
		bool _state_stable;

		uint32_t _time_prev;
		uint8_t _debounce_delay;

};

#endif