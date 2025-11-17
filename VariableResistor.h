#ifndef VR_H
#define VR_H

#include <Arduino.h>

class VariableResistor {

	public:

		// === Конструктор ===
		VariableResistor(uint8_t pin = 0);

		// === Методы ===

		// Взять значение
		int get();
		int getMapped(int fromLow, int fromHigh, int toLow, int toHigh);
		uint8_t getPercent();

		// Границы
		void setBounds(int lower, int upper);
		void setLower(int lower);
		void setUpper(int upper);
		int getLower();
		int getUpper();

		// Калибровка
		void calibrate();
		void resetCalibration();

		// Установить пин
		void setPin(uint8_t pin);

	private:
		uint8_t _pin;

		// Главные параметры
		int _value;

		// Калибровочные параметры
		int _lower, _upper;
		int _lower_min, _upper_max;

};

#endif