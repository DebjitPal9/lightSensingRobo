#include<EEPROM.h>
void setup() {
  // put your setup code here, to run once:
  EEPROM.write(0,0);
  EEPROM.write(1,'S');
  EEPROM.write(2,'J');
  EEPROM.write(3,'S');
  EEPROM.write(3,'D');
  //for commmit
  EEPROM.write(4,'E');

}

void loop() {
  // put your main code here, to run repeatedly:

}
