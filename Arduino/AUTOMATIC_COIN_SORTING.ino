//By Emag
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);//0x27
int b1,b2,b3,b4;
long c1=0,c2=0,c5=0,c10=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT_PULLUP);//C1
  pinMode(3, INPUT_PULLUP);//C2
  pinMode(4, INPUT_PULLUP);//C5
  pinMode(5, INPUT_PULLUP);//C10
  lcd.begin();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Coins1 =      C");
  lcd.setCursor(0, 1);
  lcd.print("Coins2 =      C");
  lcd.setCursor(0, 2);
  lcd.print("Coins5 =      C");
  lcd.setCursor(0, 3);
  lcd.print("Coins10=      C");
}
void loop() {
  // put your main code here, to run repeatedly:
  /*
  if(c1>9){
    
  }else if(c2>99){
    
  }else if(c3>999)
    
  }else{
    
  }
  */
  lcd.setCursor(9, 0);
  lcd.print(c1);
  lcd.setCursor(9, 1);
  lcd.print(c2);
  lcd.setCursor(9, 2);
  lcd.print(c5);
  lcd.setCursor(9, 3);
  lcd.print(c10);
  do{
    b1 = digitalRead(2);
  }while(!digitalRead(2)==0);
  do{  
    b2 = digitalRead(3);
  }while(!digitalRead(3)==0);
  do{
    b3 = digitalRead(4);
  }while(!digitalRead(4)==0);
  do{
    b4 = digitalRead(5);
  }while(!digitalRead(5)==0);
  if(b1==1){
    c1++;
  }
  if(b2==1){
    c2++;
  }
  if(b3==1){
    c5++;
  }
  if(b4==1){
    c10++;
  }
}
