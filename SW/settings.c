
#include "stm32f0xx_hal.h"              // Keil.Standalone::Device:STM32Cube HAL:COMMON
#include "main.h" 
#include "leds.h"
#include "settings.h"

settings_t  settings;

/** Init settings */
void Init_Settings(void) {
	settings.enabled = 0x03ff; // enable all 10 channels
	settings.mode = MODE_NORMAL;
}


/** Check settings */
void CheckSettings(void) {
	int i;
	uint16_t numleds = 0;
	uint16_t numselects = 0;	
	uint16_t enabled = 0;  
	GPIO_InitTypeDef	HBGPIO_InitStruct = {0};
	
	/** Set HB pin to input */
  HBGPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  HBGPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HBGPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HBGPIO_InitStruct.Pin = HB_Pin;
	HAL_GPIO_Init(HB_GPIO_Port, &HBGPIO_InitStruct);
	HAL_GPIO_WritePin(HB_GPIO_Port, HB_Pin, GPIO_PIN_RESET);
  
	/** check jumper settings 
	    skip first (only one wire) and last (all 10 wires) */
	for (i=1; i<=10; i++) {  
		Main_Led(i);
	  if (HAL_GPIO_ReadPin(HB_GPIO_Port, HB_Pin) == GPIO_PIN_SET) {
			if (numleds == 0) numleds = i;
			numselects++;
			enabled |= (1 << (i-1));
		}
	}
  // check settings
	if (numleds == 0) {		// all leds enabled
		settings.enabled = 0x03ff;
	} else {
		if (numselects == 1) {  // enable only first numleds
			enabled = 0xffff;
			enabled <<= numleds;
			settings.enabled = ~enabled;
			} else {
				settings.enabled = 0x03ff & (~enabled);
			}
	}
	
	settings.mode = (HAL_GPIO_ReadPin(SET1_GPIO_Port, SET1_Pin) == GPIO_PIN_SET) ? 1 : 0;
	
	/** return to normal operation with all leds off */
	LED_Init();
}


int LED_Enabled (uint16_t num) {
	return (settings.enabled & (1U<<(num-1)));
}
