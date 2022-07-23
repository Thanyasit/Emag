//#include <ESP8266WiFi.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme; // กำหนดค่า address I2C กรณีเป็นตำแหน่งอื่น แก้เป็น Adafruit_BME280 bme(ตำแหน่ง address i2c)

unsigned long delayTime;

void setup() {
    Serial.begin(9600);

    bool status;
    status = bme.begin();  
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }
    
    Serial.println("-- ArduinoAll BME280 Test --");
    delayTime = 1000;
    Serial.println();
    Serial.println("TEMP      Humidity    Pressure     Approx. Altitude");
}


void loop() { 
    printValues();
    delay(delayTime);
}


void printValues() {
    
    Serial.print(bme.readTemperature());
    Serial.print(" C    ");
    Serial.print(bme.readHumidity());
    Serial.print(" %    ");
    Serial.print(bme.readPressure() / 100.0F);
    Serial.print(" hPa     ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");
    

}
