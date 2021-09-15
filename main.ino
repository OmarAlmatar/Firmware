#include "inc/nco.h"
#include "inc/rms.h"

#define FS 44100

uint32_t  DacSample;
unsigned int cycle = 0; // this counter determines the frequency of the waveform, user inputs desired frequency value and it is multiplexed into a positive integer

void setup() {
  Serial.begin(9600);
  nco::DAC_Setup();
  nco::startTimer(TC1, 0, TC3_IRQn, FS); // TC1 channel 0, the IRQ for that channel and the desired frequency
}

void loop() {
;
}

void TC3_Handler()
{
  TC_GetStatus(TC1, 0); // accept interrupt
  DACC->DACC_CDR = LUT[cycle];  // Start the next DAC conversion
  cycle++; //frequency is determined by FS * cycle_increment / 2048
}