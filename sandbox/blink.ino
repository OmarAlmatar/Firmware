int LED = 13; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReadResolution(12);
  analogWriteResolution(12);
  // attachInterrupt()
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(A0));
  delay(1000);
}
