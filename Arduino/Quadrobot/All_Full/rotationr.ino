const int rotationr_1[4][3] = { {120, 61, 38}, {60, 117, 142}, {120, 61, 38}, {60, 118, 145} };
const int rotationr_2[4][3] = { {120, 66, 93}, {60, 117, 142}, {120, 66, 93}, {60, 118, 145} };
const int rotationr_3[4][3] = { {120, 61, 93}, {60, 117, 142}, {120, 61, 93}, {60, 118, 145} };
const int rotationr_4[4][3] = { {120, 61, 38}, {60, 117, 85}, {120, 61, 38}, {60, 118, 88} };
const int rotationr_5[4][3] = { {120, 61, 38}, {60, 112, 142}, {120, 61, 38}, {60, 113, 145} };
const int rotationr_6[4][3] = { {120, 61, 38}, {60, 117, 142}, {120, 61, 38}, {60, 118, 145} };
void rotationr(){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationr_1[i][j]);
        delayr();
      }
    }
    delayr();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationr_2[i][j]);
        delayr();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationr_3[i][j]);
        delayr();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationr_4[i][j]);
        delayr();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationr_5[i][j]);
        delayr();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(rotationr_6[i][j]);
        delayr();
      }
    }
    walk();
}
