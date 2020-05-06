#include<NewPing.h>
NewPing sonar(3,9,30);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Distance is:");
  int dist=sonar.ping_cm();
  Serial.print(dist);
  Serial.println(" cm");
  delay(1000);

}
