#include <Arduino.h>
// Pin Defintions
#define UART_RX 0
#define UART_TX 1
#define MUX_ADR0 2
#define MUX_ADR1 3
#define MUX_ADR2 4
#define MUX_ADR3 5
#define LCD_D4 6
#define LCD_D5 7
#define LCD_D6 8
#define SPI_CS 9
#define MicroSD_CS 10
#define SPI_MOSI 11
#define SPI_MISO 12
#define SPI_SCK 13
#define V_CELL_SENSE A0
#define LED_E A1
#define LED_RS A2
#define LED_D7 A3
#define I2C_SDA A4
#define I2C_SCL A5
#define I_SENSE A6
#define NTC A7

//Function Prototypes

Void GPIO_Init();
