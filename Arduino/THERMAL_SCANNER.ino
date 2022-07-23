//K3 Thermal Scanner 
//used esp32 get value then sent to line
//By Emag


#include <WiFi.h>
#include <HTTPClient.h>
#include <TridentTD_LineNotify.h>
const char* ssid = "Printer"; // ชื่อ
//const char* password = "1212312121"; // รหัสผ่าน

#define LINE_TOKEN  "TbbOPGmscOSpw4fg0KFEV9ou8pKVs1jrcPjXazzVHix"

// ตั้งค่า IFTTT
String event = "measure temperature"; // ชื่อ event
String key = "c_6eqjfQbJOgpG5VBeq9xM"; // Key

String sheets = "";

uint8_t cnt = 0;
byte highByteVal = 0;
byte lowByteVal = 0;
float temperatureVal = 0;
byte buf = 0;

bool i = 0;
void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
  Serial.println(sheets);
  Serial.println(LINE.getVersion());
  pinMode(LED_BUILTIN, OUTPUT);
  WiFi.begin(ssid);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {

    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
    Serial.print(".");
  }
  Serial.println("Connected");
  LINE.setToken(LINE_TOKEN);
  digitalWrite(LED_BUILTIN, LOW);
}
void loop() {
  while (Serial2.available()) {
    buf = Serial2.read();
    cnt++;
    if (cnt == 4 ) {
      lowByteVal = buf;
    } else if (cnt == 5) {
      highByteVal = buf;
    } else if (cnt == 6) {
      temperatureVal = word(highByteVal, lowByteVal) * 0.1;
      Serial.print("Temperature : ");
      Serial.println(temperatureVal);
      if (temperatureVal > 150) {
        ESP.restart();
      } else if (temperatureVal >= 37.3) {
        String Text2 = "Alarm temperature more than 37.3";
        String Text3 = " °C";
        String Text1 = Text2 + Text3;
        LINE.notify(Text1);
      }
      sheets = "https://maker.ifttt.com/trigger/measure temperature/with/key/c_6eqjfQbJOgpG5VBeq9xM?value1=" + String(temperatureVal);
      if (WiFi.status() == WL_CONNECTED) { //ถ้าเชื่อมต่อสำเร็จ
        HTTPClient http;
        http.begin(sheets); //กำหนด url เพื่อเซฟข้อมูลลง google sheets
        int httpCode = http.GET(); //ส่งค่า url
        if (httpCode > 0) { //ถ้าส่งสำเร็จ
          String payload = http.getString();// อ่านค่าผลลัพธ์
          Serial.println(payload);
        }
        http.end(); //ปิดการเชื่อมต่อ
        //delay(5000); //หน่วงเวลา เซฟข้อมูลทุก 5 วินาที
      }
      cnt = 0;
    }
  }
  while (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();
    //WiFi.disconnect();
    //WiFi.begin(ssid, password);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(2000);
    Serial.print(".");
    i = 1;
  }
  if (i == 1) {
    Serial.println("Connected");
    i = 0;
  }
}
