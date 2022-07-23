const int climbd_1[4][3] = { {120, 61, 37}, {60, 117, 142}, {120, 111, 37}, {60, 118, 147} };
const int climbd_2[4][3] = { {120, 61, 37}, {60, 117, 142}, {90, 111, 37}, {60, 118, 147} };
const int climbd_3[4][3] = { {120, 61, 37}, {60, 117, 142}, {95, 106, 37}, {60, 118, 147} };
const int climbd_4[4][3] = { {120, 61, 37}, {60, 62, 142}, {90, 96, 37}, {60, 118, 147} };
const int climbd_5[4][3] = { {120, 61, 37}, {90, 62, 142}, {90, 96, 37}, {60, 118, 147} };
const int climbd_6[4][3] = { {120, 61, 37}, {85, 67, 142}, {90, 96, 37}, {60, 118, 147} };

const int climbd_7[4][3] = { {125, 66, 37}, {83, 67, 142}, {96, 99, 37}, {64, 122, 147} };
const int climbd_8[4][3] = { {120, 61, 37}, {83, 67, 142}, {96, 99, 37}, {64, 122, 147} };
const int climbd_9[4][3] = { {118, 59, 37}, {81, 66, 142}, {95, 96, 37}, {66, 124, 147} };
const int climbd_10[4][3] = { {118, 59, 37}, {81, 66, 142}, {80, 96, 37}, {66, 124, 147} };
const int climbd_11[4][3] = { {116, 57, 37}, {79, 65, 142}, {90, 97, 37}, {55, 113, 147} };
const int climbd_12[4][3] = { {116, 57, 37}, {79, 65, 142}, {92, 97, 37}, {60, 118, 147} };
const int climbd_13[4][3] = { {114, 55, 37}, {75, 64, 142}, {94, 98, 37}, {50, 118, 147} };
const int climbd_14[4][3] = { {114, 55, 37}, {85, 64, 142}, {94, 98, 37}, {62, 120, 147} };

void climbd(){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_1[i][j]);
       delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_2[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_3[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_4[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_5[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_6[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_7[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_8[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_9[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_10[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_11[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_12[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_13[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbd_14[i][j]);
        delayc();
      }
    }
    for(int i=0;i<5;i++){
      climbd();
    }
    count = 2;
    walk();
}
