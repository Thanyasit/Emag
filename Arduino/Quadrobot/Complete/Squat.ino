const int c1[4][2] = { {0, 25}, {15, 12}, {0, 25}, {15, 12} };
const int c2[4][2] = { {0, 25}, {-2, 12}, {0, 25}, {-2, 12} };
const int c3[4][2] = { {15, 12}, {-16, 43}, {15, 12}, {-16, 43} };
const int c4[4][2] = { {-2, 12}, {0, 25}, {-2, 12}, {0, 25} };
const int c5[4][2] = { {-16, 43}, {15, 12}, {-16, 43}, {15, 12} };
void SquatFw(){   
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){
      if((i==0)&&(j==0)){
        y=setleg+(c1[i][j]/1.646);
      }else if((i==0)&&(j==1)){
        y=79-(c1[i][j]/1.646);
      }else if((i==1)&&(j==0)){
        y=setleg+(c1[i][j]/1.646);
      }else if((i==1)&&(j==1)){
        y=setleg-(c1[i][j]/1.646);
      }else if((i==2)&&(j==0)){
        y=79-(c1[i][j]/1.646);
      }else if((i==2)&&(j==1)){
        y=setleg+(c1[i][j]/1.646);
      }else if((i==3)&&(j==0)){
        y=setleg-(c1[i][j]/1.646);
      }else if((i==3)&&(j==1)){
        y=75+(c1[i][j]/1.646);
      }
      servo[i][j].write(y);
      delay(lc);
    }
  }
  for(int k =0 ; k<30;k++){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(c2[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(c2[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(c2[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(c2[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(c2[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(c2[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(c2[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(c2[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(lc);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(c3[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(c3[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(c3[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(c3[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(c3[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(c3[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(c3[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(c3[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(lc);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(c4[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(c4[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(c4[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(c4[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(c4[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(c4[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(c4[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(c4[i][j]/1.646);   
        }
        servo[i][j].write(y);
        delay(lc);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(c5[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(c5[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(c5[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(c5[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(c5[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(c5[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(c5[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(c5[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(lc);
      }
    }
  }
}
const int c11[4][2] = { {0, 25},    {-16, 43},   {0, 25},   {-16, 43} };
const int c12[4][2] = { {0, 25},    {-2, 12},   {0, 25},   {-2, 12} };
const int c13[4][2] = { {-16, 43},   {15, 12},  {-16, 43},  {15, 12} };
const int c14[4][2] = { {-2, 12},   {0, 25},    {-2, 12},  {0, 25} };
const int c15[4][2] = { {15, 12},  {-16, 43},   {15, 12}, {-16, 43} };
void SquatRw(){   
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){
      if((i==0)&&(j==0)){
        y=setleg+(c11[i][j]/1.646);
      }else if((i==0)&&(j==1)){
        y=79-(c11[i][j]/1.646);
      }else if((i==1)&&(j==0)){
        y=setleg+(c11[i][j]/1.646);
      }else if((i==1)&&(j==1)){
        y=setleg-(c11[i][j]/1.646);
      }else if((i==2)&&(j==0)){
        y=79-(c11[i][j]/1.646);
      }else if((i==2)&&(j==1)){
        y=setleg+(c11[i][j]/1.646);
      }else if((i==3)&&(j==0)){
        y=setleg-(c11[i][j]/1.646);
      }else if((i==3)&&(j==1)){
        y=75+(c11[i][j]/1.646);
      }
      servo[i][j].write(y);
      delay(lc);
    }
  }
  for(int k =0 ; k<30;k++){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(c12[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(c12[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(c12[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(c12[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(c12[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(c12[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(c12[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(c12[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(lc);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(c13[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(c13[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(c13[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(c13[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(c13[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(c13[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(c13[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(c13[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(lc);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(c14[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(c14[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(c14[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(c14[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(c14[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(c14[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(c14[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(c14[i][j]/1.646);   
        }
        servo[i][j].write(y);
        delay(lc);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(c15[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(c15[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(c15[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(c15[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(c15[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(c15[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(c15[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(c15[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(lc);
      }
    }
  }
}
