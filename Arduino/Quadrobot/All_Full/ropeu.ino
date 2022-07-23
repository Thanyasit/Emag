const int ropeu_1[4][3] = { {70, 111, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int ropeu_2[4][3] = { {90, 111, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int ropeu_3[4][3] = { {120, 61, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int ropeu_4[4][3] = { {120, 61, 37}, {60, 117, 142}, {120, 61, 37}, {120, 65, 147} };
const int ropeu_5[4][3] = { {120, 61, 37}, {60, 117, 142}, {120, 61, 37}, {90, 65, 147} };
const int ropeu_6[4][3] = { {1200, 61, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
void ropeu(){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(ropeu_1[i][j]);
       delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(ropeu_2[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(ropeu_3[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(ropeu_4[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(ropeu_5[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(ropeu_6[i][j]);
        delayc();
      }
    }
    count = 5;
    walk();
}
