/* Get IR Data from brain */
/* MakeHarvard 2019 */
#include <IRremote.h>

const int NUM_RECVS = 8;

int REC_PINS[] = {6, 7, 8, 9, 10, 11, 12, 13}; // 8 receivers

IRrecv irrecvs[] = {IRrecv(6), IRrecv(7), IRrecv(8), IRrecv(9), IRrecv(10), IRrecv(11), IRrecv(12), IRrecv(13)};

int count = 0;

void setup()   
{     
  Serial.begin(9600);

  for (int i = 0; i < NUM_RECVS; i++)
  {
    //irrecvs[i] = IRrecv(REC_PINS[i]);
    irrecvs[i].enableIRIn();
  }

  //irrecv.enableIRIn();
  
  Serial.println("Collecting data...");   
}

void loop()                    
{  
  decode_results results;

  
  
  /*
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
  */
  for (int j = 0; j < NUM_RECVS; j++)
  {
    //Serial.print("Receiver: ");
    //Serial.println(REC_PINS[j]);
    decode_results results;
    if (irrecvs[j].decode(&results))
    {
      Serial.print("Pin ");
      Serial.print(REC_PINS[j]);
      Serial.print(" received a signal: ");
      Serial.println(results.value, HEX);
      irrecvs[j].resume();              // Prepare for the next value
    }
    delay(100);
  }
  
}
