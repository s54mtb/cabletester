

#ifndef __LEDS_H__
#define __LEDS_H__

void LED_Init(void);
void HB_LED(GPIO_PinState state);
void Main_Led(uint8_t num);
void BlinkHB(uint32_t pulse);
int LED_Enabled (uint16_t num);

#endif

