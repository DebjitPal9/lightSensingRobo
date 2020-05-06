
#include<NewPing.h>
int sensePin2=0;//sensor 1
int sensePin1=1;//sensor 2
NewPing sonar(3,9,15);//(trigPin,echoPin,maxdistance in cm) ; creating NewPing object

int m1=5;//first motor pins
int n1=11;//second motor pins

void setup() {
  // put your setup code here, to run once:
  pinMode(m1,OUTPUT);
  
  pinMode(n1,OUTPUT);

  //for led 13
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);

  //sensor pins will ne aytomatically detected as inputs
  Serial.begin(9600);//begining serial connection

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int val1=analogRead(sensePin1);//value of sensor 1
  delay(100);//giving time to analog reders

  int val2=analogRead(sensePin2);//sensor value 2
  delay(100);
  //constraining values
  val1=constrain(val1,320,820);
  val2=constrain(val2,320,820);
  
 
  //mapping values
  int mspeed1=map(val1,300,820,0,255);
  int mspeed2=map(val2,300,820,0,255);

  if(mspeed1>120||mspeed2>120)
  {
  if(sonar.ping_cm()!=0)//if is true will run till object is detected
  {
    
    if(mspeed1>mspeed2)
    {
      analogWrite(m1,mspeed1);// ronin first motor at sensor detected speed
      analogWrite(n1,0);
      Serial.println("Object!!,Turning  left.");
     
    }
    else if(mspeed2>mspeed1)
    {
      analogWrite(n1,mspeed2);//ronin second motor at sensor detected speed
      analogWrite(m1,0);
      Serial.println("Object!!,Turning right.");
    
    }
    else
    {
      analogWrite(n1,0);
      analogWrite(m1,0);//ronin first motor at detected speed
      Serial.println("Object!!,Wrong input positon.");
    }
    delay(500);//giving sonar time
  }
  else
  {
    //driving motors at respective speeds
    if(mspeed1>mspeed2)
    Serial.println("No object :),Runing normal control.");
    else
    Serial.println("No object :),Runing normal control.");
   analogWrite(m1,mspeed1);
   analogWrite(n1,mspeed2);
   
  }
  }
  else
  {
    Serial.println("No source light!!,Try to use bright light.");
    analogWrite(m1,0);
    analogWrite(n1,0);
    
  }
  
  // motors will not continue to run as respective speeds are updating at 16kHz11                                   
}
