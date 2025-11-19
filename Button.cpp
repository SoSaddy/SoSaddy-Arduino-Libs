#include <Button.h>

// Конструктор
Button::Button(uint8_t pin, bool toggle, uint8_t dd) {
	reset();
	setPin(pin);
	setToggleMode(toggle);
	setDebounceDelay(dd);
};

// Очистка всех параметров
void Button::reset() {
    this->_toggle_flag = false;
    this->_flag = false;
    this->_state_prev = false;
    this->_state_stable = false;
    setDebounceDelay(DEBOUNCE_DELAY_DEFAULT);
    this->_time_prev = millis();
}

// Зажатие
bool Button::isCheck() {
	bool state = (digitalRead(_pin) == LOW);
	uint32_t time = millis();
	if (state != this->_state_prev) {
		this->_time_prev = time;
	}
	if ((time - this->_time_prev) > this->_debounce_delay) {
		if (state != this->_flag) {
			this->_flag = state;
		}
	}
	this->_state_prev = state;
	return _flag;
};

// Разовое срабатывание по зажатию
bool Button::isReleased() {
	bool state = isCheck();
	bool released = (!state && this->_state_stable);
	this->_state_stable = state;
	if (this->_toggle) {
		if (released) this->_toggle_flag = !this->_toggle_flag;
		return this->_toggle_flag;
	} else return released;
};

// Разовое срабатывание по отжатию
bool Button::isPressed() {
	bool state = isCheck();
	bool pressed = (state && !this->_state_stable);
	this->_state_stable = state;
	if (this->_toggle) {
		if (pressed) this->_toggle_flag = !this->_toggle_flag;
		return this->_toggle_flag;
	} else return pressed;
};

// Установить пин
void Button::setPin(uint8_t pin) {
	this->_pin = pin;
	pinMode(pin, INPUT_PULLUP);
};

// Установить режим переключения
void Button::setToggleMode(bool toggle) {
	this->_toggle = toggle;
	if (!toggle) this->_toggle_flag = false;
};

// Получить переключённое состояние
bool Button::getToggled() {
	return this->_toggle_flag;
};

// Защитная здержка от дребезга
void Button::setDebounceDelay(uint8_t debounce_delay) {
	this->_debounce_delay = debounce_delay;
};