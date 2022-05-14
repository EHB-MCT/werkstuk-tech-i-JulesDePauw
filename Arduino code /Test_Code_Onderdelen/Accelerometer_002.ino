/**************************************************************************/
/*!
    @file     Adafruit_MMA8451.h
    @author   K. Townsend (Adafruit Industries)
    @license  BSD (see license.txt)

    This is an example for the Adafruit MMA8451 Accel breakout board
    ----> https://www.adafruit.com/products/2019

    Adafruit invests time and resources providing this open source code,
    please support Adafruit and open-source hardware by purchasing
    products from Adafruit!

    @section  HISTORY

    v1.0  - First release
*/
/**************************************************************************/
int count=0;
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();

int lastX = 0;
int lastY = 0;
int lastZ = 0;

void setup(void) {
  Serial.begin(9600);
  
  Serial.println("Adafruit MMA8451 test!");
  

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");
  
}

void loop() {
  // Read the 'raw' data in 14-bit counts
  mma.read();
//  Serial.print("X:\t"); Serial.print(mma.x); 
//  Serial.print("\tY:\t"); Serial.print(mma.y); 
//
//  Serial.println();


  int deltaX = abs(mma.x - lastX);
  int deltaY = abs(mma.y - lastY);
  int deltaZ = abs(mma.z - lastZ);

  Serial.print("deltamove: ");
  Serial.print((deltaX + deltaY+deltaZ) / 3);
  Serial.println(deltaY);

  
  if ((deltaX+deltaY+deltaZ)/3< 500){
  count=count +1;
} else {count=count-1;}
 
 


  lastX = mma.x;
  lastY = mma.y;

  Serial.print(count);
 

  delay(500);

// delta =  ThisReading - LastReading ;


 }

  


 
