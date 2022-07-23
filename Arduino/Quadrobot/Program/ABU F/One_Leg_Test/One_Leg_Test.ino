#include <Servo.h>
Servo myservo[2];  // create servo object to control a servo
const int servo_pin[2] = {28,29};
const int setleg = 82;//All
const int stand[2] = {20,70};//20,70
const int M1[2] = {35,67}; //Front 22,23,28,29
const int M2[2] = {44,64};
const int M3[2] = {49,82};
const int M4[2] = {45,86};
const int M5[2] = {37,82};
const int M6[2] = {23,64};
/*
const int stand[2] = {30,55};
const int M1[2] = {35,67}; //Rear24,25,26,27
const int M2[2] = {44,64};
const int M3[2] = {49,82};
const int M4[2] = {45,86};
const int M5[2] = {37,82};
const int M6[2] = {23,64};
*/
int error = 1.646;
int x;
int y;
int s=1;//เลือกโหมดตั้งขาหรือทดสอบ
int s1=1;//เลือกโหมดขา+หรือ-
int d=500;
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 2; i++){
  myservo[i].attach(servo_pin[i]);
  myservo[i].write(setleg);
  delay(100);
  delay(100);
  }
}
void loop() {
  if(s==0){
    for (int i = 0; i < 2; i++){
      myservo[i].write(setleg);
      delay(100);
    } 
  }else if(s==1){
    for (int i = 0; i < 2; i++){
      if(i==0){
        y=90-(stand[i]/1.646); //22,24,27,29
      }else{
        y=setleg+(stand[i]/1.646);//23,25,26,28
      }
      myservo[i].write(y);
      Serial.print(i);
      Serial.print(" : ");
      Serial.println(y);
      delay(100);
    } 
  }else{
    for (int i = 0; i < 2; i++){
      if(i==0){
        y=90+(stand[i]/1.646); //22,24,27,29 
      }else{
        y=setleg-(stand[i]/1.646);//23,25,26,27
      }
      myservo[i].write(y);
      Serial.print(i);
      Serial.print(" : ");
      Serial.println(y);
      delay(100);
    }
   }
   delay(d);
}
