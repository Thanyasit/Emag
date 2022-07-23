//mit 30mm  very good
const int M1[4][2] = { {40, 24}, {45, 27}, {40, 24}, {45, 27} };
const int M2[4][2] = { {40, 24}, {50, 5}, {40, 24}, {50, 5} };
const int M3[4][2] = { {45, 27}, {34, 22}, {45, 27}, {34, 22} };
const int M4[4][2] = { {50, 5}, {40, 24}, {50, 5}, {40, 24} };
const int M5[4][2] = { {34, 22}, {45, 27}, {34, 22}, {45, 27} };
void WalkFw(){   
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
      delay(l);
    }
  }
  for(int k =0 ; k<30;k++){
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
  }
}
//jog
const int jog1[4][2] = { {40, 24}, {50, 5}, {40, 24}, {50, 5} };
const int jog2[4][2] = { {50, 5}, {40, 24}, {50, 5}, {40, 24} };
void Jog(){
  for(int k=0 ;k<20; k++){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){
      if((i==0)&&(j==0)){
        y=setleg+(jog1[i][j]/1.646);
      }else if((i==0)&&(j==1)){
        y=79-(jog1[i][j]/1.646);
      }else if((i==1)&&(j==0)){
        y=setleg+(jog1[i][j]/1.646);
      }else if((i==1)&&(j==1)){
        y=setleg-(jog1[i][j]/1.646);
      }else if((i==2)&&(j==0)){
        y=79-(jog1[i][j]/1.646);
      }else if((i==2)&&(j==1)){
        y=setleg+(jog1[i][j]/1.646);
      }else if((i==3)&&(j==0)){
        y=setleg-(jog1[i][j]/1.646);
      }else if((i==3)&&(j==1)){
        y=75+(jog1[i][j]/1.646);
      }
      servo[i][j].write(y);
      delay(15);
    }
  }
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){
      if((i==0)&&(j==0)){
        y=setleg+(stand[i][j]/1.646);
      }else if((i==0)&&(j==1)){
        y=79-(stand[i][j]/1.646);
      }else if((i==1)&&(j==0)){
        y=setleg+(stand[i][j]/1.646);
      }else if((i==1)&&(j==1)){
        y=setleg-(stand[i][j]/1.646);
      }else if((i==2)&&(j==0)){
        y=79-(stand[i][j]/1.646);
      }else if((i==2)&&(j==1)){
        y=setleg+(stand[i][j]/1.646);
      }else if((i==3)&&(j==0)){
        y=setleg-(stand[i][j]/1.646);
      }else if((i==3)&&(j==1)){
        y=75+(stand[i][j]/1.646);
      }
      servo[i][j].write(y);
      delay(15);
    }
  }  
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){
      if((i==0)&&(j==0)){
        y=setleg+(jog2[i][j]/1.646);
      }else if((i==0)&&(j==1)){
        y=79-(jog2[i][j]/1.646);
      }else if((i==1)&&(j==0)){
        y=setleg+(jog2[i][j]/1.646);
      }else if((i==1)&&(j==1)){
        y=setleg-(jog2[i][j]/1.646);
      }else if((i==2)&&(j==0)){
        y=79-(jog2[i][j]/1.646);
      }else if((i==2)&&(j==1)){
        y=setleg+(jog2[i][j]/1.646);
      }else if((i==3)&&(j==0)){
        y=setleg-(jog2[i][j]/1.646);
      }else if((i==3)&&(j==1)){
        y=75+(jog2[i][j]/1.646);
      }
      servo[i][j].write(y);
      delay(15);
    }
  }  
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){
      if((i==0)&&(j==0)){
        y=setleg+(stand[i][j]/1.646);
      }else if((i==0)&&(j==1)){
        y=79-(stand[i][j]/1.646);
      }else if((i==1)&&(j==0)){
        y=setleg+(stand[i][j]/1.646);
      }else if((i==1)&&(j==1)){
        y=setleg-(stand[i][j]/1.646);
      }else if((i==2)&&(j==0)){
        y=79-(stand[i][j]/1.646);
      }else if((i==2)&&(j==1)){
        y=setleg+(stand[i][j]/1.646);
      }else if((i==3)&&(j==0)){
        y=setleg-(stand[i][j]/1.646);
      }else if((i==3)&&(j==1)){
        y=75+(stand[i][j]/1.646);
      }
      servo[i][j].write(y);
      delay(15);
    }
  }  
  }
}
const int M11[4][2] = { {40, 24}, {34, 22}, {40, 24}, {34, 22} };
const int M12[4][2] = { {40, 24}, {50, 5}, {40, 24}, {50, 5} };
const int M13[4][2] = { {34, 22}, {45, 27}, {34, 22}, {45, 27} };
const int M14[4][2] = { {50, 5}, {34, 22}, {50, 5}, {34, 22} };
const int M15[4][2] = { {45, 27}, {50, 5}, {45, 27}, {50, 5} };
void WalkRw(){   
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
  for(int k =0 ; k<30;k++){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(M12[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(M12[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(M12[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(M12[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(M12[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(M12[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(M12[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(M12[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(l);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(M13[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(M13[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(M13[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(M13[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(M13[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(M13[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(M13[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(M13[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(l);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(M14[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(M14[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(M14[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(M14[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(M14[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(M14[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(M14[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(M14[i][j]/1.646);   
        }
        servo[i][j].write(y);
        delay(l);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(M15[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(M15[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(M15[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(M15[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(M15[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(M15[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(M15[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(M15[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(l);
      }
    }
  }
}
