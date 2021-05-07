/*
 * This is the code for AC Dimmer using Arduino Board.

 */


#define triacPulse 10
#define ZVC 2

int x = 0;
void setup() {
  Serial.begin(9600);
  pinMode(ZVC, INPUT_PULLUP);
  pinMode(A0, INPUT);
  pinMode(triacPulse, OUTPUT);

}

void loop() {

  
  { // When the switch is closed
   int y = analogRead(A0);
//    x= map(y,0,1024, 200,7200);

   x= map(y,0,1024, 1,8500);
    
   Serial.println(digitalRead(ZVC));
    attachInterrupt(0, acon, FALLING); // attach Interrupt at PIN2
  }
 
}

void acon()
{
   
  delayMicroseconds(x); // read AD0
  digitalWrite(triacPulse, HIGH);

  
  delayMicroseconds(50);  //delay 50 uSec on output pulse to turn on triac
  digitalWrite(triacPulse, LOW);
  
  
}
//Developed Robot Man OC(SPI)
