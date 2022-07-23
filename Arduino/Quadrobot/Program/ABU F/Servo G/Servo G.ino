#include <Servo.h>
//Servo servoa;
Servo servob;
Servo servoc;
const int b = 40;
const int c = 41;
const int lim = 45;
void setup() {
  Serial.begin(9600);
  pinMode(lim, INPUT_PULLUP);
  servoc.attach(c);
  servoc.write(90);//90 กางออก
 servob.attach(b);
  servob.write(0);//0
}
void loop() {
  if(digitalRead(lim)==0){
    servoc.write(0);
    servob.write(175);
  }
}
/*
void setup() {
  Serial.begin(9600);
  pinMode(lim, INPUT_PULLUP);
  servoa.attach(a);
  for(int i=0;i<32;i++){
    servoa.write(i);
    delay(50);
  }
  delay(2000);
  servoc.attach(c);
  servoc.write(90);//90 กางออก
 servob.attach(b);
  servob.write(140);
}
void loop() {
  if(digitalRead(lim)==0){
    servoc.write(0);
    servob.write(0);
    for(int i=32;i>0;i--){
      servoa.write(i);
      delay(50);
    }
  }
}
*/
