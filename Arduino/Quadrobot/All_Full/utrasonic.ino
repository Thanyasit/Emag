void utrasonic(){
  if(utra ==0){
    digitalWrite(tl, LOW);
    delayMicroseconds(2);
    digitalWrite(tl, HIGH);
    delayMicroseconds(5);
    digitalWrite(tl, LOW);
    durationl = pulseIn(el, HIGH, 6000);
    cml = durationl * 0.0173681;
    Serial.print("cml ");
    Serial.print(cml);
    Serial.print(" cm");
    Serial.println();  
    utra++;
  }else if(utra == 1){
    digitalWrite(tr, LOW);
    delayMicroseconds(2);
    digitalWrite(tr, HIGH);
    delayMicroseconds(5);
    digitalWrite(tr, LOW);
    durationr = pulseIn(er, HIGH, 6500);
    cmr = durationr * 0.0173681;
    Serial.print("cmr ");
    Serial.print(cmr);
    Serial.print(" cm");
    Serial.println();  
    utra++;
  }else if(utra ==2){
    digitalWrite(tb, LOW);
    delayMicroseconds(2);
    digitalWrite(tb, HIGH);
    delayMicroseconds(5);
    digitalWrite(tb, LOW);
    durationb = pulseIn(eb, HIGH, 6500);
    cmb = durationb * 0.0173681;
    Serial.print("cmb ");
    Serial.print(cmb);
    Serial.print(" cm");
    Serial.println();  
    utra=0;
  }
}
   
