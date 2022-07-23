//boston 25mm ลด Step 10+; good
const int b1[4][2] = { {45, 0}, {57, 3}, {45, 0}, {57, 3} };
const int b2[4][2] = { {45, 0}, {51, -13}, {45, 0}, {51, -13} };
const int b3[4][2] = { {57, 3}, {30, 3}, {57, 3}, {30, 3} };
const int b4[4][2] = { {51, -13}, {45, 0}, {51, -13}, {45, 0} };
const int b5[4][2] = { {30, 3}, {57, 3}, {30, 3}, {57, 3} };
void WalkbFw(){   
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){
      if((i==0)&&(j==0)){
        y=setleg+(b1[i][j]/1.646);
      }else if((i==0)&&(j==1)){
        y=79-(b1[i][j]/1.646);
      }else if((i==1)&&(j==0)){
        y=setleg+(b1[i][j]/1.646);
      }else if((i==1)&&(j==1)){
        y=setleg-(b1[i][j]/1.646);
      }else if((i==2)&&(j==0)){
        y=79-(b1[i][j]/1.646);
      }else if((i==2)&&(j==1)){
        y=setleg+(b1[i][j]/1.646);
      }else if((i==3)&&(j==0)){
        y=setleg-(b1[i][j]/1.646);
      }else if((i==3)&&(j==1)){
        y=75+(b1[i][j]/1.646);
      }
      servo[i][j].write(y);
      delay(lb);
    }
  }
  for(int k =0 ; k<30;k++){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(b2[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(b2[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(b2[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(b2[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(b2[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(b2[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(b2[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(b2[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(lb);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(b3[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(b3[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(b3[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(b3[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(b3[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(b3[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(b3[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(b3[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(lb);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(b4[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(b4[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(b4[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(b4[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(b4[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(b4[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(b4[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(b4[i][j]/1.646);   
        }
        servo[i][j].write(y);
        delay(lb);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 2; j++){
        if((i==0)&&(j==0)){
          y=setleg+(b5[i][j]/1.646);
        }else if((i==0)&&(j==1)){
          y=79-(b5[i][j]/1.646);
        }else if((i==1)&&(j==0)){
          y=setleg+(b5[i][j]/1.646);
        }else if((i==1)&&(j==1)){
          y=setleg-(b5[i][j]/1.646);
        }else if((i==2)&&(j==0)){
          y=79-(b5[i][j]/1.646);
        }else if((i==2)&&(j==1)){
          y=setleg+(b5[i][j]/1.646);
        }else if((i==3)&&(j==0)){
          y=setleg-(b5[i][j]/1.646);
        }else if((i==3)&&(j==1)){
          y=75+(b5[i][j]/1.646);
        }
        servo[i][j].write(y);
        delay(lb);
      }
    }
  }
}
const int b11[4][2] = { {45, 0},     {30, 3},      {45, 0},     {30, 3} };
const int b12[4][2] = { {45, 0},     {51, -13},    {45, 0},     {51, -13} };
const int b13[4][2] = { {30, 3},     {57, 3},      {30, 3},     {57, 3} };
const int b14[4][2] = { {51, -13},   {45, 0},      {51, -13},   {45, 0} };
const int b15[4][2] = { {57, 3},     {30, 3},      {57, 3},     {30, 3} };
void WalkbRw() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      if ((i == 0) && (j == 0)) {
        y = setleg + (b11[i][j] / 1.646);
      } else if ((i == 0) && (j == 1)) {
        y = 79 - (b11[i][j] / 1.646);
      } else if ((i == 1) && (j == 0)) {
        y = setleg + (b11[i][j] / 1.646);
      } else if ((i == 1) && (j == 1)) {
        y = setleg - (b11[i][j] / 1.646);
      } else if ((i == 2) && (j == 0)) {
        y = 79 - (b11[i][j] / 1.646);
      } else if ((i == 2) && (j == 1)) {
        y = setleg + (b11[i][j] / 1.646);
      } else if ((i == 3) && (j == 0)) {
        y = setleg - (b11[i][j] / 1.646);
      } else if ((i == 3) && (j == 1)) {
        y = 75 + (b11[i][j] / 1.646);
      }
      servo[i][j].write(y);
      delay(lb);
    }
  }
  for (int k = 0 ; k < 30; k++) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        if ((i == 0) && (j == 0)) {
          y = setleg + (b12[i][j] / 1.646);
        } else if ((i == 0) && (j == 1)) {
          y = 79 - (b12[i][j] / 1.646);
        } else if ((i == 1) && (j == 0)) {
          y = setleg + (b12[i][j] / 1.646);
        } else if ((i == 1) && (j == 1)) {
          y = setleg - (b12[i][j] / 1.646);
        } else if ((i == 2) && (j == 0)) {
          y = 79 - (b12[i][j] / 1.646);
        } else if ((i == 2) && (j == 1)) {
          y = setleg + (b12[i][j] / 1.646);
        } else if ((i == 3) && (j == 0)) {
          y = setleg - (b12[i][j] / 1.646);
        } else if ((i == 3) && (j == 1)) {
          y = 75 + (b12[i][j] / 1.646);
        }
        servo[i][j].write(y);
        delay(lb);
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        if ((i == 0) && (j == 0)) {
          y = setleg + (b13[i][j] / 1.646);
        } else if ((i == 0) && (j == 1)) {
          y = 79 - (b13[i][j] / 1.646);
        } else if ((i == 1) && (j == 0)) {
          y = setleg + (b13[i][j] / 1.646);
        } else if ((i == 1) && (j == 1)) {
          y = setleg - (b13[i][j] / 1.646);
        } else if ((i == 2) && (j == 0)) {
          y = 79 - (b13[i][j] / 1.646);
        } else if ((i == 2) && (j == 1)) {
          y = setleg + (b13[i][j] / 1.646);
        } else if ((i == 3) && (j == 0)) {
          y = setleg - (b13[i][j] / 1.646);
        } else if ((i == 3) && (j == 1)) {
          y = 75 + (b13[i][j] / 1.646);
        }
        servo[i][j].write(y);
        delay(lb);
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        if ((i == 0) && (j == 0)) {
          y = setleg + (b14[i][j] / 1.646);
        } else if ((i == 0) && (j == 1)) {
          y = 79 - (b14[i][j] / 1.646);
        } else if ((i == 1) && (j == 0)) {
          y = setleg + (b14[i][j] / 1.646);
        } else if ((i == 1) && (j == 1)) {
          y = setleg - (b14[i][j] / 1.646);
        } else if ((i == 2) && (j == 0)) {
          y = 79 - (b14[i][j] / 1.646);
        } else if ((i == 2) && (j == 1)) {
          y = setleg + (b14[i][j] / 1.646);
        } else if ((i == 3) && (j == 0)) {
          y = setleg - (b14[i][j] / 1.646);
        } else if ((i == 3) && (j == 1)) {
          y = 75 + (b14[i][j] / 1.646);
        }
        servo[i][j].write(y);
        delay(lb);
      }
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        if ((i == 0) && (j == 0)) {
          y = setleg + (b15[i][j] / 1.646);
        } else if ((i == 0) && (j == 1)) {
          y = 79 - (b15[i][j] / 1.646);
        } else if ((i == 1) && (j == 0)) {
          y = setleg + (b15[i][j] / 1.646);
        } else if ((i == 1) && (j == 1)) {
          y = setleg - (b15[i][j] / 1.646);
        } else if ((i == 2) && (j == 0)) {
          y = 79 - (b15[i][j] / 1.646);
        } else if ((i == 2) && (j == 1)) {
          y = setleg + (b15[i][j] / 1.646);
        } else if ((i == 3) && (j == 0)) {
          y = setleg - (b15[i][j] / 1.646);
        } else if ((i == 3) && (j == 1)) {
          y = 75 + (b15[i][j] / 1.646);
        }
        servo[i][j].write(y);
        delay(lb);
      }
    }
  }
}
