/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com
*********/
//Used DHT11
//Adjust By Emag

#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include "DHT.h"
// Replace the next variables with your SSID/Password combination
const char* ssid = "Printer";
const char* password = "";


const char* mqtt_server = "10.4.31.200";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

float temperature = 0;
float humidity = 0;

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(115200);
  dht.begin();

  setup_wifi();
  client.setServer(mqtt_server, 1883);

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
  if (now - lastMsg > 900000) {
  //if (now - lastMsg > 10000) {
    lastMsg = now;
    if (!client.connected()) {
      reconnect();
    }
    client.loop();
    temperature = dht.readTemperature();
    if (temperature > 51) {
      ESP.restart();
    }
    char tempString[8];
    dtostrf(temperature, 1, 2, tempString);
    Serial.print("Temperature: ");
    Serial.println(tempString);
    client.publish("esp32/temperatureserverroom", tempString);

    humidity = dht.readHumidity();

    // Convert the value to a char array
    char humString[8];
    dtostrf(humidity, 1, 2, humString);
    Serial.print("Humidity: ");
    Serial.println(humString);
    client.publish("esp32/humidityserverroom", humString);
  }
}
