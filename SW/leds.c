#include "stm32f0xx_hal.h"              // Keil.Standalone::Device:STM32Cube HAL:COMMON
#include "main.h" 
#include "leds.h"

/*
LEDs init 

Leds are placed as follows: 

	CH1  PF0
	CH2  PA0
	CH3  PA1
	CH4  PA2
	CH5  PA3
	CH6  PA4
	CH7  PB1
	CH8  PA7
	CH9  PA6
	CH10 PA5

*/

 GPIO_TypeDef 
	           *chx[10] = { MA1_GPIO_Port, 
                          MA2_GPIO_Port, 
                          MA3_GPIO_Port, 
                          MA4_GPIO_Port, 
                          MA5_GPIO_Port, 
                          MA6_GPIO_Port, 
                          MA7_GPIO_Port, 
                          MA8_GPIO_Port,
                          MA9_GPIO_Port,
                          MA10_GPIO_Port,
						           };
						 
const uint16_t 
	            chp[10] = { MA1_Pin, 
                          MA2_Pin, 
                          MA3_Pin, 
                          MA4_Pin, 
                          MA5_Pin, 
                          MA6_Pin, 
                          MA7_Pin, 
                          MA8_Pin,
                          MA9_Pin,
                          MA10_Pin
							          };


void LED_Init(void) {
	__HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitTypeDef	LEDsGPIO_InitStruct = {0};
	
  LEDsGPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  LEDsGPIO_InitStruct.Pull = GPIO_PULLUP;
  LEDsGPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	
	for (int i=0; i<10; i++) {
		LEDsGPIO_InitStruct.Pin = chp[i];
		HAL_GPIO_Init(chx[i], &LEDsGPIO_InitStruct);
		HAL_GPIO_WritePin(chx[i], chp[i], GPIO_PIN_RESET);
	}
	
	for (int i=0; i<10; i++) {
		LEDsGPIO_InitStruct.Pin = chp[i];
		HAL_GPIO_Init(chx[i], &LEDsGPIO_InitStruct);
		HAL_GPIO_WritePin(chx[i], chp[i], GPIO_PIN_RESET);
	}

	/* HB pin set to input to avoid fantom blinking via setting jumpers */
  LEDsGPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	LEDsGPIO_InitStruct.Pin = HB_Pin;
	HAL_GPIO_Init(HB_GPIO_Port, &LEDsGPIO_InitStruct);
	HAL_GPIO_WritePin(HB_GPIO_Port, HB_Pin, GPIO_PIN_RESET);

}


/** Set all LED pins to input mode */
void LED_AllInputs(void) {
  GPIO_InitTypeDef	LEDsGPIO_InitStruct = {0};
  LEDsGPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	for (int i=0; i<10; i++) {
		LEDsGPIO_InitStruct.Pin = chp[i];
		HAL_GPIO_Init(chx[i], &LEDsGPIO_InitStruct);
		HAL_GPIO_WritePin(chx[i], chp[i], GPIO_PIN_RESET);
	}	
}	



/** Set heartbit LED */
void HB_LED(GPIO_PinState state) {
	HAL_GPIO_WritePin(HB_GPIO_Port, HB_Pin, state);
}

/** set single LED output to 1, other 0
    num: 1...10, other set all to 0
*/
void Main_Led(uint8_t num)	{
  for (int i=0; i<10; i++) {
			HAL_GPIO_WritePin(chx[i], chp[i], GPIO_PIN_RESET);
	}	
	if ((num>0) & (num<11)) {	
		num--;
	  HAL_GPIO_WritePin(chx[num], chp[num], GPIO_PIN_SET);
	}
}


/** Blink HB LED */
void BlinkHB(uint32_t pulse) {
  GPIO_InitTypeDef	LEDsGPIO_InitStruct = {0};
	LED_AllInputs();

  LEDsGPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  LEDsGPIO_InitStruct.Pull = GPIO_PULLUP;
  LEDsGPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	LEDsGPIO_InitStruct.Pin = HB_Pin;
	HAL_GPIO_Init(HB_GPIO_Port, &LEDsGPIO_InitStruct);
	
	HB_LED(GPIO_PIN_SET);
	HAL_Delay(pulse);
	
	
  LED_Init();



}


