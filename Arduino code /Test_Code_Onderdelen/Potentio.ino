int POT=17;
int readVal;
float sens;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readVal=analogRead(POT);
sens=(200./1023.)*readVal+18;
Serial.println(sens);
delay(100);
}
