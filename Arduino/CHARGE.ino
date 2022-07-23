//By Emag
#include <Adafruit_NeoPixel.h>
#include <Bounce2.h>
#define PIN 8
#define Relay 6
#define NUMPIXELS 4
#define sw 2
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Bounce debouncer = Bounce();
int c1 = 0 , c2 = 0; //color
boolean on = false;
int delayval = 50;
int low = 505;//2.4v
int high = 680;//3.2v
void setup() {
  Serial.begin(115200);
  pixels.begin();
  pinMode(Relay, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  debouncer.attach(sw, INPUT_PULLUP);
  debouncer.interval(25); // กำหนดเวลาการเปลี่ยนสถานะให้กับ debouncer object ที่ 25 มิลลิวินาที
}
void loop() {
  debouncer.update();
  if ( debouncer.fell() ) {
    on = !on;
  }
  digitalWrite(LED_BUILTIN, on);
  int val = analogRead(A0);
  Serial.println(on);
  Serial.println(val);
  if (val > high) {
    if (on == 1) {
      digitalWrite(Relay, HIGH);
    }
  } else if (val < low) {
    digitalWrite(Relay, LOW);
  }
  if (val < 530) {
    c1 = 255;
    c2 = 255;
  } else if (val < 640) {
    c1 = 255;
    c2 = 0;
  } else {
    c1 = 0;
    c2 = 255;
  }
  Serial.print("c1 = ");
  Serial.print(c1);
  Serial.print("c2 = ");
  Serial.println(c2);
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(c1, c2, 0));
    pixels.show();
    delay(delayval);
  }
}
