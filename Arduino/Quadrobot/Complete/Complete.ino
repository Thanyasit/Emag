#include <Servo.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo[4][2];  // create servo object to control a servo
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
const char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}};
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
const int servo_pin[4][2] = { {22, 23}, {24, 25}, {26, 27}, {28, 29} };
const int stand[4][2] = {{40,24},{40,24},{40,24},{40,24}};
const int standj[4][2] = {{34,23},{34,23},{34,23},{34,23}};
const int standjk[4][2] = {{71,1},{71,1},{71,1},{71,1}};
const int standdog[4][2] = {{20,90},{80,-30},{75,-30},{20,90}};//stand dog
const int sit[4][2] = {{30,0},{30,0},{30,0},{30,0}};
const int sit2[4][2] = {{55,-40},{55,-40},{55,-40},{55,-40}};
const int standb[4][2] = {{45,0},{45,0},{45,0},{45,0}};//stand 45
const int standc[4][2] = {{0,25},{0,25},{0,25},{0,25}};//stand 45
const int standh[4][2] = {{0,90},{0,90},{0,90},{0,90}};//stand 45
const int setleg = 82;
int y;
int l=18;//7000-walk15-climb20//delay between servo
int lb=13;
int lc=20;
void setup() {
  Serial.begin(115200);
  lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("      MR.2");
  lcd.setCursor(0, 1);
  lcd.print("     Ready.");
  pinMode (11,OUTPUT);
   for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(stand[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(stand[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(stand[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(stand[i][j]/1.646);//25
      }else if((i==2)&&(j==0)){
        y=79-(stand[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(stand[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(stand[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(stand[i][j]/1.646);//29   71
      } 
      servo[i][j].attach(servo_pin[i][j]);
      servo[i][j].write(y);
      delay(15);//10
    }
  }
}
void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY){
    Serial.println(key);
    digitalWrite (11,1);
    delay(200);
    digitalWrite (11,0);
  }
  if(key=='1'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       1.");
    lcd.setCursor(0, 1);
    lcd.print("     WalkFw");
    Setstand();
    WalkFw();
    Setstand();
  }else if(key=='2'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       2.");
    lcd.setCursor(0, 1);
    lcd.print("      Jog.");
    Setstand();
    Jog();
  }else if(key=='3'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       3.");
    lcd.setCursor(0, 1);
    lcd.print("     WalkRw");
    Setstand();
    WalkRw();
    Setstand();
  }else if(key=='4'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       4.");
    lcd.setCursor(0, 1);
    lcd.print("    WalkbFw.");
    Setstandb();
    WalkbFw();
    Setstandb();
  }else if(key=='5'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       5.");
    lcd.setCursor(0, 1);
    lcd.print("      Jogb");
    Setstandb();
  }else if(key=='6'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       6.");
    lcd.setCursor(0, 1);
    lcd.print("    WalkbRw.");
    Setstandb();
    WalkbRw();
    Setstandb();
  }else if(key=='7'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       7.");
    lcd.setCursor(0, 1);
    lcd.print("     silde");
    for(int p = 0; p < 10; p++){ 
      Setstandb();
      delay(700);
      Setstand();
      delay(700);
    }
  }else if(key=='8'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       8.");
    lcd.setCursor(0, 1);
    lcd.print("     Jump.");
    Setstandj();
    Jump();
    Setstandj();
  }else if(key=='9'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       9.");
    lcd.setCursor(0, 1);
    lcd.print("   StandLow.");
    Setstandjk();
  }else if(key=='A'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       A.");
    lcd.setCursor(0, 1);
    lcd.print("      Sit.");
    Sit();
  }else if(key=='B'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       B.");
    lcd.setCursor(0, 1);
    lcd.print("     Stand.");
    Setstand();
  }else if(key=='C'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       C.");
    lcd.setCursor(0, 1);
    lcd.print("  StandHigh");
    Setstandh();
  }else if(key=='D'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       D.");
    lcd.setCursor(0, 1);
    lcd.print("    Standdog");    
    Standdog();
  }else if(key=='*'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       *.");
    lcd.setCursor(0, 1);
    lcd.print("    SquatFw.");
    Setstandc();
    SquatFw();
    Setstandc();
  }else if(key=='0'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       0.");
    lcd.setCursor(0, 1);
    lcd.print("      Frog");
    Setstandc();
  }else if(key=='#'){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("       #.");
    lcd.setCursor(0, 1);
    lcd.print("     FrogRw");
    Setstandc();
    SquatRw();
    Setstandc();
  }
}
