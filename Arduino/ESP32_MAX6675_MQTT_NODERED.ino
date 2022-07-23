/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com
*********/
//Used MAX6675
//Adjust be emag
#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "Max6675.h"

Max6675 ts(15, 4, 5);

// Replace the next variables with your SSID/Password combination
const char* ssid = "Printer";
const char* password = "";

// Add your MQTT Broker IP address, example:
//const char* mqtt_server = "192.168.1.144";
const char* mqtt_server = "10.4.31.200";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;


float temperature = 0;
float humidity = 0;


void setup() {
  ts.setOffset(0);
  Serial.begin(115200);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

  pinMode(LED_BUILTIN, OUTPUT);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  // Feel free to add more if statements to control more GPIOs with MQTT

  // If a message is received on the topic esp32/output, you check if the message is either "on" or "off".
  // Changes the output state according to the message
  if (String(topic) == "esp32/output") {
    Serial.print("Changing output to ");
    if (messageTemp == "on") {
      Serial.println("on");
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else if (messageTemp == "off") {
      Serial.println("off");
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
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
void loop() {
  long now = millis();
  if (now - lastMsg > 450000) {
 // if (now - lastMsg > 10000) {
    lastMsg = now;
    if (!client.connected()) {
      reconnect();
    }
    client.loop();
    // Temperature in Celsius
    temperature = ts.getCelsius();
//    if (temperature > 150) {
//      ESP.restart();
//    }
    // Uncomment the next line to set temperature in Fahrenheit
    // (and comment the previous temperature line)
    //temperature = 1.8 * bme.readTemperature() + 32; // Temperature in Fahrenheit

    // Convert the value to a char array
    char tempString[8];
    dtostrf(temperature, 1, 2, tempString);
    Serial.print("Temperature: ");
    Serial.println(tempString);
    client.publish("esp32/temperature", tempString);

  }
}
