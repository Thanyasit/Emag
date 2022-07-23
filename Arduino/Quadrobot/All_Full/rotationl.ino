const int rotationl_1[4][3] = { {120, 61, 38}, {60, 117, 142}, {120, 61, 38}, {60, 118, 145} };
const int rotationl_2[4][3] = { {120, 61, 38}, {60, 112, 85}, {120, 61, 38}, {60, 113, 88} };
const int rotationl_3[4][3] = { {120, 61, 38}, {60, 117, 85}, {120, 61, 38}, {60, 118, 88} };
const int rotationl_4[4][3] = { {120, 61, 93}, {60, 117, 142}, {120, 61, 93}, {60, 118, 145} };
const int rotationl_5[4][3] = { {120, 66, 38}, {60, 117, 142}, {120, 66, 38}, {60, 118, 145} };
const int rotationl_6[4][3] = { {120, 61, 38}, {60, 117, 142}, {120, 61, 38}, {60, 118, 145} };
void rotationl(){
  for(int i=0;i<2;i++){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationl_1[i][j]);
        delayr();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationl_2[i][j]);
        delayr();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationl_3[i][j]);
        delayr();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationl_4[i][j]);
        delayr();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationl_5[i][j]);
        delayr();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationl_6[i][j]);
        delayr();
      }
    }
  }
    walk();
}
