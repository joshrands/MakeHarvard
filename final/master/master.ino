/* master takes accelerometer data and IR Receiver data
and sends it through a serial port to the PC */

#include <Wire.h>
#include <SparkFun_MMA8452Q.h>
#include <IRremote.h>

// accelerometer config
MMA8452Q accel;
double controlVal = 0.2;

// ir config
int currentPin = 2;
const int MIN_PIN = 2;
const int MAX_PIN = 10;

int BUTTON_PIN = 13;

int ticks = 0;

IRrecv irrecv(currentPin);

void accelSetup()
{
  // Accelerometer Data
  //Serial.println("Enabling accelerometer");
  accel.init(SCALE_8G);
  //Serial.println("Enabled accelerometer");
}

void irSetup()
{
  //Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  //Serial.println("Enabled IRin");
}

/*
void sync()
{
  pinMode(BUTTON_PIN, INPUT);

  while (digitalRead(BUTTON_PIN) == LOW)
  {
    //Serial.println("Press button to sync...");
    delay(10);
  }
}
*/

void setup() {
  Serial.begin(9600);
  //Serial.println("Test");

  accelSetup();
  irSetup();
  //sync();
}

void checkAccel()
{
  // First, use accel.read() to read the new variables:
  accel.read();

  /*
  if (accel.cx > controlVal) {
    //Move forward 
    Serial.print("forward ");
  }
  else if (accel.cx < (-1 * controlVal)) {
    //Move backward
    Serial.print("back ");
  }
  */
  
  if (accel.cz > controlVal) 
  {
    // Move left
    Serial.print("A_L\n");
  }
  else if (accel.cz < (-1 * controlVal)) 
  {
    // Move right
    Serial.print("A_R\n");
  }
  else
  {
    Serial.print("A_0\n");
  }
}

void checkIR()
{
  // move to next pin
  currentPin++;
  if (currentPin == MAX_PIN)
  {
    ticks++;
    currentPin = MAX_PIN - 1;
    // wait however many steps
    if (ticks >= 8)
    {
      ticks = 0;
      currentPin = MIN_PIN - 1;
    }
  }
  else
  {  
    // set the current IR receiver in question
    irrecv.setPort(currentPin);
  
    decode_results results;
  
    Serial.print("IR"); // tell ground station this is IR data
  
    // adjust pin for delay
    if (currentPin == MIN_PIN)
      Serial.print(MAX_PIN - 1);
    else
      Serial.print(currentPin - 1);
  
    Serial.print("_");  
    
    if (irrecv.decode(&results)) {
      Serial.print("1\n");
      // we don't care about the value. Serial.println(results.value, HEX);
      irrecv.resume(); // Receive the next value
    }
    else
    {
      Serial.print("0\n");
    }
  }
  //delay(125); // wait 1/8 sec
}

void loop() 
{
  checkAccel();
  checkIR();
  delay(125);
}
