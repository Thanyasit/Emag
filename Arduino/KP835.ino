//used esp32 get value for kp-835 with modbus Rs485 then sent to nodered with mqtt
//By Emag
//#include <SoftwareSerial.h>
#include <ModbusMaster.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
//SoftwareSerial mySerial(2, 3); // RX, TX

#define MAX485_DE 5
#define MAX485_RE_NEG 4

ModbusMaster node;
const char* ssid = "Printer";
const char* password = "";


const char* mqtt_server = "10.4.31.200";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;
//*******************************************************************//
// Convent 32bit to float // ฟังชั่นแปลง 32bit ไปเป็น ทศนิยม *** เผื่อใช้
//*******************************************************************//
float HexTofloat(uint32_t x) {
  return (*(float*)&x);
}

uint32_t FloatTohex(float x) {
  return (*(uint32_t*)&x);
}// End

void preTransmission()
{
  digitalWrite(MAX485_RE_NEG, 1);
  digitalWrite(MAX485_DE, 1);
}

void postTransmission()
{
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  pinMode(MAX485_RE_NEG, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // Init in receive mode
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
  Serial.println("start init serial 0");
  Serial.begin(9600);

  while (!Serial) {
    Serial.println("loop for init serial 0");
  }
  Serial.println("start init software serial");
  Serial2.begin(9600);
  while (!Serial2) {
    Serial.println("loop for init software serial");
  }

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  //client.setCallback(callback);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  node.begin(1, Serial2);
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
}

void loop() {
  long now = millis();
  if (now - lastMsg > 450000) {
    //if (now - lastMsg > 10000) {
    lastMsg = now;
    while (WiFi.status() != WL_CONNECTED) {
      digitalWrite(LED_BUILTIN, HIGH);
      delay(250);
      digitalWrite(LED_BUILTIN, LOW);
      delay(250);
      Serial.print(".");
    }
    if (!client.connected()) {
      reconnect();
    }
    client.loop();

    uint16_t result;
    uint32_t x;
    float power;
    //uint16_t data[1];
    Serial.println("Get data");
    result = node.readInputRegisters(0x0048, 0x0002);
    if (result == node.ku8MBSuccess)
    {
      Serial.print("Voltage: ");
      x = (node.getResponseBuffer(0) << 16) | node.getResponseBuffer(1);
      power = HexTofloat(x);
      Serial.println(power);
    }
    //    if (temperature > 51) {
    //      ESP.restart();
    //    }
    char powerString[8];
    dtostrf(power, 1, 1, powerString);
    Serial.print("powerA: ");
    //powerA
    //pumppowerB
    Serial.println(powerString);
    client.publish("esp32/powerA", powerString);
    //powerA
    //pumppowerB
  }
}
