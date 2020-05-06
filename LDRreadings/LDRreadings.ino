int sensePin=0;
int sensePin2=1;
void setup() {
  // put your setup code here, to run once:
 
  analogReference(DEFAULT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(analogRead(sensePin));
  //delay(1000);

  Serial.println(analogRead(sensePin2));
  delay(1000);
}
