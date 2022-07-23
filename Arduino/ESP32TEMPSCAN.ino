//K3 Thermal Scanner 
//used esp32 get value 
//By Emag

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
}
uint8_t cnt = 0;
byte highByteVal = 0;
byte lowByteVal = 0;
float temperatureVal = 0;
byte buf=0;
void loop() {

  while (Serial2.available()) {
    //String buf = String(Serial2.read(), DEC);
    //int A = buf.toInt();
    buf = Serial2.read();
    cnt++;
    if (cnt == 4 ) {
      lowByteVal = buf;
      //Serial.print("lowByteVal");
      //Serial.println(lowByteVal);
    } else if (cnt == 5) {
      highByteVal = buf;
    } else if (cnt == 6) {
      temperatureVal = word(highByteVal, lowByteVal) * 0.1;
      Serial.print("Temperature : ");
      Serial.println(temperatureVal);
      cnt = 0;
    }
    //Serial.print("A ");
    //Serial.println(buf);
    //Serial.println(cnt);
  }

}
