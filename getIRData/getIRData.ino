/* Get IR Data from brain */
/* MakeHarvard 2019 */
#include <IRremote.h>

int IR_PINS = [3, 4, 5];

int IRledPin =  13;    // LED connected to digital pin 13

// The setup() method runs once, when the sketch starts

void setup()   {               
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);     

  Serial.begin(9600);
}

void loop()                    
{
  SendChannelUpCode();

  delay(1000);//20*1000);  // wait twenty seconds (20 seconds * 1000 milliseconds) Change this value for different intervals.
}

// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait

  cli();  // this turns off any background interrupts

  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds

   // so 26 microseconds altogether
   microsecs -= 26;
  }

  sei();  // this turns them back on
}

void SendChannelUpCode() {
  // This is the code for the CHANNEL + for the TV COMCAST
 
  delayMicroseconds(36328);      //Time off (LEFT column)       
  pulseIR(280);                               //Time on (RIGHT column)    <-------DO NOT MIX THESE UP
  delayMicroseconds(820);
  pulseIR(300);
  delayMicroseconds(1580);
  pulseIR(320);
  delayMicroseconds(640);
  pulseIR(240);
  delayMicroseconds(1280);
  pulseIR(240);
  delayMicroseconds(1240);
  pulseIR(240);
  delayMicroseconds(1120);
  pulseIR(240);
  delayMicroseconds(2600);
  pulseIR(240);
  delayMicroseconds(12740);
  pulseIR(240);
  delayMicroseconds(840);
  pulseIR(240);
  delayMicroseconds(980);
  pulseIR(240);
  delayMicroseconds(700);
  pulseIR(240);
  delayMicroseconds(700);
  pulseIR(240);
  delayMicroseconds(720);
  pulseIR(240);
  delayMicroseconds(2460);
  pulseIR(240);
  delayMicroseconds(700);
  pulseIR(240);
  delayMicroseconds(700);
  pulseIR(240);
  delayMicroseconds(14904);
  pulseIR(240);
  delayMicroseconds(820);
  pulseIR(240);
  delayMicroseconds(1600);
  pulseIR(240);
  delayMicroseconds(700);
  pulseIR(260);
  delayMicroseconds(2740);
  pulseIR(240);
  delayMicroseconds(1240);
  pulseIR(240);
  delayMicroseconds(1260);
  pulseIR(240);
  delayMicroseconds(1100);
  pulseIR(240);
  delayMicroseconds(2620);
  pulseIR(240);
  delayMicroseconds(12720);
  pulseIR(260);
  delayMicroseconds(840);
  pulseIR(220);
  delayMicroseconds(2080);
  pulseIR(240);
  delayMicroseconds(1780);
  pulseIR(260);
  delayMicroseconds(700);
  pulseIR(240);
  delayMicroseconds(700);
  pulseIR(240);
  delayMicroseconds(2480);
  pulseIR(240);
  delayMicroseconds(700);
  pulseIR(240);
  delayMicroseconds(700);
  pulseIR(240);
}
