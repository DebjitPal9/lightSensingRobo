#include<EEPROM.h>
#include<Metro.h>
#include<Servo.h>
#include<NewPing.h>

//light sensor pins
int sensePin1=0;
int sensePin2=1;
//servo pin
int srPin=10;
//motor pins
int m1=5;
int m2=11;

int i;//servo angle control
//LED pins
int lp1=12;
int lp2=8;
//LED on off
boolean bright=LOW;

Metro bk1=Metro(1000);
Metro bk2=Metro(1000);

int val1=0;
int val2=0;
int mspeed1=0;
int mspeed2=0; 
NewPing sonar(3,9,15);//(trigPin,echoPin,maxDistInCm)
Servo servo;
//Servo wire facing towards robot and is facing its left
//ultrasonic sensor facing away from robot
void setup() {
  i=EEPROM.read(0);
  // put your setup code here, to run once:
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  Serial.begin(9600);
  servo.attach(srPin);//connecting servo with object

  pinMode(lp1,OUTPUT);
  pinMode(lp2,OUTPUT);
  
 
}
void loop() {
  
    val1=analogRead(sensePin1);//value of sensor 1
    delay(50);//giving time to analog reders

    val2=analogRead(sensePin2);//sensor value 2
    delay(50);
    //constraining values
    val1=constrain(val1,320,820);
    val2=constrain(val2,320,820);
    mspeed1=map(val1,300,820,0,255);
    mspeed2=map(val2,300,820,0,255);
    //updating servo
    EEPROM.write(0,i);
    servo.write(i);
    
    if(mspeed1>120||mspeed2>120)
    {
    int cond=sonar.ping_cm();//object condition
    int prnt=map(i,0,90,0,300);//to print
   
    while(cond!=0)//when object
    {
      int ang=i;
      if(ang>45)
      {
        digitalWrite(m2,HIGH);
        digitalWrite(m1,LOW);
      }
      else
      {
        digitalWrite(m2,LOW);
         digitalWrite(m1,HIGH);
      }
      cond=sonar.ping_cm();//updating condition of object
      //Serial.println(prnt);//object angle out of 300
      
      if(i>45)
      {
        Serial.println("Object at left");
       if(bk1.check())
       {
          digitalWrite(lp1,bright);
          bright=!bright;
       }
        
      }
      else if(i==45)
      {
        if(bk1.check())
        {
        digitalWrite(lp1,bright);
        digitalWrite(lp2,bright);
        bright=!bright;
        Serial.println("Object at front");
        }
      }
      else 
      {
        Serial.println("Object at right");
        if(bk2.check())
        {
          digitalWrite(lp2,bright);
         bright=!bright; 
        }
      }
      
      delay(500);
    }
    //No object
     digitalWrite(lp1,LOW);
     digitalWrite(lp2,LOW);
     
    Serial.println("No object");
    analogWrite(m1,mspeed1);
    analogWrite(m2,mspeed2);
    if(i==90)
    rev();
    delay(500);//very very important delay!
    i+=9;
    }
    else//no light
    {
     Serial.println("No light");
     delay(500);//very very important delay!
     digitalWrite(m1,LOW);
     digitalWrite(m2,LOW);
    }
}
void rev()
{
  while(i>=0)
  {
    val1=analogRead(sensePin1);//value of sensor 1
    delay(50);//giving time to analog reders

    val2=analogRead(sensePin2);//sensor value 2
    delay(50);
    //constraining values
    val1=constrain(val1,320,820);
    val2=constrain(val2,320,820);
    mspeed1=map(val1,300,820,0,255);
    mspeed2=map(val2,300,820,0,255);
    
    //updating servo
    EEPROM.write(0,i);
    servo.write(i);
    
    if(mspeed1>120||mspeed2>120)
    {
      int cond=sonar.ping_cm();
      int prnt=map(i,0,90,0,300);
      
     while(cond!=0)//when object
     {
      int ang=i;
      if(ang>45)
      {
        digitalWrite(m2,HIGH);
        digitalWrite(m1,LOW);
      }
      else
      {
        digitalWrite(m2,LOW);
         digitalWrite(m1,HIGH);
      }
      cond=sonar.ping_cm();//updating object condition
     //Serial.println(prnt);//object angle out of 300
     if(i>45)
      {
        Serial.println("Object at left");
       if(bk1.check())
       {
          digitalWrite(lp1,bright);
          bright=!bright;
       }
      }
      else if(i==45)
      {
        if(bk1.check())
        {
        digitalWrite(lp1,bright);
        digitalWrite(lp2,bright);
        bright=!bright;
        Serial.println("Object at front");
        }
      }
      else 
      {
        Serial.println("Object at right");
        if(bk2.check())
        {
          digitalWrite(lp2,bright);
         bright=!bright; 
        }
      }
     
      delay(500);
    }
    //no object
    digitalWrite(lp1,LOW);
     digitalWrite(lp2,LOW);
    Serial.println("No object");
    analogWrite(m1,mspeed1);
    analogWrite(m2,mspeed2);
    delay(500);//very very important delay!
    //servo will only update its angle if there is light
    i-=9;
    }
    else//no light
    {
     Serial.println("No light");
     delay(500);//very very important delay!
     digitalWrite(m1,LOW);
     digitalWrite(m2,LOW);
    }
  }
  
  return;
}
