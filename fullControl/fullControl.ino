#include<NewPing.h>
int sensePin2=0;
int sensePin1=1;//
NewPing sonar(3,9,15);//(trigPin,echoPin,maxdistance in cm) ; creating NewPing object
int m1=5;
int m2=6;

int n1=11;
int n2=10;
void setup() {
  // put your setup code here, to run once:
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(n1,OUTPUT);
  pinMode(n2,OUTPUT);
  Serial.begin(9600);//begining serial connection
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(sonar.ping_cm()!=0)//loop will run till object is detected
  {
    analogWrite(n1,0);//setting second motor speed as 0
    analogWrite(n2,0);
    analogWrite(m2,0);//setting first motor at full speed
    analogWrite(m1,255);
    delay(500);//giving sonar time
  }
  
  int val1=analogRead(sensePin1);//value of sensor 1
  delay(100);//giving time to analog reders

  int val2=analogRead(sensePin2);//sensor value 2
  delay(100);
  //constraining values
  val1=constrain(val1,320,820);
  val2=constrain(val2,320,820);
  
  Serial.print(val1);//for convenience only
  Serial.println(val2);

  //mapping values
  int mspeed1=map(val1,300,820,0,255);
  int mspeed2=map(val2,300,820,0,255);
  
  //driving motors at respective speeds
  analogWrite(m2,0);
  analogWrite(n2,0);
  
  analogWrite(m1,mspeed1);
  analogWrite(n1,mspeed2);
  
  delay(100);
}
