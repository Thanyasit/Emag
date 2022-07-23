const int jump1[4][2] = { {24, 43}, {24, 43}, {24, 43}, {24, 43} };//275
const int jump2[4][2] = { {42, 7}, {42, 7}, {42, 7}, {42, 7} }; //225
const int jump3[4][2] = { {53, -16}, {53, -16}, {53, -16}, {53, -16} }; //180
const int jump4[4][2] = { {48, -6}, {48, -6}, {48, -6}, {48, -6} };// 200
const int jump5[4][2] = { {34, 23}, {34, 23}, {34, 23}, {34, 23} };// 250
void Jump(){
  for(int k=0 ;k<15; k++){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){
      if((i==0)&&(j==0)){
        y=setleg+(jump2[i][j]/1.646);
      }else if((i==0)&&(j==1)){
        y=79-(jump2[i][j]/1.646);
      }else if((i==1)&&(j==0)){
        y=setleg+(jump2[i][j]/1.646);
      }else if((i==1)&&(j==1)){
        y=setleg-(jump2[i][j]/1.646);
      }else if((i==2)&&(j==0)){
        y=79-(jump2[i][j]/1.646);
      }else if((i==2)&&(j==1)){
        y=setleg+(jump2[i][j]/1.646);
      }else if((i==3)&&(j==0)){
        y=setleg-(jump2[i][j]/1.646);
      }else if((i==3)&&(j==1)){
        y=75+(jump2[i][j]/1.646);
      }
      servo[i][j].write(y);
      delay(10);
    }
  }
  delay(200);
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){
      if((i==0)&&(j==0)){
        y=setleg+(jump1[i][j]/1.646);
      }else if((i==0)&&(j==1)){
        y=79-(jump1[i][j]/1.646);
      }else if((i==1)&&(j==0)){
        y=setleg+(jump1[i][j]/1.646);
      }else if((i==1)&&(j==1)){
        y=setleg-(jump1[i][j]/1.646);
      }else if((i==2)&&(j==0)){
        y=79-(jump1[i][j]/1.646);
      }else if((i==2)&&(j==1)){
        y=setleg+(jump1[i][j]/1.646);
      }else if((i==3)&&(j==0)){
        y=setleg-(jump1[i][j]/1.646);
      }else if((i==3)&&(j==1)){
        y=75+(jump1[i][j]/1.646);
      }
      servo[i][j].write(y);
      delay(10);
    }
  }    
  }
}
