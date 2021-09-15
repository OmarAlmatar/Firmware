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

<<<<<<< HEAD
void TC3_Handler()
{
  TC_GetStatus(TC1, 0); // accept interrupt
  DACC->DACC_CDR = LUT[cycle];  // Start the next DAC conversion
  cycle++; //frequency is determined by FS * cycle_increment / 2048
=======
  while(!interruptFlag) //do nothing until interrupt
  {
    digitalWrite(13, 1); //best practice to do some NOOP task inside empty loop to avoid errors
  }
  
  if(cycle > 2047) //to prevent overflow, reset the cycle counter
  {
    cycle = 0;
  }
  
/* UNCOMMENT THIS CODE TO TEST NCO DIGITALLY
  test (justin)
  Serial.println(LUT[cycle]);
*/

  DacSample = LUT[cycle]; // push into DAC
  DACC->DACC_CDR = DacSample;  // Start the next DAC conversion
  cycle = cycle + cycle_incr; // increment cycle counter to fetch next value in LUT, the higher the increment value is, the higher the sine wave frequency

  interruptFlag = false; // wait for next interrupt
>>>>>>> 63cfe528ac0e1aea4ccf74c83d07ec6c98715a8f
}