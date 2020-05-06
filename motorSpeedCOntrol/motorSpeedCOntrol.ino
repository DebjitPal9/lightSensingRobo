int M1=6;
int M2=5;
void setup() {
  // put your setup code here, to run once:
  pinMode(M1,OUTPUT);
  pinMode(M2,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(M2,0);
  int i;
  for(i=0;i<=255;i++)
  {
    analogWrite(M1,i);
    delay(50);
  }
  delay(500);
  analogWrite(M1,0);
 
  for(i=0;i<=255;i++)
  {
    analogWrite(M2,i);
    delay(50);
  }
   delay(500);
}
