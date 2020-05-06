int sp1=0;
int sp2=1;

int m1=5;//first motor
int m2=6;

int n1=11;//secong motor
int n2=10;
void setup() {
  // put your setup code here, to run once:
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  pinMode(n1,OUTPUT);
  pinMode(n2,OUTPUT);
  Serial.begin(9600);
}
void case1(int x)//straight (anyone value)
{
  analogWrite(m2,0);
  analogWrite(n2,0);

  analogWrite(m1,x);
  analogWrite(n1,x);
}
void case2(int m,int x)//bleak turn (motor,greater value) 
{
   analogWrite(m2,0);
   analogWrite(n2,0);
   int hlf=x/2;
  
  if(m==1)
  {
    analogWrite(m1,x);
    analogWrite(n1,hlf);
  } else if(m==2)
  {
    analogWrite(m1,hlf);
    analogWrite(n1,x);
  }
}
void case3(int m,int x)//sharp turn (motor,greater value)
{
  analogWrite(m2,0);
  analogWrite(n2,0);

  if(m==1)
  {
    analogWrite(m1,x);
    analogWrite(n1,0);
  }
  else if(m==2)
  {
    analogWrite(m1,0);
    analogWrite(n1,x);
  }
}
void loop() {
  // put your main code here, to run repeatedly:
  int v1=analogRead(sp1);
  //Serial.println(v1);
  delay(100);
  v1=constrain(v1,320,870);
  v1=map(v1,320,870,0,255);

  
  int v2=analogRead(sp2);
  delay(100);
  //Serial.println(v2);
  v2=constrain(v2,360,880);
  v2=map(v2,360,880,0,255);


  

  //getting difference
  double diff=0;
  
  if(v1>v2)
    {
      diff=v1-v2;//therefore v1>v2
      if(diff<=0.5*v1)
        {//CASE 1
          case1(v1);
        }
      else if(diff>0.5*v1&& diff<=0.6667*v1)
       {
          case2(1,v1);
       }
       else if(diff>0.6667*v1)
       {
          case3(1,v1);
       }
    }
  else if(v1<v2)
    {
      diff=v2-v1;
      if(diff<=0.5*v2)
      {
        //CASE 1
        case1(v2);
      }
      else if(diff>0.5*v2&& diff<=0.6667*v2)
       {//case 2
        case2(2,v2);
       }
       else if(diff>0.6667*v2)
       {
        //case 3
        case3(2,v2);
       }
    }
  else //assuming v1==v2
  {
    //case 1
    case1(v1);
  }
  
}
