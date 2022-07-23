const int climbu_1[4][3] = { {70, 111, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int climbu_2[4][3] = { {90, 111, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int climbu_3[4][3] = { {90, 96, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int climbu_4[4][3] = { {90, 96, 37}, {60, 117, 142}, {120, 61, 37}, {120, 65, 147} };
const int climbu_5[4][3] = { {90, 96, 37}, {60, 117, 142}, {120, 61, 37}, {90, 65, 147} };
const int climbu_6[4][3] = { {90, 96, 37}, {60, 117, 142}, {120, 61, 37}, {90, 80, 147} };

const int climbu_7[4][3] = { {70, 116, 37}, {58, 116, 142}, {126, 64, 37}, {94, 82, 147} };
const int climbu_8[4][3] = { {90, 96, 37}, {58, 116, 142}, {126, 64, 37}, {94, 82, 147} };
const int climbu_9[4][3] = { {88, 96, 37}, {56, 115, 142}, {110, 46, 37}, {96, 83, 147} };
const int climbu_10[4][3] = { {88, 96, 37}, {56, 115, 142}, {120, 61, 37}, {96, 83, 147} };
const int climbu_11[4][3] = { {86, 95, 37}, {54, 114, 142}, {122, 62, 37}, {120, 60, 147} };
const int climbu_12[4][3] = { {86, 95, 37}, {54, 114, 142}, {122, 62, 37}, {90, 80, 147} };
const int climbu_13[4][3] = { {84, 94, 37}, {70, 132, 142}, {124, 63, 37}, {92, 81, 147} };
const int climbu_14[4][3] = { {84, 94, 37}, {60, 117, 142}, {124, 63, 37}, {92, 81, 147} };
void climbu(){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_1[i][j]);
       delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_2[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_3[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_4[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_5[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_6[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_7[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_8[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_9[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_10[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_11[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_12[i][j]);
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_13[i][j]);
       delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbu_14[i][j]);
        delayc();
      }
    }
}
