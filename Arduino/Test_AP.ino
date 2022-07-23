#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#define AppName "dashboard"

const char* ssid     = AppName;
const char* password = "12345678";

WebServer server(80);
#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();

void HandleRoot() {
  String s PROGMEM = R"=====(<!DOCTYPE html><html lang="en"><head> <meta charset="UTF-8"> <meta name="viewport" content="width=device-width, initial-scale=1.0"> <meta http-equiv="X-UA-Compatible" content="ie=edge"> <link rel="stylesheet" href="style.css"> <title>ESP32:Dashboard</title></head><body> <div id="container"> <header class="header"> <div><h2>Dashboard</h2></div></header> <main class="main"> <div class="main-overview"> <div class="overviewcard"> <div class="overviewcard__icon">CPU Temp</div><div class="overviewcard__info"><span id="temp">N/A</span> <sup>o</sup>C</div></div><div class="overviewcard"> <div class="overviewcard__icon">LED</div><div class="overviewcard__info"> <input type="checkbox" id="led" onclick="onoff(this)"> </div></div><div class="overviewcard"> <div class="overviewcard__icon">IP</div><div class="overviewcard__info" id="ip">N/A</div></div><div class="overviewcard"> <div class="overviewcard__icon">MAC</div><div class="overviewcard__info" id="mac">N/A</div></div><div class="overviewcard"> <div class="overviewcard__icon">MEM</div><div class="overviewcard__info" id="mem">N/A</div></div></div></main> <footer class="footer"> <div class="footer__copyright">&copy; 2019 </div><div class="footer__signature">ESP32 WebServer Library</div></footer> </div></div><script src="index.js"></script></body></html>)=====";
  server.send(200, "text/html", s);
}

void HandleCss() {
  String css PROGMEM = R"=====( html,body{margin: 0;height: 100%;color: #fff;}#container{display: flex;flex-direction: column;}.header{align-items: center;justify-content: space-between;padding-top: 10px 15px;background-color: #648ca6;width: 100%;}.header h2{margin-left: 15px;}.main{background-color: #8fd4d9;padding-top: 20px;overflow: auto;flex: 1;min-width: 100vw;min-height: 100vh;}.main-header{display: flex;justify-content: space-between;margin: 20px;padding: 20px;height: 50px;background-color: #e3e4e6;color: slategray;}.main-overview{display: grid;grid-template-columns: repeat(auto-fit, minmax(265px, 1fr));grid-auto-rows: 94px;grid-gap: 20px;margin: 20px;}.overviewcard{display: flex;align-items: center;justify-content: space-between;padding: 20px;background-color: #d3d3;}.main-cards{column-count: 1;column-gap: 20px;margin: 20px;}.card{display: flex;flex-direction: column;align-items: center;width: 100%;background-color: #82bef6;margin-bottom: 20px;-webkit-column-break-inside: avoid;padding: 24px;box-sizing: border-box;}.card:first-child{height: 485px;}.card:nth-child(2){height: 200px;}.card:nth-child(3){height: 265px;}.footer{grid-area: footer;display: flex;align-items: center;justify-content: space-between;padding: 0 16px;background-color: #648ca6;} )=====";
  server.send(200, "text/css", css);
}

void HandleJs() {
  String js PROGMEM = R"=====(function onoff(e){var n=new XMLHttpRequest;n.open("POST","onoff",!1),n.send(e.checked),n.response?alert(n.response):alert("UnSuccess!!")}function getData(e){var n=new XMLHttpRequest;n.onreadystatechange=function(){if(4==this.readyState&&200==this.status)for(var e=JSON.parse(this.responseText),n=0;n<e.length;n++)j=e[n],document.getElementById(j.name)&&("led"===j.name?document.getElementById(j.name).checked=j.val:document.getElementById(j.name).innerHTML=j.val),document.getElementById("label_"+j.name)&&(document.getElementById("label_"+j.name).innerHTML=j.name)},n.open("GET",e,!0),n.send()}getData("info"),setInterval(function(){getData("info")},5e3);)=====";
  server.send(200, "application/javascript", js);
}

void HandleOnOff() {
  uint8_t cmd = (server.arg(0) == "true") ? LOW : HIGH;
  String led = (cmd == LOW) ? "ON" : "OFF";

  digitalWrite(LED_BUILTIN, cmd);
  Serial.println(server.arg(0));

  server.send(200, "text/plain", led);
}

void HandleInfo() {
  String data = "[";
  data += "{\"name\": \"temp\",\"val\":" +  CpuTemp() + "}";
  data += ",{\"name\":\"led\",\"val\":" + LedStatus()  + "}";
  data += ",{\"name\":\"mac\",\"val\":\"" + String(WiFi.macAddress()) + "\"}";
  data += ",{\"name\":\"ip\",\"val\":\"" + (WiFi.softAPIP()).toString() + "\"}";
  data += ",{\"name\":\"mem\",\"val\":\"" + String(esp_get_free_heap_size() / 1024) + " KB\"}";

  data += "]";

  server.send(200, "application/json", data);
}

String CpuTemp() {

  int temp = ((temprature_sens_read() - 32) / 1.8);

  return String(temp);
}
String LedStatus() {
  return ( digitalRead(LED_BUILTIN) == LOW) ? "true" : "false";
}
void StartDNS() {
  if (!MDNS.begin(ssid)) {
    Serial.println("Error setting up MDNS responder!");
    while (1) {
      delay(1000);
    }
  }
  Serial.println("mDNS responder started");
  MDNS.addService("http", "tcp", 80);
}

void StartWeb() {
  server.on("/", HandleRoot);
  server.on("/style.css", HandleCss);
  server.on("/index.js", HandleJs);
  server.on("/onoff", HandleOnOff);
  server.on("/info", HandleInfo);
  server.begin();
  Serial.printf("HTTP server started at: \n\t - http://%s\n\t - http://%s.local\n", WiFi.softAPIP().toString().c_str(), WiFi.softAPgetHostname());
}

void StartAP() {

  Serial.printf("\nConfiguring access point...\n");
  WiFi.softAP(ssid, password);
  WiFi.softAPsetHostname(ssid);
  Serial.printf("AP IP address: %s\n", WiFi.softAPIP().toString().c_str());

}


void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  StartAP();
  StartWeb();
  StartDNS();


}

void loop() {

  server.handleClient();


}
