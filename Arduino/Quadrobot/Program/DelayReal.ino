void utrasonic() {
  ct = millis();
  digitalWrite(tl, LOW);
  delayMicroseconds(2);
  digitalWrite(tl, HIGH);
  delayMicroseconds(5);
  digitalWrite(tl, LOW);
  duration = pulseIn(el, HIGH, 5000);
  cm = duration* 0.0173681;
  int ge = millis()-ct;
  int Delay = l-ge;
  if(a==0){
    if(cm<12){
      t=2;
      d=1;
      a=1;
      l=20;
    }
  }else if(a==1){
    if(cm>12){
      a=3;
    }
  }else if(a==3){
    count++;
    if(count>400){
      t=1;
      d=1;
      l=15;
      a=0;
    }
  }

  Serial.print("count:");
  Serial.println(count);
  Serial.print("t:");
  Serial.println(t);
  Serial.print("d:");
  Serial.println(d);
  Serial.print("cm:");
  Serial.println(cm);
  Serial.print("a:");
  Serial.println(a);
  delay(Delay);
  Serial.print("delay:");
  Serial.println(Delay);
}
