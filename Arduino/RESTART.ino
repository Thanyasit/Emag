int i;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  Serial.begin(9600);//initialize the serial port
  i=0;
}
void(* resetFunc) (void) = 0; //declare reset function @ address 0


// the loop routine runs over and over again forever:
void loop() {
  Serial.println(i);
  i++;
  delay(1000);               // wait for a second
  Serial.println("resetting");
  resetFunc();  //call reset
  delay(100);
}




