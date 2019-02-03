/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int currentPin = 2;
const int MIN_PIN = 2;
const int MAX_PIN = 11;

IRrecv irrecv(currentPin);

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  //Serial.print("Trying Port ");
  //Serial.println(currentPin);
  irrecv.setPort(currentPin);
  //irrecv.enableIRIn();
  //irrecv.resume();
  decode_results results;
  
  if (irrecv.decode(&results)) {
    Serial.print("Port ");
    if (currentPin == MIN_PIN)
      Serial.print(MAX_PIN - 1);
    else
      Serial.print(currentPin - 1);
      
    Serial.println(" success");
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    //irrecv2.resume();
  }

  currentPin++;
  if (currentPin == MAX_PIN)
    currentPin = MIN_PIN;

  delay(200);
}
