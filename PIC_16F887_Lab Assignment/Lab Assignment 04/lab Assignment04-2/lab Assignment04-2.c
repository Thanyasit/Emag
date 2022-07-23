#include "D:\Work T.Pongsak\Microcontroller\Work\Lab Assignment\Lab Assignment 04\lab Assignment04-2\lab Assignment04-2.h"
#use delay (clock=20M)
int y,a=0,i=0,x=0,t10=0,b=0;
char save[];
#include <lcd.c>
#int_timer0
void time0_isr(){
   if(b==1){
      t10++;
         if(t10==100){
         t10=0;
         a=5;
      }
      set_timer0(61);
   }
}
#INT_RDA
void rs232_isr(){
   y = getc();
   output_b(y);
   b=1;
   if(a==0){
      if(y==0x01){
      output_high(PIN_C0);
      a=1;
      }
   }else if(a==1){
      if(y==0x02){
      output_high(PIN_C1);
      a=2;
      }
   }else if(a==2){
      if(y==0x03){
         output_high(PIN_C2);
         a=3;
      }else{
         save[x]=y;
         x++;
         a=2;
      }
   }else if(a==3){
      if(y==0x04){
         output_high(PIN_C3);
         a=4;
      }
   }
}
void main()
{
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_DIV_256);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_RDA);
   enable_interrupts(INT_TIMER0);
   set_timer0(61);
   set_tris_c(0xFF);
   set_tris_d(0x00);
   set_tris_b(0x00);
   output_b(0x00);
   lcd_init();
   lcd_gotoxy(7,1);
   printf(lcd_putc,"DATA");
   lcd_gotoxy(3,2);
   while(1){
      if(a==4){
         disable_interrupts(INT_RDA);
         for(i=0;i<x;i++){
            lcd_putc(save[i]);
         }
         while(1);
      }
      if(a==5){
         lcd_gotoxy(7,2);
         printf(lcd_putc,"ERROR");
         while(1);
      }
   }
}

