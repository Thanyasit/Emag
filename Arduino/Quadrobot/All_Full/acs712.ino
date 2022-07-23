void Acs712(){
  for(int i = 0; i < 1000; i++) {
  average = average + (.0264 * analogRead(A0) -13.51) / 1000;
  delay(1);
  }
}
