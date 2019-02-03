#include <IRremote.h>

const int NUM_LEDS = 3;
int LED_PINS[NUM_LEDS] = {4, 5, 6}; // 3 IR LEDS
int SYNC_PIN = 2;

const long PULSE_TIME = 1000000;
const unsigned int INTER_PULSE = 1000;

int count = 0;

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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // initialize the IR pins as outputs
  for (int i = 0; i < NUM_LEDS; i++)
  {
    pinMode(LED_PINS[i], OUTPUT);
    //digitalWrite(LED_PINS[i], HIGH);
  }
  pinMode(SYNC_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Pulsing LED: ");
  Serial.println(LED_PINS[count]);

  if (count == 0)
  {
    Serial.println("Sync active");
    digitalWrite(SYNC_PIN, HIGH);
  }

  long microsecs = PULSE_TIME;
  Serial.println(microsecs);
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
    digitalWrite(LED_PINS[count], HIGH);  // this takes about 3 microseconds to happen
    delayMicroseconds(10);         // hang out for 10 microseconds
    digitalWrite(LED_PINS[count], LOW);   // this also takes about 3 microseconds
    delayMicroseconds(10);         // hang out for 10 microseconds
    
    // so 26 microseconds altogether
    microsecs -= 26;
  }
  //pulseIR(PULSE_TIME, LED_PINS[count]);
  if (count == 0)
  {
    Serial.println("Sync deactivated.");
    digitalWrite(SYNC_PIN, LOW);
  }

  count++;
  if (count == NUM_LEDS)
    count = 0;

  delay(INTER_PULSE); // wait 1 second between pulses
}
