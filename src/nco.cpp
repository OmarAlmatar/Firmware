#include "../inc/nco.h"

NCO::NCO(float freq, float amp, Tc *_tc, uint32_t _tc_channel, IRQn_Type _irq) :
  tc(_tc), tc_channel(_tc_channel), irq(_irq){
  this->setFrequency(freq);
  this->setAmplitude(amp);
  DAC_Setup();
  Timer_Setup(); 
}
  
void NCO::DAC_Setup() { //TODO: NEED TO PARSE THIS FUNCTION
  PIOB->PIO_PDR |= PIO_PDR_P15 | PIO_PDR_P16;  // Disable GPIO on corresponding pins DAC0 and DAC1
  PMC->PMC_PCER1 |= PMC_PCER1_PID38 ;     // DACC power ON
  DACC->DACC_CR = DACC_CR_SWRST ;         // reset DACC
  DACC->DACC_MR = DACC_MR_REFRESH (1)
                  | DACC_MR_STARTUP_0
                  | DACC_MR_MAXS
                  | DACC_MR_USER_SEL_CHANNEL1;
  DACC->DACC_CHER =  DACC_CHER_CH1;      // enable DAC channel 1
}

void NCO::Timer_Setup() {
  pmc_set_writeprotect(false);
  pmc_enable_periph_clk((uint32_t)irq);
  TC_Configure(tc, tc_channel, TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK1);
  uint32_t rc = VARIANT_MCK/2/FS; //2 because we selected TIMER_CLOCK1 above
  TC_SetRA(tc, tc_channel, rc/2); //50% high, 50% low
  TC_SetRC(tc, tc_channel, rc);
  tc->TC_CHANNEL[tc_channel].TC_IER=TC_IER_CPCS;
  tc->TC_CHANNEL[tc_channel].TC_IDR=~TC_IER_CPCS;
  NVIC_EnableIRQ(irq);
}

void NCO::setFrequency(float newFrequency) { //TODO: Need to add frequency scaling calculation here
  float calc;
  calc = newFrequency;
  frequency = calc;
}

void NCO::setAmplitude(float newAmplitude) {  //TODO: Need to add amplitude scaling calculation here
  float calc;
  calc = newAmplitude;
  amplitude = calc;
}

float NCO::getFrequency(){

}

float NCO::getAmplitude(){

}

void NCO::startNCO(){
  TC_Start(tc, tc_channel);
}

void NCO::stopNCO() {
  TC_Stop(tc, tc_channel);
}
