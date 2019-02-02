#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  irrecv.enableIRIn();  // start the receiver

  pinMode(RECV_PIN, INPUT);
  Serial.println("Beginning test...");
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Test");    
  if (irrecv.decode(&results))
  {
    Serial.println("IR RECV Code = 0x");
    Serial.println(results.value, HEX);
    irrecv.resume();
  } 
}
