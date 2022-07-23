//Used DHT11
//Adjust By Emag
#include <TridentTD_LineNotify.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
#define SSID        "Printer"
//#define PASSWORD    "1212312121"
#define LINE_TOKEN  "TbbOPGmscOSpw4fg0KFEV9ou8pKVs1jrcPjXazzVHix"

DHT dht(DHTPIN, DHTTYPE);

float h = 0;
float t = 0;
float hic = 0;
bool i = 0;

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());

  WiFi.begin(SSID);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    delay(250);
    Serial.print(".");
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);
  digitalWrite(LED_BUILTIN, LOW);
  dht.begin();
}

void loop() {
  dht11();
  String Hum;
  String Hum1 = "Humidity: ";
  String Hum2 = " %";
  Hum = Hum1 + h + Hum2;
  LINE.notify(Hum);
  String Temp;
  String Temp1 = "Temperature: ";
  String Temp2 = " °C";
  Temp = Temp1 + t + Temp2;
  LINE.notify(Temp);
  String Heat;
  String Heat1 = "Heat index: ";
  Heat = Heat1 + hic;
  LINE.notify(Heat);
  //LINE.notify("Temperature: ");
  //LINE.notify(t,"°C");
  //LINE.notify("Heat index: ");
  //LINE.notify(hic);
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
void dht11() {
  // Wait a few seconds between measurements.s
  delay(900000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
