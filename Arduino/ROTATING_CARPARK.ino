//Adjust By Emag
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_PCF8574.h>
LiquidCrystal_PCF8574 lcd(0x3F);
#define buzPin          8
#define motorPin        5
#define motorPin2        4
#define homeSensorPin   6
#define countSensorPin  7
int sensorCounter = 0;
int Positionold = 0;
int Num = 0;
byte parkingAvailable = 10;
#define motorOnF()       digitalWrite(motorPin, HIGH),digitalWrite(motorPin2, LOW);
#define motorOnR()       digitalWrite(motorPin, LOW),digitalWrite(motorPin2, HIGH);
#define motorOff()      digitalWrite(motorPin, LOW),digitalWrite(motorPin2, LOW);
// Create instances
#define RST_PIN         9
#define SS_PIN          10
MFRC522 mfrc522(SS_PIN, RST_PIN);
struct {
  bool PARKING_SPACE;
  byte CARD_UID[4];
} DataParking[10];
byte readCard[4];
#define senser_counter_normal   false
#define senser_counter_active   true
#define senser_home_normal      LOW
#define senser_home_active      HIGH
void readCntSensor(void) {
  static enum {SensorNoneAct, SensorAct , SensorHold} SensorState;
  bool SensorRead = digitalRead(countSensorPin);
  bool a = digitalRead(homeSensorPin);
  if ((a || SensorRead) == senser_counter_normal) {
    SensorState = SensorNoneAct;
    return;
  }
  if ((a || SensorRead) == senser_counter_active && SensorState == SensorNoneAct) {
    SensorState = SensorAct;
    Serial.println("2");
    return;
  }
  if (SensorState == SensorAct) {
    sensorCounter++;
    Serial.println("3");
    SensorState = SensorHold;
  }
}
void motorControl(uint8_t parking_num) {
  if (parking_num == 0) {
    Serial.println("Goto Home Position");
    if (digitalRead(homeSensorPin) == senser_home_normal) {
      if (Positionold > 5) {
        motorOnR();
      } else {
        motorOnF();
      }
    } else {
      motorOff();
    }
    while (digitalRead(homeSensorPin) == senser_home_normal);
    motorOff();
  }
  beep();
  Serial.println("Goto Parking Position");
  delay(2000);
  if (parking_num != Positionold) {
    Num = parking_num - Positionold;
    if (abs(Num) > 6) {
      if (Num < 0) {
        Num = 10 + Num;
      } else if (Num > 0) {
        Num = -10 + Num;
      }
    }
    Positionold = parking_num;
    sensorCounter = 0;
    if (parking_num != 0) {
      if (Num < 0) {
        motorOnR();
      } else if (Num > 0) {
        motorOnF();
      }
      delay(500);
      while (sensorCounter != abs(Num)){
        readCntSensor();
      }
      motorOff();
      beep();
    }
    Serial.println("Parking Position Success");
    delay(2000);
  }
}
void beep() {
  for (int i = 0; i < 500; i++) {
    digitalWrite(buzPin, HIGH);
    delayMicroseconds(250);
    digitalWrite(buzPin, LOW);
    delayMicroseconds(250);
  }
  digitalWrite(buzPin, LOW);
}
uint8_t compare_uid(uint8_t uid) {
  uint8_t match_id = 0;
  for (uint8_t i = 0; i < 4; i++) {
    if (readCard[i] == DataParking[uid].CARD_UID[i]) {
      match_id++;
    }
  }
  if (match_id == 4) {
    return 1;
  }
  return 0;
}
void clear_uid (uint8_t uid) {
  for (uint8_t i = 0; i < 4; i++) {
    DataParking[uid].CARD_UID[i] = 0;
  }
}
void parking_print_match_num(uint8_t num) {
  parkingAvailable++;
  Serial.print("Found card match parking ");
  Serial.println(num);
  lcd.setCursor(0, 0);
  lcd.print("Park free :");
  lcd.write(parkingAvailable / 10 % 10 + '0');
  lcd.write(parkingAvailable % 10 + '0');
  lcd.setCursor(0, 1);
  lcd.print("Match UID :");
  lcd.write(num / 10 % 10 + '0');
  lcd.write(num % 10 + '0');
}
void parking_print_save_num(uint8_t num) {
  parkingAvailable--;
  Serial.print("Save card parking ");
  Serial.println(num);
  lcd.setCursor(0, 0);
  lcd.print("Park free :");
  lcd.write(parkingAvailable / 10 % 10 + '0');
  lcd.write(parkingAvailable % 10 + '0');
  lcd.setCursor(0, 1);
  lcd.print("Save  UID :");
  lcd.write(num / 10 % 10 + '0');
  lcd.write(num % 10 + '0');
}
///////////////////////////////////////////////////////////////////////////////////
void setup() {
  pinMode(buzPin, OUTPUT);
  pinMode(homeSensorPin, INPUT_PULLUP);
  pinMode(countSensorPin, INPUT_PULLUP);
  pinMode(motorPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.setBacklight(255);
  Serial.begin(115200);
  SPI.begin();        // SPI bus
  mfrc522.PCD_Init(); //  MFRC522
  DataParking[0].PARKING_SPACE  = false;
  DataParking[1].PARKING_SPACE  = false;
  DataParking[2].PARKING_SPACE  = false;
  DataParking[3].PARKING_SPACE  = false;
  DataParking[4].PARKING_SPACE  = false;
  DataParking[5].PARKING_SPACE  = false;
  DataParking[6].PARKING_SPACE  = false;
  DataParking[7].PARKING_SPACE  = false;
  DataParking[8].PARKING_SPACE  = false;
  DataParking[9].PARKING_SPACE  = false;
  DataParking[10].PARKING_SPACE = false;
  Serial.println("Ready!!!");
  lcd.setCursor(0, 0);
  lcd.print("Ready!!!        ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  beep();
}
void loop() {
  if ( ! mfrc522.PICC_IsNewCardPresent()) { //If a new PICC placed to RFID reader continue
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {   //Since a PICC placed get Serial and continue
    return;
  }
  for ( uint8_t i = 0; i < 4; i++) {  //
    readCard[i] = mfrc522.uid.uidByte[i];
    mfrc522.PICC_HaltA(); // Stop reading
    beep();
    if (compare_uid(0) == true) {
      clear_uid(0);
      DataParking[0].PARKING_SPACE = false;
      parking_print_match_num(0);
      motorControl(0);
      return;
    }
    if (compare_uid(1) == true) {
      clear_uid(1);
      DataParking[1].PARKING_SPACE = false;
      parking_print_match_num(1);
      motorControl(1);
      return;
    }
    if (compare_uid(2) == true) {
      clear_uid(2);
      DataParking[2].PARKING_SPACE = false;
      parking_print_match_num(2);
      motorControl(2);
      return;
    }
    if (compare_uid(3) == true) {
      clear_uid(3);
      DataParking[3].PARKING_SPACE = false;
      parking_print_match_num(3);
      motorControl(3);
      return;
    }
    if (compare_uid(4) == true) {
      clear_uid(4);
      DataParking[4].PARKING_SPACE = false;
      parking_print_match_num(4);
      motorControl(4);
      return;
    }
    if (compare_uid(5) == true) {
      clear_uid(5);
      DataParking[5].PARKING_SPACE = false;
      parking_print_match_num(5);
      motorControl(5);
      return;
    }
    if (compare_uid(6) == true) {
      clear_uid(6);
      DataParking[6].PARKING_SPACE = false;
      parking_print_match_num(6);
      motorControl(6);
      return;
    }
    if (compare_uid(7) == true) {
      clear_uid(7);
      DataParking[7].PARKING_SPACE = false;
      parking_print_match_num(7);
      motorControl(7);
      return;
    }
    if (compare_uid(8) == true) {
      clear_uid(8);
      DataParking[8].PARKING_SPACE = false;
      parking_print_match_num(8);
      motorControl(8);
      return;
    }
    if (compare_uid(9) == true) {
      clear_uid(9);
      DataParking[9].PARKING_SPACE = false;
      parking_print_match_num(9);
      motorControl(9);
      return;
    }
    if (DataParking[0].PARKING_SPACE == false) {
      for ( uint8_t i = 0; i < 4; i++) {
        DataParking[0].CARD_UID[i] = readCard[i];
      }
      parking_print_save_num(0);
      DataParking[0].PARKING_SPACE = true;//Have
      motorControl(0);
      return;
    }
    if (DataParking[1].PARKING_SPACE == false) {
      for ( uint8_t i = 0; i < 4; i++) {
        DataParking[1].CARD_UID[i] = readCard[i];
      }
      parking_print_save_num(1);
      DataParking[1].PARKING_SPACE = true;
      motorControl(1);
      return;
    }
    if (DataParking[2].PARKING_SPACE == false) {
      for ( uint8_t i = 0; i < 4; i++) {
        DataParking[2].CARD_UID[i] = readCard[i];
      }
      parking_print_save_num(2);
      DataParking[2].PARKING_SPACE = true;
      motorControl(2);
      return;
    }
    if (DataParking[3].PARKING_SPACE == false) {
      for ( uint8_t i = 0; i < 4; i++) {
        DataParking[3].CARD_UID[i] = readCard[i];
      }
      parking_print_save_num(3);
      DataParking[3].PARKING_SPACE = true;
      motorControl(3);
      return;
    }
    if (DataParking[4].PARKING_SPACE == false) {
      for ( uint8_t i = 0; i < 4; i++) {
        DataParking[4].CARD_UID[i] = readCard[i];
      }
      parking_print_save_num(4);
      DataParking[4].PARKING_SPACE = true;
      motorControl(4);
      return;
    }
    if (DataParking[5].PARKING_SPACE == false) {
      for ( uint8_t i = 0; i < 4; i++) {
        DataParking[5].CARD_UID[i] = readCard[i];
      }
      parking_print_save_num(5);
      DataParking[5].PARKING_SPACE = true;
      motorControl(5);
      return;
    }
    if (DataParking[6].PARKING_SPACE == false) {
      for ( uint8_t i = 0; i < 4; i++) {
        DataParking[6].CARD_UID[i] = readCard[i];
      }
      parking_print_save_num(6);
      DataParking[6].PARKING_SPACE = true;
      motorControl(6);
      return;
    }
    if (DataParking[7].PARKING_SPACE == false) {
      for ( uint8_t i = 0; i < 4; i++) {
        DataParking[7].CARD_UID[i] = readCard[i];
      }
      parking_print_save_num(7);
      DataParking[7].PARKING_SPACE = true;
      motorControl(7);
      return;
    }
    if (DataParking[8].PARKING_SPACE == false) {
      for ( uint8_t i = 0; i < 4; i++) {
        DataParking[8].CARD_UID[i] = readCard[i];
      }
      parking_print_save_num(8);
      DataParking[8].PARKING_SPACE = true;
      motorControl(8);
      return;
    }
    if (DataParking[9].PARKING_SPACE == false) {
      for ( uint8_t i = 0; i < 4; i++) {
        DataParking[9].CARD_UID[i] = readCard[i];
      }
      parking_print_save_num(9);
      DataParking[9].PARKING_SPACE = true;
      motorControl(9);
      return;
    }
  }
}
