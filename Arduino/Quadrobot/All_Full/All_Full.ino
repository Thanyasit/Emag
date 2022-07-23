#include <Servo.h>
Servo servo[4][3];
//define sw
const int sw1 = 22; //walk
const int sw2 = 23; //walk climb
const int sw3 = 24; //rotation
//define pin sen
const int tl = 48; //trigleft
const int el = 49;   //echoleft
const int tr = 50;
const int er = 51;
const int tb = 52;
const int eb = 53;
//define servos' ports
const int servo_pin[4][3] = { {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13} };
const int setting[4][3] = { {90, 91, 93}, {90, 87, 85}, {90, 91, 93}, {90, 89, 88} };
const int standnew[4][3] = { {120, 61, 37}, {70, 117, 141}, {110, 61, 37}, {60, 118, 147} };
//define variable
int r = 20 ; //delay rotation
int rt = 15; //delay rotation
int w = 15; //delay walk
int wt = 15; //delay walk
int c = 20; //delay climb
int ct = 50; //delay climb
int sm = 0; //selectmode
int nrope =0;
long durationl=0, cml=0, durationr=0, cmr=0, durationb=0, cmb=0 ;
//int inputsen = 0;
int utra = 0;
int count =0;
float average = 0; //Sen Amp
void setup() {
  Serial.begin(115200);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(tl, OUTPUT);
  pinMode(el, INPUT);
  pinMode(tr, OUTPUT);
  pinMode(er, INPUT);
  pinMode(tb, OUTPUT);
  pinMode(eb, INPUT);
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      pinMode(servo_pin[i][j], OUTPUT);
      servo[i][j].attach(servo_pin[i][j]);
      servo[i][j].write(standnew[i][j]);
      delay(100);
    }
  }
  delay(2000);
}
void loop() {
  if (!digitalRead(sw1)) {
    sm = 1;
  }
  if (!digitalRead(sw2)) {
    sm = 2;
  }
  if (!digitalRead(sw3)) {
    sm = 3;
  }
  if (sm == 1) {
    walk();
  } else if (sm == 2) {
    walk();
  } else if (sm == 3) {
    count = 3;
    walk();
  }
  Serial.print("select mode  ");
  Serial.println(sm);
}

void delayr() {
  delay(r);
}
void delayc() {
  utrasonic();
  if((cmb<10)&&(cmb>5)){
    count = 1;
  }
  if(count == 1){
    if((cmb<30)&&(cmb>25)){
      walk();
    }
  }
  delay(c);
}
void delayw() {
  utrasonic();
  if((cml<95)&&(cml>91)&&(cmr<30)&&(cmr>26)){
    rotationr();
  }else if((cml<5)&&(cmr<5)&&(cmr!=0)&&(cml!=0)){
    climbu();
  }
  delay(w);
}
