int sensePin=0;//analog input A0
int m1=5;//PWM pin 5
int m2=6;//PWN pin 6
void setup() {
  // declaring pins
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  
  Serial.begin(9600);//begining serial connection
}

void loop() {
  // put your main code here, to run repeatedly:
  int val=analogRead(sensePin);
  
  delay(100);//giving time to analog reders
  
  //sonstraining val to give correct output
  val=constrain(val,320,820);
  Serial.println(val);
  
  //mapping motor speed
  int mspeed=map(val,320,820,0,255);
  //setting up unidirectional rotation
  analogWrite(m2,0);
  analogWrite(m1,mspeed);
  
  delay(100);//giving time to read serial data
}
