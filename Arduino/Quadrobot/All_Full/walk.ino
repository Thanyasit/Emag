const int walk_1[4][3] = { {125, 66, 37}, {68, 115, 141}, {116, 67, 37}, {64, 122, 147} };
const int walk_2[4][3] = { {120, 61, 37}, {68, 115, 141}, {116, 67, 37}, {64, 122, 147} };
const int walk_3[4][3] = { {118, 59, 37}, {66, 113, 141}, {100, 51, 37}, {66, 124, 147} };
const int walk_4[4][3] = { {118, 59, 37}, {66, 113, 141}, {110, 61, 37}, {66, 124, 147} };
const int walk_5[4][3] = { {116, 57, 37}, {64, 111, 141}, {112, 63, 37}, {55, 113, 147} };
const int walk_6[4][3] = { {116, 57, 37}, {64, 111, 141}, {112, 63, 37}, {60, 118, 147} };
const int walk_7[4][3] = { {114, 55, 37}, {80, 127, 141}, {114, 65, 37}, {50, 118, 147} };
const int walk_8[4][3] = { {114, 55, 37}, {70, 117, 141}, {114, 65, 37}, {62, 120, 147} };
void walk(){
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(walk_1[i][j]);
        delayw();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(walk_2[i][j]);
        delayw();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(walk_3[i][j]);
        delayw();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(walk_4[i][j]);
        delayw();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(walk_5[i][j]);
        delayw();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(walk_6[i][j]);
        delayw();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(walk_7[i][j]);
        delayw();
      }
    }
    for (int i = 0; i < 4; i++){
      for (int j = 0; j < 3; j++){
        servo[i][j].write(walk_8[i][j]);
        delayw();
      }
    }
    if(count == 1){
      for(int i=0 ;i<3;i++){
        walk();
      }
      count = 0;
      climbd();
    }else if(count ==2){
      for(int i=0 ;i<3;i++){
        walk();
      }
      count = 3;
      rotationr(); 
    }else if(count ==3){
      for(int i=0 ;i<8;i++){
        walk();
      }
      count == 4;
      rotationl();
    }else if(count == 4){
       for(int i=0 ;i<8;i++){
        walk();
      }
      ropeu();
    }else if(count ==5){
      for(int i=0 ;i<3;i++){
        walk();
      }
      roped();
    }
}
