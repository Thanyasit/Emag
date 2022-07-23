#include <Servo.h>
Servo servo[4][2];  // create servo object to control a servo
const int servo_pin[4][2] = { {22, 23}, {24, 25}, {26, 27}, {28, 29} };
const int setleg = 82;
//const int stand[4][2] = {{45,0},{45,0},{45,0},{45,0}};//stand 45
//const int stand[4][2] = {{34,23},{34,23},{34,23},{34,23}};//stand high
const int stand[4][2] = {{40,24},{40,24},{40,24},{40,24}};//stand mit
//const int stand[4][2] = {{59,4},{59,4},{59,4},{59,4}};//stand mit slope
//const int stand[4][2] = {{43,27},{43,27},{43,27},{43,27}};//stand mit slope
/*
//boston 25mm ลด Step 10+; good
const int M1[4][2] = { {45, 0}, {57, 3}, {45, 0}, {57, 3} };
const int M2[4][2] = { {45, 0}, {51, -13}, {45, 0}, {51, -13} };
const int M3[4][2] = { {57, 3}, {30, 3}, {57, 3}, {30, 3} };
const int M4[4][2] = { {51, -13}, {45, 0}, {51, -13}, {45, 0} };
const int M5[4][2] = { {30, 3}, {57, 3}, {30, 3}, {57, 3} };
*/
//mit 30mm  very good
const int M1[4][2] = { {40, 24}, {45, 27}, {40, 24}, {45, 27} };
const int M2[4][2] = { {40, 24}, {50, 5}, {40, 24}, {50, 5} };
const int M3[4][2] = { {45, 27}, {34, 22}, {45, 27}, {34, 22} };
const int M4[4][2] = { {50, 5}, {40, 24}, {50, 5}, {40, 24} };
const int M5[4][2] = { {34, 22}, {45, 27}, {34, 22}, {45, 27} };
//mit 70 ลด Step clime  very good
/*
const int M6[4][2] = { {40, 24}, {44, 29}, {40, 24}, {44, 29} };//
const int M7[4][2] = { {40, 24}, {62, -15}, {40, 24}, {62, -15} };
const int M8[4][2] = { {44, 29}, {34, 22}, {44, 29}, {34, 22} };
const int M9[4][2] = { {62, -15}, {40, 24}, {62, -15}, {40, 24} };
const int M10[4][2] = { {34, 22}, {44, 29}, {34, 22}, {44, 29} };
/*
//boston 70 ลด Step clime good
const int M1[4][2] = { {34, 23}, {38, 23}, {34, 23}, {38, 23} };//55-20 angle80 delay 23
const int M2[4][2] = { {34, 23}, {55, -20}, {34, 23}, {55, -20} };//54-18 angle75
const int M3[4][2] = { {38, 23}, {29, 23}, {38, 23}, {29, 23} };
const int M4[4][2] = { {55, -20}, {34, 23}, {55, -20}, {34, 23} };
const int M5[4][2] = { {29, 23}, {38, 23}, {29, 23}, {38, 23} };
//boston 50mm circle ขึ้นเนิน Delay 7ms good
const int M1[4][2] = { {45, 0}, {51, 1}, {45, 0}, {51, 1} }; 
const int M2[4][2] = { {45, 0}, {57, 3}, {45, 0}, {57, 3} };
const int M3[4][2] = { {45, 0}, {64, -16}, {45, 0}, {64, -16} };
const int M4[4][2] = { {45, 0}, {57, -24}, {45, 0}, {57, -24} };
const int M5[4][2] = { {51, 1}, {42, -16}, {51, 1}, {42, -16} };
const int M6[4][2] = { {57, 3}, {30, 3}, {57, 3}, {30, 3} };
const int M7[4][2] = { {64, -16}, {39, 1}, {64, -16}, {38, 1} };
const int M8[4][2] = { {57, -24}, {45, 0}, {57, -24}, {45, 0} };
const int M9[4][2] = { {42, -16}, {51, 1}, {42, -16}, {51, 1} };
const int M10[4][2] = { {30, 3}, {57, 3}, {30, 3}, {57, 3} };
const int M11[4][2] = { {39, 3}, {64, -16}, {39, 3}, {64, -16} };
//boston 50mm circle step ขึ้นเนิน Delay 7ms good
const int M1[4][2] = { {45, 0}, {51, 1}, {45, 0}, {51, 1} }; 
const int M2[4][2] = { {45, 0}, {64, -16}, {45, 0}, {64, -16} };
const int M3[4][2] = { {51, 1}, {42, -16}, {51, 1}, {42, -16} };
const int M4[4][2] = { {64, -16}, {39, 1}, {64, -16}, {38, 1} };
const int M5[4][2] = { {42, -16}, {51, 1}, {42, -16}, {51, 1} };
//boston 30cmm circle 60 ขึ้นเนิน 
const int M1[4][2] = { {59, 4}, {63, 10}, {59, 4}, {63, 10} }; 
const int M2[4][2] = { {59, 4}, {68, -10}, {59, 4}, {68, -10} };
const int M3[4][2] = { {63, 10}, {53, 0}, {63, 10}, {53, 0} };
const int M4[4][2] = { {68, -10}, {59, 4}, {68, -10}, {59, 4} };
const int M5[4][2] = { {53, 0}, {63, 10}, {53, 0}, {63, 10} };
/*
//boston 30cmm circle 60 ขึ้นเนิน 
const int M1[4][2] = { {43, 27}, {48, 38}, {43, 27}, {48, 38} }; 
const int M2[4][2] = { {43, 27}, {52, 11}, {43, 27}, {52, 11} };
const int M3[4][2] = { {48, 38}, {34, 23}, {48, 38}, {34, 23} };
const int M4[4][2] = { {52, 11}, {43, 27}, {52, 11}, {43, 27} };
const int M5[4][2] = { {34, 23}, {48, 38}, {34, 23}, {48, 38} };
*/
int t=0;
int d=1; //test
int y;
int l=13;//7-10-walk15-climb20//delay between servolow
int s=1;//เลือกโหมดตั้งขาหรือทดสอบ
void setup() {
  Serial.begin(115200);
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
  //while(1);
  if(s==0){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        servo[i][j].write(setleg);
        delay(100);
      }
    }
  }else{
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
          delay(l);
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
          delay(l);
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
          delay(l);
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
          delay(l);
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
          delay(l);
        }
      }
      /*
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
          delay(l);
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
          delay(l);
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
          delay(l);
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
          delay(l);
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
          delay(l);
        }
      }
      for (int i = 0; i < 4; i++){
        for (int j = 0; j < 2; j++){
          if((i==0)&&(j==0)){
            y=setleg+(M11[i][j]/1.646);
          }else if((i==0)&&(j==1)){
            y=79-(M11[i][j]/1.646);
          }else if((i==1)&&(j==0)){
            y=setleg+(M11[i][j]/1.646);
          }else if((i==1)&&(j==1)){
            y=setleg-(M11[i][j]/1.646);
          }else if((i==2)&&(j==0)){
            y=79-(M11[i][j]/1.646);
          }else if((i==2)&&(j==1)){
            y=setleg+(M11[i][j]/1.646);
          }else if((i==3)&&(j==0)){
            y=setleg-(M11[i][j]/1.646);
          }else if((i==3)&&(j==1)){
            y=75+(M11[i][j]/1.646);
          }
          servo[i][j].write(y);
          delay(l);
        }
      }
      */
    
  }
}
