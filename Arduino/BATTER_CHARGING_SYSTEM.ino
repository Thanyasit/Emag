//By Emag
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 20, 4);

const int billValidator = A0;
unsigned long inputcoin;
int dollarCounter = 0;
int c = 0;
int X = 0;
int h = 0;
int t = 0;
int Button;
int s = 59;
void setup() {
  pinMode(A2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(3, 0);
  digitalWrite(4, 0);
  c = 0;
  X = 0;
  Serial.begin(9600);
  pinMode(billValidator, INPUT_PULLUP);
  lcd.begin();
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(" Solar cell charger ");
  lcd.setCursor(0, 2);
  lcd.print("      To Phone ");
  lcd.setCursor(0, 3);
  lcd.print("        2017 ");
  delay(5000);
  lcd.clear();
  loop() ;
}

void loop() {
  lcd.setCursor(0, 2);
  lcd.print("  TIME = ");
  lcd.setCursor(10 , 2);
  lcd.print(X);
  lcd.setCursor(0, 1);
  lcd.print("  Money = ");
  lcd.setCursor(10 , 1);
  lcd.print(c);
  lcd.setCursor(14, 1);
  lcd.print("Baht");
  lcd.setCursor(0, 2);
  lcd.print("  Time  =");
  lcd.setCursor(14, 2);
  lcd.print("Min");
  while (1) {
    if (t == 1) {
      lcd.setCursor(0, 3);
      lcd.print("       USB OFF");
      lcd.setCursor(0, 0);
      lcd.print("  Pls Insert Money");
    }
    Button = digitalRead(A2);
    h = 5;
    s = 59;
    inputcoin = pulseIn(billValidator, HIGH);
    float time = inputcoin / 10000.00;

    Serial.print("DelT=");
    Serial.print(time);
    Serial.println(" ms");

    if (time > 0) {
      dollarCounter++;
      if (t == 1) {
        t = 0;
        lcd.clear();
      }
      Serial.println(dollarCounter);
    }
    if (time == 0) {
      if (dollarCounter == 1) {
        //lcd.print("1");
        c = c + 1;
        X = h * c;
      } else if (dollarCounter > 1 && dollarCounter <= 7) {
        //lcd.print("5");
        c = c + 5;
        X = h * c;
      } else if (dollarCounter > 8) {
        //lcd.print("10");
        c = c + 10;
        X = h * c;
      }
      if (X < 10) {
        lcd.setCursor(14, 2);
        lcd.print(" ");
      }
      lcd.setCursor(0, 2);
      lcd.print("  Time  =");
      lcd.setCursor(10 , 2);
      lcd.print(X);
      lcd.setCursor(14, 2);
      lcd.print("Min");
      lcd.setCursor(0, 1);
      lcd.print("  Money = ");
      lcd.setCursor(10 , 1);
      lcd.print(c);
      lcd.setCursor(14, 1);
      lcd.print("Baht");
      if (Button == LOW) {
        if (c >= 1) {
          lcd.clear();
          X--;
          Clcok();
        } else {
          lcd.clear();
          lcd.setCursor(0, 1);
          lcd.print(" !!Not Have Money!! ");
          delay(500);
          lcd.clear();
          t = 1;
          loop();
        }
      }
      dollarCounter = 0;
    }
  }
}
//////////////////////////////////////////////////////////////////////////////////////
void Clcok() {
  while (1) {
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    checkinsetcoil();
    lcd.setCursor(0, 0);
    lcd.print("       USB ON");
    lcd.setCursor(0, 2);
    lcd.print("Time  = ");
    //Serial.println (T);
    lcd.setCursor(8, 2);
    lcd.print(X);
    lcd.setCursor(11, 2);
    lcd.print(":");
    lcd.setCursor(12, 2);
    lcd.print(s);
    if (s < 10) {
      lcd.setCursor(13, 2);
      lcd.print("  ");
    }
    lcd.setCursor(14, 2);
    lcd.print(" Min.");
    s -= 1;
    if ((X == 0) && (s == 0)) {
      lcd.clear();
      c = 0;
      digitalWrite(4, 0);
      digitalWrite(3, 0);
      //Serial.println("hccccccccccccccccccccccccccccccccc");
      setup();
    } else if (s == 0) {
      X -= 1;
      s = 59;
    }
  }
}
////////////////////////////////////////////////////////////
void checkinsetcoil() {
  inputcoin = pulseIn(billValidator, HIGH);
  float time = inputcoin / 10000.00;
  /*
    Serial.print("DelT=");
    Serial.print(time);
    Serial.println(" ms");
  */
  if (time > 0) {
    dollarCounter++;
    //Serial.println(dollarCounter);
  }
  if (time == 0) {
    if (dollarCounter == 1) {
      //  Serial.println("1");
      X += 5;
    }
    if (dollarCounter > 1 && dollarCounter <= 3) {
      //  Serial.println("5");
      X += 25;
    }
    if (dollarCounter > 4) {
      // Serial.println("10");
      X += 50;
    }
    dollarCounter = 0;
  }
}
