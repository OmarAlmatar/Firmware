#include "../inc/pot.h"

// Writes to digital outputs to control potentiometer relays
void POT::set_CCW(){
    digitalWrite(CCW, );
    digitalWrite(MID, );
    digitalWrite(CW, );
    state = "CCW";
}

void POT::set_MID(){
    state = "MID";
}

void POT::set_CW(){
    state = "CW";
}