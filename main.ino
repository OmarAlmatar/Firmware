#include "inc/nco.h"
#include "inc/rms.h"

void setup() {
  
  Serial.begin(9600);
  nco::DAC_Setup();
  nco::startTimer(TC1, 0, TC3_IRQn, FS); // TC1 channel 0, the IRQ for that channel and the desired frequency
}

void loop() {

  while(!interruptFlag) //do nothing until interrupt
  {
    digitalWrite(13, 1); //best practice to do some NOOP task inside empty loop to avoid errors
  }
  
  while(cycle > 2047) //to prevent overflow, reset the cycle counter <- previously if(cycle > 2047){ reset cycle }. Uusing empty while loop to cut off waveform to test results
  {
    digitalWrite(13, 0); //best practice to do some NOOP task inside empty loop to avoid errors
  }
  
/* UNCOMMENT THIS CODE TO TEST NCO DIGITALLY
  test (justin)
  Serial.println(LUT[cycle]);
*/

  DacSample = LUT[cycle]; // push into DAC
  DACC->DACC_CDR = DacSample;  // Start the next DAC conversion
  cycle++; // increment cycle counter to fetch next value in LUT, the higher the increment value is, the higher the sine wave frequency, counter is incremented by its initial value, for example, iteration1: 2, iteration2: 2+2, iteration3: 4+2, etc.

  interruptFlag = false; // wait for next interrupt
}