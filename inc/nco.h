#ifndef NCO_H_INCLUDED
#define NCO_H_INCLUDED

#define FS 44100
class NCO {
    private:
        float frequency, amplitude;             //frequency and amplitude of NCO
        Tc *tc;
        uint32_t tc_channel;
        IRQn_Type irq;
        void Timer_Setup();
        void DAC_Setup();
    public:
        NCO(float frequency, float amplitude, Tc *tc, uint32_t tc_channel, IRQn_Type irq);
        void setFrequency(float newFrequency);
        void setAmplitude(float newAmplitude);
        float getFrequency();
        float getAmplitude();
        void startNCO();                        //starts the NCO frequency generator
        void stopNCO();                         //stops the NCO frequency generator
};

#endif