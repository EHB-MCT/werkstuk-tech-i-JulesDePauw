int LED1 = 10;
int LED2 = 9;
int LED3 = 6;
int Clock;
int brightness= 0;
int fadeAmount= 1;
int count=0;

void setup() {
  // put your setup code here, to run once:
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(LED1,count);
analogWrite(LED2,count-255);
analogWrite(LED3,count-500);


count=count+1;
}
