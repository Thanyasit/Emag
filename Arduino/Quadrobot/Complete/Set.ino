void Setstand(){ 
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(stand[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(stand[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(stand[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(stand[i][j]/1.646);//2
      }else if((i==2)&&(j==0)){
        y=79-(stand[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(stand[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(stand[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(stand[i][j]/1.646);//29   71
      } 
      servo[i][j].write(y);
      delay(15);//10
    }
  }
}
void Setstandj(){ 
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(standj[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(stand[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(standj[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(standj[i][j]/1.646);//2
      }else if((i==2)&&(j==0)){
        y=79-(standj[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(standj[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(standj[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(standj[i][j]/1.646);//29   71
      } 
      servo[i][j].write(y);
      delay(15);//10
    }
  }
}
void Standdog(){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(standdog[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(standdog[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(standdog[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(standdog[i][j]/1.646);//2
      }else if((i==2)&&(j==0)){
        y=79-(standdog[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(standdog[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(standdog[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(standdog[i][j]/1.646);//29   71
      } 
      servo[i][j].write(y);
      delay(25);//10
    }
  }
}
void Sit(){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(sit[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(sit[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(sit[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(sit[i][j]/1.646);//2
      }else if((i==2)&&(j==0)){
        y=79-(sit[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(sit[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(sit[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(sit[i][j]/1.646);//29   71
      } 
      servo[i][j].write(y);
      delay(20);//10
    }
  }
  delay(500);
   for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(sit2[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(sit2[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(sit2[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(sit2[i][j]/1.646);//2
      }else if((i==2)&&(j==0)){
        y=79-(sit2[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(sit2[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(sit2[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(sit2[i][j]/1.646);//29   71
      } 
      servo[i][j].write(y);
      delay(20);//10
    }
  }
}
void Setstandb(){ 
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(standb[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(standb[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(standb[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(standb[i][j]/1.646);//2
      }else if((i==2)&&(j==0)){
        y=79-(standb[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(standb[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(standb[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(standb[i][j]/1.646);//29   71
      } 
      servo[i][j].write(y);
      delay(15);//10
    }
  }
}
void Setstandc(){ 
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(sit[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(sit[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(sit[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(sit[i][j]/1.646);//2
      }else if((i==2)&&(j==0)){
        y=79-(sit[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(sit[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(sit[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(sit[i][j]/1.646);//29   71
      } 
      servo[i][j].write(y);
      delay(20);//10
    }
  }
  delay(500);
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(standc[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(standc[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(standc[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(standc[i][j]/1.646);//2
      }else if((i==2)&&(j==0)){
        y=79-(standc[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(standc[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(standc[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(standc[i][j]/1.646);//29   71
      } 
      servo[i][j].write(y);
      delay(20);//10
    }
  }
}
void Setstandh(){ 
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(standh[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(standh[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(standh[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(standh[i][j]/1.646);//2
      }else if((i==2)&&(j==0)){
        y=79-(standh[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(standh[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(standh[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(standh[i][j]/1.646);//29   71
      } 
      servo[i][j].write(y);
      delay(15);//10
    }
  }
}
void Setstandjk(){ 
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 2; j++){ 
      if((i==0)&&(j==0)){
        y=setleg+(standjk[i][j]/1.646);//22
      }else if((i==0)&&(j==1)){
        y=79-(standjk[i][j]/1.646);//23
      }else if((i==1)&&(j==0)){
        y=setleg+(standjk[i][j]/1.646);//24
      }else if((i==1)&&(j==1)){
        y=setleg-(standjk[i][j]/1.646);//2
      }else if((i==2)&&(j==0)){
        y=79-(standjk[i][j]/1.646);//26
      }else if((i==2)&&(j==1)){
        y=setleg+(standjk[i][j]/1.646);//27
      }else if((i==3)&&(j==0)){
        y=setleg-(standjk[i][j]/1.646);//28
      }else if((i==3)&&(j==1)){
        y=75+(standjk[i][j]/1.646);//29   71
      } 
      servo[i][j].write(y);
      delay(15);//10
    }
  }
}
