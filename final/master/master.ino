/* master takes accelerometer data and IR Receiver data
and sends it through a serial port to the PC */

#include <Wire.h>
#include <SparkFun_MMA8452Q.h>

MMA8452Q accel;
double controlVal = 0.2;

void setup() {
  Serial.begin(9600);
  // Accelerometer Data
  accel.init(SCALE_8G);

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
  
  if (accel.cz > controlVal) {
    // Move left
    Serial.print("A_L\n");
  }
  else if (accel.cz < (-1 * controlVal)) {
    // Move right
    Serial.print("A_R\n");
  }

}

void loop() 
{
  checkAccel();
  delay(125);
}
