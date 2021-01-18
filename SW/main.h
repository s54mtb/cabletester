/**
  ******************************************************************************
  * @file    Templates/Inc/main.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_hal.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

#define MA1_Pin GPIO_PIN_0
#define MA1_GPIO_Port GPIOF

#define MA2_Pin GPIO_PIN_0
#define MA2_GPIO_Port GPIOA

#define MA3_Pin GPIO_PIN_1
#define MA3_GPIO_Port GPIOA

#define MA4_Pin GPIO_PIN_2
#define MA4_GPIO_Port GPIOA

#define MA5_Pin GPIO_PIN_3
#define MA5_GPIO_Port GPIOA

#define MA6_Pin GPIO_PIN_4
#define MA6_GPIO_Port GPIOA

#define MA7_Pin GPIO_PIN_1
#define MA7_GPIO_Port GPIOB

#define MA8_Pin GPIO_PIN_7
#define MA8_GPIO_Port GPIOA

#define MA9_Pin GPIO_PIN_6
#define MA9_GPIO_Port GPIOA

#define MA10_Pin GPIO_PIN_5
#define MA10_GPIO_Port GPIOA

#define HB_Pin GPIO_PIN_1
#define HB_GPIO_Port GPIOF

#define SET1_Pin GPIO_PIN_9
#define SET1_GPIO_Port GPIOA

#define SET2_Pin GPIO_PIN_10
#define SET2_GPIO_Port GPIOA



/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
