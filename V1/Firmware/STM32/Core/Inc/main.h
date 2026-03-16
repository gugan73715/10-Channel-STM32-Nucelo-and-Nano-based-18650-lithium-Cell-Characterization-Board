/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LCD_D5_Pin GPIO_PIN_0
#define LCD_D5_GPIO_Port GPIOF
#define LCD_D6_Pin GPIO_PIN_1
#define LCD_D6_GPIO_Port GPIOF
#define V_Cell_Pin GPIO_PIN_0
#define V_Cell_GPIO_Port GPIOA
#define LCD_E_Pin GPIO_PIN_1
#define LCD_E_GPIO_Port GPIOA
#define NTC_Pin GPIO_PIN_2
#define NTC_GPIO_Port GPIOA
#define LCD_RS_Pin GPIO_PIN_3
#define LCD_RS_GPIO_Port GPIOA
#define LCD_D7_Pin GPIO_PIN_4
#define LCD_D7_GPIO_Port GPIOA
#define SDA_Pin GPIO_PIN_5
#define SDA_GPIO_Port GPIOA
#define SCL_Pin GPIO_PIN_6
#define SCL_GPIO_Port GPIOA
#define I_Sense_Pin GPIO_PIN_7
#define I_Sense_GPIO_Port GPIOA
#define MUX_ADR1_Pin GPIO_PIN_0
#define MUX_ADR1_GPIO_Port GPIOB
#define SPI_CS_Pin GPIO_PIN_8
#define SPI_CS_GPIO_Port GPIOA
#define MicroSD_CS_Pin GPIO_PIN_11
#define MicroSD_CS_GPIO_Port GPIOA
#define MUX_ADR0_Pin GPIO_PIN_12
#define MUX_ADR0_GPIO_Port GPIOA
#define MUX_ADR3_Pin GPIO_PIN_15
#define MUX_ADR3_GPIO_Port GPIOA
#define LCD_D4_Pin GPIO_PIN_6
#define LCD_D4_GPIO_Port GPIOB
#define MUX_ADR2_Pin GPIO_PIN_7
#define MUX_ADR2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
