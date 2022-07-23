#define echoPin 5
#define trigPin 4

long duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  //Serial.println(duration);
  distance = duration / 58.2;
  if (distance != 0) {
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
}
