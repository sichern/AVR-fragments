
/**
 * Модуль чтения/записи в EEPROM
 * Created: 11.03.2024
 * Author: schern
*/

#include "eeprom.h"

// Функция записи байта в eeprom
void EEPROM_write(unsigned int addr, unsigned char data)
{
	// Ожидание окончания предыдущей записи
	while(EECR & (1<<EEWE));
	// Указание адреса и данных
	EEAR = addr;
	EEDR = data;
	// Запись 1 в EEMWE
	EECR |= (1<<EEMWE);
	// Запуск записи путем установки EEWE
	EECR |= (1<<EEWE);
}//end void EEPROM_write

// Функция чтения байта из eeprom
unsigned char EEPROM_read(unsigned int addr)
{
	// Ожидание завершения предыдущей записи
	while(EECR & (1<<EEWE));
	// Установка адресного регистра
	EEAR = addr;
	// Разрешение чтения из EEPROM путем установки EERE
	EECR |= (1<<EERE);
	// Возврат данных из регистра данных EEPROM
	return EEDR;
}//end unsigned char EEPROM_read
