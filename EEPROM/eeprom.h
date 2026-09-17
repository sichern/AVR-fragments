
/**
 * eeprom.h
 * Пример для ATMega16.
 * Для другого микроконтроллера нужно подключить соответствующий заголовочный файл <avr\iomxx.h>
 * Created: 11.03.2024
 * Author: schern
 */

#ifndef __EEPROM_H__
#define __EEPROM_H__

#include <avr\io.h>
#include <avr\iom16.h>
#include <avr\eeprom.h>

// Прототипы функций
void EEPROM_write(unsigned int addr, unsigned char data);
unsigned char EEPROM_read(unsigned int addr);

#endif	// __EEPROM_H__
