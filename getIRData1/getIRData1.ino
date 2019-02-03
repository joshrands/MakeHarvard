/* Get IR Data from brain */
/* MakeHarvard 2019 */
#include <IRremote.h>
#include <jm_Scheduler.h>

const int NUM_LEDS = 3;
const int NUM_RECVS = 8;

int LED_PINS[] = {2, 3, 4}; // 3 IR LEDS
int REC_PINS[] = {6, 7, 8, 9, 10, 11, 12, 13}; // 8 receivers

IRrecv irrecv(11);

IRrecv irrecvs[] = {IRrecv(6), IRrecv(7), IRrecv(8), IRrecv(9), IRrecv(10), IRrecv(11), IRrecv(12), IRrecv(13)};

int cnt = 0;

jm_Scheduler scheduler;

void sendIRSignal()
{
  //Serial.print("Pulsing LED: ");
  //Serial.println(LED_PINS[cnt]);
  pulseIR(100000, LED_PINS[cnt]);

  cnt++;
  if (cnt == NUM_LEDS)
    cnt = 0;
}

void recSignal()
{
  decode_results results;
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  //delay(10);
}

/*void recSignal()
{
  Serial.print("Test");
  
  decode_results results;
  
  for (int j = 0; j < NUM_RECVS; j++)
  {
    Serial.print("Receiver: ");
    Serial.println(REC_PINS[j]);
    if (irrecvs[j].decode(&results))
    {
      Serial.println("RECEIVED DATA");
      Serial.println(results.bits, DEC);
      /*dumpInfo(&results);           // Output the results
      dumpRaw(&results);            // Output the results in RAW format
      dumpCode(&results);           // Output the results as source code
      Serial.println("");           // Blank line between entries
      irrecvs[j].resume();              // Prepare for the next value
    }
  }
}*/

void setup()   {     
  Serial.begin(9600);
  irrecv.enableIRIn();
            
  // initialize the IR pins as outputs
  for (int i = 0; i < NUM_LEDS; i++)
  {
    pinMode(LED_PINS[i], OUTPUT);
  }

  for (int i = 0; i < NUM_RECVS; i++)
  {
    //irrecvs[i] = IRrecv(REC_PINS[i]);
    irrecvs[i].enableIRIn();
  }

  Serial.println("Collecting data...");   

  //scheduler.start(sendIRSignal, TIMESTAMP_1MS*100);
  //Serial.println("Test2");
  //scheduler.start(recSignal, TIMESTAMP_1MS*10);
  
  //digitalWrite(LED_PINS[0], HIGH);  // this takes about 3 microseconds to happen
}

// This procedure sends a 38KHz pulse to the IRledPin
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs, int IRledPin) {
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

void loop()                    
{  
  yield();
  
  //Serial.println("Test3");
  recSignal();
  pulseIR(100000, LED_PINS[cnt]);
  recSignal();

  cnt++;
  if (cnt == NUM_LEDS)
    cnt = 0;
}
  

  /*
  for (int i = 0; i < NUM_RECVS; i++)
  {
    Serial.print("Receiver: ");
    Serial.println(REC_PINS[i]);
    if (irrecvs[i].decode(&results))
    {
      Serial.println("RECEIVED DATA");
      Serial.println(results.bits, DEC);
      /*dumpInfo(&results);           // Output the results
      dumpRaw(&results);            // Output the results in RAW format
      dumpCode(&results);           // Output the results as source code
      Serial.println("");           // Blank line between entries
      irrecvs[i].resume();              // Prepare for the next value
    }
  }
*/
  //delay(10);//20*1000);  // wait twenty seconds (20 seconds * 1000 milliseconds) Change this value for different intervals.


/*
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
}*/
