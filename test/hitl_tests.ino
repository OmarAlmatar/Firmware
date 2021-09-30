#include "../inc/nco.h"
#include "../inc/rms.h"
#include "../inc/pot.h"

#define FS 44100

void setup() {
  Serial.begin(9600);
}

void loop() {
  
}


/* Potentiometer Test
Intantiate all relay potentiometers and cycle through different values
*/
void test_pots() {
  POT p1;       //object instantiated from class POT
  p1.set_CCW();
  
  p1.set_MID();
  
  p1.set_CW();

  Serial.print("Pot Test Complete");
}
