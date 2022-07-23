#include "D:\Work T.Pongsak\Microcontroller\Work\ABU2\ABU2.h"
#use delay (clock=20m)
#use fast_io(A)
#use fast_io(B)
#use fast_io(C)
#use fast_io(D)
#use fast_io(E)
int x=0,duty=0,i=0,f=1,t=0;
int y=0,d=0;//0=0%,1=20%,2=40%,3=60%,4=80%,5=100%
int16 s=0;
#INT_RTCC
void timer0_isr(void){
   SET_TIMER0(254); //0.1ms
   s++;
   if(s>=10000){
      s=10000;
   }
   if(s>=0&&s<ph1){
      d = 1;
   }else if(s>=ph1&&s<ph2){
      d = 2;
   }else if(s>=ph2&&s<ph3){
      d = 3;
   }else if(s>=ph3&&s<ph4){
      d = 4;
   }else if(s>=ph4){
      d = 5;
   }
   if(y==5){
      output_high(M1);
      output_high(M2);
      output_high(M3);
      output_high(M4);
      y=0;
   }
   if(y>=d){
      output_low(M1);
      output_low(M2);
      output_low(M3);
      output_low(M4);
      y++;
   }else{
      output_high(M1);
      output_high(M2);
      output_high(M3);
      output_high(M4);
      y++;
   }
}
//*****************************************************************************
#INT_TIMER1
void timer1_isr(){
/*
   set_timer1(65474);//65536-62
   if(y==5){
      output_high(M1);
      y=0;
   }
   if(y>=d){
      output_low(M1);
      y++;
   }else{
      output_high(M1);
      y++;
   }
   */
}
//*****************************************************************************
#INT_RDA
void rs232_isr(){
   x=getc();
}
//*****************************************************************************
void main()
{
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
   setup_timer_2(T2_DIV_BY_16,156,1);
   setup_ccp1(CCP_PWM);
   setup_ccp2(CCP_PWM);
   set_pwm1_duty(duty);
   set_pwm2_duty(duty);
   // TODO: USER CODE!!
   set_tris_d(0x00);
   set_tris_c(0x00);
   set_tris_b(0xFE);//80
   set_tris_a(0x00);
   set_tris_e(0x00);
   output_a(0x00);
   output_low(ENA);
   output_c(0x00);
   output_d(0x00);
   output_e(0x00);
   enable_interrupts(GLOBAL);
   do{
      x = getc();
   }while(x!='1');
   x=0; 
   output_e(7);
   delay_ms(500);
   output_e(0);
   delay_ms(500);
   output_e(7);
   delay_ms(500);
   output_e(0);
   output_high(ENA); //Enable
   enable_interrupts(INT_RDA);
   while(1){
      if(x=='A'){//Up
         Up();
      }else if(x=='D'){//Right
         Right();
      }else if(x=='B'){//Down
         Down();
      }else if(x=='C'){//Left
         Left();
      }else if(x=='H'){//Roll Right
         RollRight();
      }else if(x=='G'){//Roll Left
         RollLeft();
      }else if(x=='K'){ //Shoot 
         Shoot();
      }else if(x=='I'){//Mag
         RollMag();
      }else if(x=='L'){//Up speed roll shoot
         Upspeed();
      }else if(x=='J'){//Down speed roll shoot
         Downspped();
      }else if(x=='E'){//Lift Up
         LiftUp();
      }else if(x=='F'){//Lift Down
         LiftDown();
      }else if(x=='M'){//Angle Up
         AngleUp();
      }else if(x=='N'){//Angle Down
         AngleDown();
      }else{
         Stop();
      }
      x=0;
      delay();      
   }
}
//*****************************************************************************
void delay(){//Sensor
   if(!input(LMM)){
      do{
         output_high(Mag);
      }while(!input(LMM));
      output_low(Mag);
   }
   for(t=0;t<40;t++){
      if(!input(LMS)){
         output_low(SOT);
         output_low(COT);
         f=1;
      }
    delay_ms(1);
   }
}
//*****************************************************************************
void Up(){
    enable_interrupts(INT_TIMER0);
//    enable_interrupts(INT_TIMER1);
//    output_high(M1); //FWD
    output_low(M1R);
//    output_high(M2); //REV
    output_high(M2R); 
//    output_high(M3); //REV
    output_high(M3R); 
//    output_high(M4); //FWD
    output_low(M4R);
}
//*****************************************************************************
void Left(){
   enable_interrupts(INT_TIMER0);
//   enable_interrupts(INT_TIMER1);
//   output_high(M1); //REV
   output_high(M1R);
//   output_high(M2); //REV
   output_high(M2R);
//   output_high(M3); //REV
   output_high(M3R); 
//   output_high(M4); //REV
   output_high(M4R);
}
//*****************************************************************************
void Right(){
   enable_interrupts(INT_TIMER0);
//   enable_interrupts(INT_TIMER1);
//   output_high(M1); //FWD
   output_low(M1R);
//   output_high(M2); //FWD
   output_low(M2R);
//   output_high(M3); //FWD
   output_low(M3R); 
//   output_high(M4); //FWD
   output_low(M4R); 
}
//*****************************************************************************
void Down(){
   enable_interrupts(INT_TIMER0);
//   enable_interrupts(INT_TIMER1);
//   output_high(M1); //REV
   output_high(M1R);
//   output_high(M2); //FWD
   output_low(M2R);
//   output_high(M3); //FWD
   output_low(M3R); 
//   output_high(M4); //REV
   output_high(M4R); 
}
//*****************************************************************************
void RollRight(){
//   enable_interrupts(INT_TIMER0);
//   enable_interrupts(INT_TIMER1);
   output_high(M1); //FWD//
   output_low(M1R);
   output_high(M2); //FWD//
   output_low(M2R);
   output_high(M3); //REV//
   output_high(M3R); 
   output_high(M4); //REV//
   output_high(M4R); 
}
//*****************************************************************************
void RollLeft(){
//   enable_interrupts(INT_TIMER0);
//   enable_interrupts(INT_TIMER1);
   output_high(M1); //REV
   output_high(M1R);
   output_high(M2); //REV
   output_high(M2R);
   output_high(M3); //FWD
   output_low(M3R); 
   output_high(M4); //FWD
   output_low(M4R); 
}
//*****************************************************************************
void Shoot(){
   if(f==1){
      output_high(SOT);
      output_high(COT);
      f=0;
   }
}
//*****************************************************************************
void RollMag(){
   output_high(Mag);
}
//*****************************************************************************
void LiftUp(){
   output_high(ML);
   output_low(MLR);
}
//*****************************************************************************
void LiftDown(){
   output_high(ML);
   output_high(MLR);
}
//*****************************************************************************
void AngleUp(){
   output_high(MA);
   output_low(MAR);
}
//*****************************************************************************
void AngleDown(){
   output_high(MA);
   output_high(MAR);
}
//*****************************************************************************
void Upspeed(){
   if(i<15){
      i++;
   }
   duty=(i*8)+37;
/*
   if(i<7){
      i++;
   }
   duty=i*23;
*/
   set_pwm1_duty(duty);
   set_pwm2_duty(duty);
   output_e(i);
   if(i>7){//
      output_high(PIN_A0);
   }else{
      output_low(PIN_A0);
   }
}
//*****************************************************************************
void Downspped(){
   if(i>0){
      i--;
   }
   if(i==0){
      duty=0;
   }else{
      duty=(i*8)+37;
   }
//   duty=i*23;
   set_pwm1_duty(duty);
   set_pwm2_duty(duty);
   output_e(i);
   if(i>7){//
      output_high(PIN_A0);
   }else{
      output_low(PIN_A0);
   }
}  
//*****************************************************************************
void Stop(){
   s=0;
   Disable_interrupts(INT_TIMER0);
//   Disable_interrupts(INT_TIMER1);
   output_d(0x00);
   output_low(MA);
   output_low(MAR);
   output_low(ML);
   output_low(MLR);
}
//*****************************************************************************

