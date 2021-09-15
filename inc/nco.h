#ifndef NCO_H_INCLUDED
#define NCO_H_INCLUDED

#define FC 44100
class NCO {
    private:
        int LUT[2048];
        float frequency, amplitude;             //frequency and amplitude of NCO
        Tc *tc;
        uint32_t tc_channel;
        IRQn_Type irq;
        void Timer_Setup();
        void DAC_Setup();
    public:
        NCO(float frequency, float amplitude, Tc *tc, uint32_t tc_channel);
        void setFrequency(int counterincrement);
        void setAmplitude(int counterincrement);
        float getFrequency();
        float getAmplitude();
        void startNCO();                        //starts the NCO oscillations
        void stopNCO();                         //stops the NCO oscillations
};

#endif