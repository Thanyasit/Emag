//By Emag
#include <Wire.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 0x3f for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,20,4);
Servo servo1; // Create a servo object
int Button1;//Set
int Button2;//Start
int Time;
int f1;
int X,s,b1,b2,b3,m;
int Save;
unsigned long previousTime = 0;
void setup()
{
servo1.attach(5); // Attaches the servo on Pin 5 to the servo object
pinMode(3,INPUT);
pinMode(2,INPUT);
// initialize the LCD
lcd.begin();
lcd.print("      Time");
lcd.setCursor(0, 1);
lcd.print("    00:00:00");
}
void loop() 
{
    //unsigned long showTime = millis();
    lcd.setCursor(0, 0);      
    lcd.print("      Time");
    if(Time>9){
      lcd.setCursor(4, 1);
    }else{
      lcd.setCursor(5, 1);
    }
    lcd.print(Time);
    do{
      Button1 = digitalRead(2);
      delay(5);
      Button2 = digitalRead(3);     
      delay(5);
    }while(!(digitalRead(2)==1)&&(digitalRead(3)==1));
    if(Button1==0){
      if(Time>=24){
        Time=0;
        lcd.setCursor(0, 1);
        lcd.print("    0");
      }else{
        Time++;
      }
      lcd.setCursor(0, 1);
      lcd.print("SET");
    }else if(Button2==0&&f1==0&&Time>0){
      lcd.setCursor(0, 1);
      lcd.print("    00:00:00");
      Save=Time;
      Time--;
      m=59;
      X=59;
      s=27;
      f1=1;
      Clcok();      
    }
}
void Clcok(){
      while(1){
            lcd.setCursor(0, 0);      
            lcd.print("      Time");
            if(Time>9){
              lcd.setCursor(4, 1);
            }else{
              lcd.setCursor(0, 1);
              lcd.print("    0");
              lcd.setCursor(5, 1);
            }
            lcd.print(Time);
            if(X>9){
              lcd.setCursor(7, 1);
            }else{
              lcd.setCursor(7, 1);
              lcd.print("0");
              lcd.setCursor(8, 1);
            }
            lcd.print(X);
            if(m>9){
              lcd.setCursor(10, 1);
            }else{
              lcd.setCursor(10, 1);
              lcd.print("0");
              lcd.setCursor(11, 1);
            }
            lcd.print(m);
            s-=1; 
         //   delay(800);
            if ((X==0)&&(m==0)&&(Time==0)&&(s==0)){  
                  lcd.clear();  
                  lcd.setCursor(0, 1);
                  lcd.print("Feeding Animals");
                  servo1.write(0); // Write the angle to the servo
                  delay(5000); // Delay of 15ms to allow servo to reach position
                  servo1.write(90);
                  delay(15);
                  lcd.clear();
                  lcd.setCursor(0, 1); 
                  lcd.print("      :  :"); 
                  Time=Save;
                  Time--;
                  m=59;
                  X=59;
                  s=27;
                  Clcok();
            }else if ((X==0)&&(s==0)&&(m==0)){
                  Time--;
                  X=59;
                  m=59;
                  s=27;
            }else if ((m==0)&&(s==0)){
                  X-=1;
                  m=59;
                  s=27;
            }else if(s==0){
                  m--;
                  s=27;
            }
     }
}
