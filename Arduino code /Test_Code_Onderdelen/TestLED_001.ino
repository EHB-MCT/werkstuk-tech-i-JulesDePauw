#define LED1 16
#define LED2 15
#define LED3 14

void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(LED1,HIGH);
digitalWrite(LED2,HIGH);
digitalWrite(LED3,HIGH);
}
