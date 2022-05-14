

/**************************************************************************/
//LEDS
/*****************  NEEDED TO MAKE NODEMCU WORK ***************************/
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ESP8266_RAW_PIN_ORDER

int count=0;
int light1=0;
int light2=0;
int light3=0;
int light4=0;
int light5=0;
int light6=0;
int light7=0;
int light8=0;
int i;

//Draaiknop
int POT=17;
int readVal;
float sens;

/******************  LIBRARY SECTION *************************************/
#include <FastLED.h>
/*****************  LED LAYOUT AND SETUP *********************************/
#define NUM_LEDS 43
/*****************  DECLARATIONS  ****************************************/
CRGB leds[NUM_LEDS];
/*****************  GLOBAL VARIABLES  ************************************/
const int ledPin = 12; 
/*****************  SETUP FUNCTIONS  ****************************************/
//ACCELEROMETER
#include <Wire.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>

Adafruit_MMA8451 mma = Adafruit_MMA8451();

int lastX = 0;
int lastY = 0;
int lastZ = 0;

//STARTKnop
int Start=0;
int btnLED= 10;
int btn= 11;
int btnNew;
int btnOld;
int dt=100;

void setup(void) {
  Serial.begin(9600);
  
  Serial.println("Adafruit MMA8451 test!");
  
  FastLED.addLeds<WS2812B, ledPin, RGB>(leds, NUM_LEDS);

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_2_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");




//STARTKnop
Serial.begin(9600);
pinMode(btnLED,OUTPUT);
pinMode(btn,INPUT);


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

// Serial.print("deltamove: ");
// Serial.print((deltaX + deltaY+deltaZ) / 3);
// Serial.println(deltaY);
//Gevoeligheid
readVal=analogRead(POT);
sens=(300./1023.)*readVal+18;
Serial.println(sens);



//STARTKNOP
btnNew=digitalRead(btn);
if(btnOld==0 && btnNew==1){
if (Start==0){
  digitalWrite(btnLED,HIGH);
Start=1;
}
else{digitalWrite(btnLED,LOW);
Start=0;
}
}
btnOld=btnNew;
//Serial.println(Start);

if (Start==0){

Serial.println((deltaX+deltaY+deltaZ)/3);



 //Motion clock
  if ((deltaX+deltaY+deltaZ)/3< sens){
  count=count +1;
} else {count=count-2;}

 if (count<0){
  count=0;
 }
 if (count>1800){
  count=1800;
 }


  lastX = mma.x;
  lastY = mma.y;

  //Serial.print(count);
 
 

// delta =  ThisReading - LastReading ;
}
else {
  count=0;
 }
 //code Led1
  if (count<0){
  light1=0;
} else {
  light1=count;
}
if (count>200){
  light1=200;
}

//code Led2
 if (count<200){
  light2=0;
} else {
  light2=count-200;
}
if (count>400){
  light2=200;
}

//code Led3
 if (count<600){
  light3=0;
} else {
  light3=count-600;
}
if (count>800){
  light3=200;
}

//code Led4
 if (count<800){
  light4=0;
} else {
  light4=count-800;
}
if (count>1000){
  light4=200;
}

//code Led5
 if (count<1000){
  light5=0;
} else {
  light5=count-1000;
}
if (count>1200){
  light5=1000;
}

//code Led6
 if (count<1200){
  light6=0;
} else {
  light6=count-1200;
}
if (count>1400){
  light6=1200;
}

//code Led7
 if (count<1400){
  light7=0;
} else {
  light7=count-1400;
}
if (count>1600){
  light7=1400;
}

//code Led8
 if (count<1600){
  light8=0;
} else {
  light8=count-1600;
}
if (count>1800){
  light8=1600;
}






 leds[0] = CHSV (85, 200, light1);
  leds[1] = CHSV (96, 200, light2);
  leds[2] = CHSV (64, 200, light3);
  leds[3] = CHSV (0, 200, light4);
  leds[4] = CHSV (160, 150, light5);
  leds[5] = CHSV (130, 200, light6);
  leds[6] = CHSV (200, 200, light7);
  
  for(i=7;i<=NUM_LEDS;i=i+1){
    leds[i] = CHSV (200, 0, light8);
  }
  
  FastLED.show();
//Serial.print(light1);
  delay(10);
}

  



  


 
