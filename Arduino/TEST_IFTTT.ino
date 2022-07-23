// Example By ArduinoAll.com
// adjust for ESP32 By Emag
//#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>

#include <WiFi.h>
#include <HTTPClient.h>
//ตั้งค่า wifi
const char* ssid = "Test"; // ชื่อ
const char* password = "1212312121"; // รหัสผ่าน


// ตั้งค่า IFTTT
String event = "measure temperature"; // ชื่อ event
String key = "c_6eqjfQbJOgpG5VBeq9xM"; // Key

String sheets = "";
void setup () {
  //สำหรับ esp8266 url ตรง https ให้เปลี่ยนเป็น http
  sheets = "https://maker.ifttt.com/trigger/measure temperature/with/key/c_6eqjfQbJOgpG5VBeq9xM?value1=666&value2=999"; // url ที่ส่งค่าลง google sheet

  Serial.begin(115200);
  Serial.println(sheets);
  WiFi.begin(ssid, password);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) { //ถ้าเชื่อมต่อสำเร็จ

    HTTPClient http;
    http.begin(sheets); //กำหนด url เพื่อเซฟข้อมูลลง google sheets
    int httpCode = http.GET(); //ส่งค่า url

    if (httpCode > 0) { //ถ้าส่งสำเร็จ

      String payload = http.getString();// อ่านค่าผลลัพธ์
      Serial.println(payload);
    }
    http.end(); //ปิดการเชื่อมต่อ

  }
  delay(5000); //หน่วงเวลา เซฟข้อมูลทุก 5 วินาที
}
