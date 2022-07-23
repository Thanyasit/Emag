#include <Servo.h>
Servo servo[4][2];  // create servo object to control a servo
Servo servob;
Servo servoc;
const int servo_pin[4][2] = { {22, 23}, {24, 25}, {26, 27}, {28, 29} };
const int setleg = 82;
const int stand[4][2] = {{40,24},{40,24},{40,24},{40,24}};//stand mit
//const int stand[4][2] = {{59,4},{59,4},{59,4},{59,4}};//stand mit slope
//const int stand[4][2] = {{36,90},{80,-30},{80,-30},{39,90}};//stand dog
//mit 30mm  very good
const int M1[4][2] = { {40, 24}, {45, 27}, {40, 24}, {45, 27} };
const int M2[4][2] = { {40, 24}, {50, 5}, {40, 24}, {50, 5} };
const int M3[4][2] = { {45, 27}, {34, 22}, {45, 27}, {34, 22} };
const int M4[4][2] = { {50, 5}, {40, 24}, {50, 5}, {40, 24} };
const int M5[4][2] = { {34, 22}, {45, 27}, {34, 22}, {45, 27} };
//mit 70 ลด Step clime  very good
const int M6[4][2] = { {40, 24}, {44, 29}, {40, 24}, {44, 29} };//
const int M7[4][2] = { {40, 24}, {62, -15}, {40, 24}, {62, -15} };
const int M8[4][2] = { {44, 29}, {34, 22}, {44, 29}, {34, 22} };
const int M9[4][2] = { {62, -15}, {40, 24}, {62, -15}, {40, 24} };
const int M10[4][2] = { {34, 22}, {44, 29}, {34, 22}, {44, 29} };
/*
//boston 30cmm circle 60 slope delay 13ms very good 
const int M1[4][2] = { {59, 4}, {63, 10}, {59, 4}, {63, 10} }; 
const int M2[4][2] = { {59, 4}, {68, -10}, {59, 4}, {68, -10} };
const int M3[4][2] = { {63, 10}, {53, 0}, {63, 10}, {53, 0} };
const int M4[4][2] = { {68, -10}, {59, 4}, {68, -10}, {59, 4} };
const int M5[4][2] = { {53, 0}, {63, 10}, {53, 0}, {63, 10} };
*/
unsigned long ct=0;
unsigned long duration=0, cm=0;
const int tl = 46;
const int el = 47;
const int lim = 45;
const int b = 40;
const int c = 41;
int count=0;
int a=0;
int t=0;
int d=1; //test
int y;
int l=15;//7000-walk15-climb20//delay between servolow
int s=1;//เลือกโหมดตั้งขาหรือทดสอบ
void setup() {
  Serial.begin(115200);
  pinMode(lim, INPUT_PULLUP);
  pinMode(tl, OUTPUT);
  pinMode(el, INPUT);
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
    servoc.attach(c);
    servoc.write(90);//90 กางออก
    servob.attach(b);
    servob.write(0);
}
void loop() {
  //while(1);
  if(s==0){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        servo[i][j].write(setleg);
        delay(100);
      }
    }
  }else{
    if(digitalRead(lim)==0){
      delay(500);
      servob.write(175);
      servoc.write(0);
      t=1;
    }
    if(t==1){
      if(d==1){
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M1[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M1[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M1[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M1[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M1[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M1[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M1[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M1[i][j]/1.646);
          }
          servo[i][j].write(y);
          d=0;
          utrasonic();
        }
      }
      }
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M2[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M2[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M2[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M2[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M2[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M2[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M2[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M2[i][j]/1.646);
          }
          servo[i][j].write(y);
          utrasonic();
        }
      }
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M3[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M3[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M3[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M3[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M3[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M3[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M3[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M3[i][j]/1.646);
          }
          servo[i][j].write(y);
          utrasonic();
        }
      }
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M4[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M4[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M4[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M4[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M4[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M4[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M4[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M4[i][j]/1.646);   
          }
          servo[i][j].write(y);
          utrasonic();
        }
      }
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M5[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M5[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M5[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M5[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M5[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M5[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M5[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M5[i][j]/1.646);
          }
          servo[i][j].write(y);
          utrasonic();
        }
      }
    }else if(t==2){
      if(d==1){
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M6[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M6[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M6[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M6[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M6[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M6[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M6[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M6[i][j]/1.646);
          }
          servo[i][j].write(y);
          d=0;
          utrasonic();
        }
      }
      }
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M7[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M7[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M7[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M7[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M7[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M7[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M7[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M7[i][j]/1.646);
          }
          servo[i][j].write(y);
          utrasonic();
        }
      }
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M8[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M8[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M8[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M8[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M8[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M8[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M8[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M8[i][j]/1.646);
          }
          servo[i][j].write(y);
          utrasonic();
        }
      }
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M9[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M9[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M9[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M9[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M9[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M9[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M9[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M9[i][j]/1.646);
          }
          servo[i][j].write(y);
          utrasonic();
        }
      }
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M10[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M10[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M10[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M10[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M10[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M10[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M10[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M10[i][j]/1.646);
          }
          servo[i][j].write(y);
          utrasonic();
        }
      }
    }
  }
}
