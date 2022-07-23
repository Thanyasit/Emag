const int roped_1[4][3] = { {70, 111, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int roped_2[4][3] = { {90, 111, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int roped_3[4][3] = { {120, 61, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
const int roped_4[4][3] = { {120, 61, 37}, {60, 117, 142}, {120, 61, 37}, {120, 65, 147} };
const int roped_5[4][3] = { {120, 61, 37}, {60, 117, 142}, {120, 61, 37}, {90, 65, 147} };
const int roped_6[4][3] = { {1200, 61, 37}, {60, 117, 142}, {120, 61, 37}, {60, 118, 147} };
void roped(){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(roped_1[i][j]);
       delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(roped_2[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(roped_3[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(roped_4[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(roped_5[i][j]);
        delayc();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(roped_6[i][j]);
        delayc();
      }
    }
    nrope++;
    if(nrope =2){
      count = 3;
    }else{
      count = 4;
    }
    walk();
}
