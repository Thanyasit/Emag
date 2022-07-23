//Used esp8266 get value from bme280 then sent to line
//by Emag
#include <ESP8266WiFi.h>
#include <WiFiClientSecureAxTLS.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <time.h>
#include <TimeLib.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme; // กำหนดค่า address I2C กรณีเป็นตำแหน่งอื่น แก้เป็น Adafruit_BME280 bme(ตำแหน่ง address i2c)
unsigned long delayTime;
int timezone = 7 * 3600; //ตั้งค่า TimeZone ตามเวลาประเทศไทย
int dst = 0;              //กำหนดค่า Date Swing Time
int count = 0;
int savehour = 0;
int savemin = 0;
int ckh = 0; //checktimehour
bool A = 0;//count
int ckm = 0; //checktimehour
String  message1;
String  message3;
String  message2;
String  message4;
float humid;
float temp;
#define LINE_TOKEN "gy1g40LlzDW5LJMMOZcYRTIMwFxN1vPlYHy3pKVAKT6"
//#define LINE_TOKEN "VC1kkIbAIGfN48coR8FIOneaTCrfVtFCWOkSUPkm0Rs" //?
//#define LINE_TOKEN "UuWAtAyXdgbT9ZYLEmoIQkyXk3UDzOJ8Jk2YdH6mAaS"//ห้องเย็น 
char buf[20];
void setup() {
  delay(200);
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW); 
  Serial.begin(115200);
  bool status;
  status = bme.begin();
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  Serial.setDebugOutput(true);
  WiFiManager wifiManager;
  wifiManager.setTimeout(180);
  if (!wifiManager.autoConnect("AutoConnectAP2"))
  {
    Serial.println("Failed to connect and hit timeout");
    delay(1000);
    ESP.reset();
    delay(2000);
  }
  WiFi.printDiag(Serial);
  Serial.println();
  Serial.println("connected...OK");
  configTime(timezone, dst, "pool.ntp.org", "time.nist,gov");  //ดึงเวลาจาก Server
  Serial.println("\nWaiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
}

void loop() {
  digitalWrite(16, LOW); 
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(250);
    Serial.print(".");
    digitalWrite(16, HIGH); 
    count++;
    if (count == 20) {
      delay(1000);
      ESP.reset();
      delay(2000);
    }
  }
  time_t now = time(nullptr);
  Serial.println(ctime(&now));
  struct tm* p_tm = localtime(&now);
  Serial.print("Hour = ");
  Serial.println(p_tm->tm_hour);
  Serial.println(ckh);
  Serial.println(ckm);
  if (A == 0) {
    ckh = p_tm->tm_hour;
    if (p_tm->tm_min > 45) {
      ckh++;
    }
  }
  if (p_tm->tm_min > 30) {
    ckm = 45;
  } else if (p_tm->tm_min > 15) {
    ckm = 30;
  } else if (p_tm->tm_min > 0) {
    ckm = 15;
  } else {
    ckm = 0;
  }
  if (p_tm->tm_hour == ckh && p_tm->tm_min == ckm && p_tm->tm_sec == 45 ) {
    humid = bme.readHumidity();
    temp = bme.readTemperature();
    message1 = dtostrf(humid, 3, 3, buf);
    message2 = " Humid = " + message1;
    message3 = dtostrf(temp, 3, 3, buf) + message2;
    message4 = "2 Notify Temp = " + message3;
    Serial.println("Notify");
    Line_Notify(message4);
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print(" , Humid: ");
    Serial.println(humid);
    //delay(1000);
    A = 1;
    if (ckm >= 45) {
      ckh++;
    }
    if (ckh == 24) {
      ckh = 0;
    }
  }
  delay(300);
  //delay(0);
}
void Line_Notify(String message) {
  axTLS::WiFiClientSecure client;
  if (!client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    return;
  }
  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Connection: close\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;
  client.print(req);
  delay(20);
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }
}
