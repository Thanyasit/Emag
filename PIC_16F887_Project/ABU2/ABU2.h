#include <16F877.h>
#device adc=8

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES HS                       //High speed Osc (> 4mhz)
#FUSES NOPUT                    //No Power Up Timer
#FUSES PROTECT                  //Code protected from reads
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOCPD                    //No EE protection
#FUSES NOWRT                    //Program memory not write protected
#FUSES NODEBUG                  //No Debug mode for ICD

#use delay(clock=20000000)
#use rs232(baud=115200,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)

#define M1  PIN_D0  // PWN Moter1
#define M1R PIN_D1  // Moter1 Reves
#define M2  PIN_D2  // PWN Moter2
#define M2R PIN_D3  // Moter2 Reves
#define M3  PIN_D4  // PWN Moter3
#define M3R PIN_D5  // Moter3 Reves
#define M4  PIN_D6  // PWN Moter4
#define M4R PIN_D7  // Moter4 Reves
#define ENA PIN_B0  // Enable
#define LMM PIN_B1  // Limit Mag
#define LMS PIN_B2  // Limit Shoot
#define LLU PIN_B3  // Limit liftUp
#define LLD PIN_B4  // Limit liftDown
#define LAU PIN_B5  // Limit AngleUp
#define LAD PIN_B6  // Limit AngleDown
//#define Lm7 PIN_B7  // Limit Shoot 
#define Mag PIN_C0  // Moter Mag
#define SOT PIN_C3  // Moter Shoot
#define MA  PIN_C4  // Moter Angle
#define MAR PIN_C5  // Moter Angle Reves
#define ML  PIN_A2  // Moter Lift 
#define MLR PIN_A5  // Moter Lift Reves
#define COT PIN_A3  // Moter Couter
//#define M4R PIN_A3  // Moter4 Reves
//#define M4R PIN_A4  // Moter4 Reves
//#define M4R PIN_A5  // Moter4 Reves
//#define M4R PIN_E0  // Moter4 Reves
//#define M4R PIN_E1  // Moter4 Reves
//#define M4R PIN_E2  // Moter4 Reves
#define ph1 2000    // 0.4 sec. step count
#define ph2 4000
#define ph3 6000
#define ph4 8000
#define ph5 1000
void delay(void);//delay
void Up(void);
void Left(void);
void Right(void);
void Down(void);
void RollRight(void);
void RollLeft(void);
void Shoot(void);
void RollMag(void);
void LiftUp(void);
void LiftDown(void);
void AngleUp(void);
void AngleDown(void);
void Upspeed(void);
void Downspped(void);
void Stop(void);
void Dutycycle(void);
void goAhead1(void);
