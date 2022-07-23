//By Emag
#include "sensirion_uart.h"
#include "sps30.h"
//#include <FastLED.h>
#include "BluetoothSerial.h"
#ifdef __AVR__
#include <avr/power.h>
#endif
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
#define NUM_LEDS 1
#define DATA_PIN 18
CRGB leds[NUM_LEDS];
BluetoothSerial SerialBT;
float aqi_us = 0;
int pm_min = 0;
int aqi_max = 0;
int pmdiff = 0;
int aqi_min = 0;
int aqi_level = 0;
int delayval = 500; // delay for half a second
void setup() {
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(20);
  leds[0] = CRGB(255, 255, 255);
  FastLED.show();
  delay(500);
  // Now turn the LED off, then pause
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
  Serial.begin(115200);
  SerialBT.begin("MyAir_Case"); //Bluetooth device name
  delay(2000);
  sensirion_uart_open();
  while (sps30_probe() != 0) {
    Serial.println("probe failed");
    delay(1000);
  }
  // sps30_set_fan_auto_cleaning_interval(60*60);
  /* start measurement and wait for 10s to ensure the sensor has a
     stable flow and possible remaining particles are cleaned out */
  if (sps30_start_measurement() != 0) {
    Serial.println("error starting measurement");
  }
}
int counter_led = 0;
float pm25_real = 0;
void loop()
{
  struct sps30_measurement measurement;
  s16 ret;
  while (true) {
    delay(5000);
    //counter_led++;
    ret = sps30_read_measurement(&measurement);
    if (ret < 0) {
      Serial.println("read measurement failed");
    } else {
      if (SPS_IS_ERR_STATE(ret)) {
        Serial.println("Measurements may not be accurate");
      } else {
        measurement.mc_2p5 = ((5.18 * measurement.mc_2p5) / 10000) * 0.8;
        //measurement.mc_2p5 = (0.02195*measurement.mc_2p5) - 1682;
        //Serial.print("pm1.0 :");Serial.println(measurement.mc_1p0);
        Serial.print("pm2.5 :"); Serial.println(measurement.mc_2p5);
        //Serial.print("pm4.0 :");Serial.println(measurement.mc_4p0);
        ///Serial.print("pm10.0 :");Serial.println(measurement.mc_10p0);
        //Serial.print("nc0.5 :");Serial.println(measurement.nc_0p5);
        //Serial.print("nc1.0 :");Serial.println(measurement.nc_1p0);
        //Serial.print("nc2.5 :");Serial.println(measurement.nc_2p5);
        //Serial.print("nc4.0 :");Serial.println(measurement.nc_4p0);
        //Serial.print("nc10.0 :");Serial.println(measurement.nc_10p0);
        //Serial.print("typical particle size :");Serial.println(measurement.typical_particle_size);
        if (measurement.mc_2p5 >= 0 && measurement.mc_2p5 <= 12) {
          pm_min = 0;
          aqi_max = 50;
          pmdiff = 12;
          aqi_min = 0;
          aqi_level = 0;
        }
        else if (measurement.mc_2p5 > 12 && measurement.mc_2p5 <= 35.5) {
          pm_min = 12;
          aqi_max = 101;
          pmdiff = 23.5;
          aqi_min = 51;
          aqi_level = 1;
        }
        else if (measurement.mc_2p5 > 35.5 && measurement.mc_2p5 <= 55.5) {
          pm_min = 35.5;
          aqi_max = 151;
          pmdiff = 20;
          aqi_min = 101;
          aqi_level = 2;
        }
        else if (measurement.mc_2p5 > 55.5 && measurement.mc_2p5 <= 150.5) {
          pm_min = 55.5;
          aqi_max = 201;
          pmdiff = 95;
          aqi_min = 151;
          aqi_level = 3;
        }
        else if (measurement.mc_2p5 > 150.5 && measurement.mc_2p5 <= 250.5) {
          pm_min = 150.5;
          aqi_max = 301;
          pmdiff = 100;
          aqi_min = 201;
          aqi_level = 4;
        }
        else if (measurement.mc_2p5 > 250.5 && measurement.mc_2p5 <= 350.5) {
          pm_min = 250.5;
          aqi_max = 401;
          pmdiff = 100;
          aqi_min = 301;
          aqi_level = 5;
        }
        else if (measurement.mc_2p5 > 350.5 && measurement.mc_2p5 <= 500.5) {
          pm_min = 350.5;
          aqi_max = 501;
          pmdiff = 150;
          aqi_min = 401;
          aqi_level = 6;
        }
        aqi_us = (((measurement.mc_2p5 - pm_min) * (aqi_max - aqi_min)) / pmdiff) + aqi_min;
        SerialBT.print(measurement.mc_2p5);
        SerialBT.print(",");
        SerialBT.print(aqi_us);
        SerialBT.print(",");
        if (measurement.mc_2p5 > 50) {
          SerialBT.println("0");
        }
        else if (measurement.mc_2p5 <= 50) {
          SerialBT.println("1");
        }
        if (measurement.mc_2p5 <= 50)
        {
          leds[0] = CRGB(255, 0, 0);
          FastLED.show();
          delay(500);
          leds[0] = CRGB::Black;
          FastLED.show();
          delay(500);
        }
        else if (measurement.mc_2p5 > 50 )
        {
          leds[0] = CRGB(0, 255, 0);
          FastLED.show();
          delay(500);
          leds[0] = CRGB::Black;
          FastLED.show();
          delay(500);
        }
        delay(5000);
      }
    }
  }
  sps30_stop_measurement();
  sensirion_uart_close();
  /////////////////////////////////////////////////////////////////////////////////////////
  /*else if(aqi_level > 100)
     {
       for (int i = 0; i < 20; i++)
       {
       ring[i] = CRGB::Black;
       }
       FastLED.show();
       delay(10000);
     }*/
}
