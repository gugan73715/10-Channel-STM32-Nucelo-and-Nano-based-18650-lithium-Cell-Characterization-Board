#include "GPIO.h"
#include <arduino.h>

void GPIO_Init() {

  // V_CELL MUX Address Pins
  pinMode(MUX_ADR0, OUTPUT);
  pinMode(MUX_ADR1, OUTPUT);
  pinMode(MUX_ADR2, OUTPUT);
  pinMode(MUX_ADR3, OUTPUT);

  // SPI
  pinMode(SPI_CS, OUTPUT);
  pinMode(MicroSD_CS, OUTPUT);

  // V_CELL
  pinMode(V_CELL_SENSE, INPUT);

  // I_CELL
  pinMode(I_SENSE, INPUT);

  //NTC
  pinMode(NTC, INPUT);

}