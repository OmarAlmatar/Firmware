namespace nco {
    #define FS 44100    
    int LUT[2048];
    void DAC_Setup();
    void TC3_Handler();
    void startTimer(Tc *tc, uint32_t channel, IRQn_Type irq, uint32_t frequency);
}