const int climbw_1[4][3] = { {70, 111, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int climbw_2[4][3] = { {90, 111, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int climbw_3[4][3] = { {90, 96, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int climbw_4[4][3] = { {90, 96, 37}, {60, 117, 142}, {120, 61, 37}, {120, 65, 147} };
const int climbw_5[4][3] = { {90, 96, 37}, {60, 117, 142}, {120, 61, 37}, {90, 65, 147} };
const int climbw_6[4][3] = { {90, 96, 37}, {60, 117, 142}, {120, 61, 37}, {90, 80, 147} };

const int climbw_7[4][3] = { {70, 116, 37}, {58, 116, 142}, {126, 64, 37}, {94, 82, 147} };
const int climbw_8[4][3] = { {90, 96, 37}, {58, 116, 142}, {126, 64, 37}, {94, 82, 147} };
const int climbw_9[4][3] = { {88, 96, 37}, {56, 115, 142}, {110, 46, 37}, {96, 83, 147} };
const int climbw_10[4][3] = { {88, 96, 37}, {56, 115, 142}, {120, 61, 37}, {96, 83, 147} };
const int climbw_11[4][3] = { {86, 95, 37}, {54, 114, 142}, {122, 62, 37}, {120, 60, 147} };
const int climbw_12[4][3] = { {86, 95, 37}, {54, 114, 142}, {122, 62, 37}, {90, 80, 147} };
const int climbw_13[4][3] = { {84, 94, 37}, {70, 132, 142}, {124, 61, 37}, {92, 81, 147} };
const int climbw_14[4][3] = { {84, 94, 37}, {60, 117, 142}, {124, 61, 37}, {92, 81, 147} };
void climbw(){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_1[i][j]);
       delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_2[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_3[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_4[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_5[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_6[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_7[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_8[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_9[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_10[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_11[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_12[i][j]);
        delay(ct);
      }
    }
    //delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_13[i][j]);
        delay(ct);
      }
    }
    delayc();
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(climbw_14[i][j]);
        delay(ct);
      }
    }
    delayc();
}
