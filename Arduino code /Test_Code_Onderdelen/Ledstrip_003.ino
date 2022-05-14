
   
/*****************  NEEDED TO MAKE NODEMCU WORK ***************************/

#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ESP8266_RAW_PIN_ORDER
int count=0;
int VAL=0
/******************  LIBRARY SECTION *************************************/
#include <FastLED.h>
/*****************  LED LAYOUT AND SETUP *********************************/
#define NUM_LEDS 7

/*****************  DECLARATIONS  ****************************************/
CRGB leds[NUM_LEDS];
/*****************  GLOBAL VARIABLES  ************************************/
const int ledPin = 13; //marked as D2 on the board
/*****************  SETUP FUNCTIONS  ****************************************/
void setup() 
{
  Serial.begin(115200);
  FastLED.addLeds<WS2812B, ledPin, RGB>(leds, NUM_LEDS);
}
/*****************  MAIN LOOP  ****************************************/
void loop() 
{
   leds[0] = CHSV (85, 200, count);
  leds[1] = CHSV (96, 200, count);
  leds[2] = CHSV (64, 200, count);
  leds[3] = CHSV (0, 200, count);
  leds[4] = CHSV (160, 150, count);
  leds[5] = CHSV (130, 200, count);
  leds[6] = CHSV (200, 200, count);
  FastLED.show();
  count=count+1;
delay(30);




}
