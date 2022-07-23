#include "E:\class-59\uC-DVT\Project\Project.h"
#use delay(clock=8M)
//#use delay(clock=20M)
#include <lcd.c>
#define InCoins1  PIN_E0
#define InCoins5  PIN_E1
#define InCoins10 PIN_E2
#include <stdlib.h>
//char number[]={'0','1','2','3','4','5','6','7','8','9'};
char c5[5]={0x20,0x20,0x20,0x20,0x20};
char m[5]={0x20,0x20,0x20,0x20,0x20};
char c1[5]={0x20,0x20,0x20,0x20,0x20};
char c10[5]={0x20,0x20,0x20,0x20,0x20};
int f1=0,f2=0,f3=0,CO1=0,CO2=0,CO3=0;
int32 Coins1=0,Coins5=0,Coins10=0,Money,l,Test;
int i,t=0,d;
int LCD();
int ClearLCD();
void main()
{
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab
   setup_oscillator(OSC_8MHZ);
   // TODO: USER CODE!!
   set_tris_e(0xff);
   output_e(0xff);
   set_tris_c(0xff);
   output_c(0xff);
   lcd_init();
   lcd_gotoxy(0,0);//0=1 3=4 19=20
   printf(lcd_putc,"Money   =       Bath");
   lcd_gotoxy(0,1);
   printf(lcd_putc,"Coins1  =       C");
   lcd_gotoxy(0,2);
   printf(lcd_putc,"Coins5  =       C");
   lcd_gotoxy(0,3);
   printf(lcd_putc,"Coins10 =       C");
   while(1){
      for(l=0;l<=50000;l++){
         if(input(PIN_C4)){
            Coins1=0;
            Coins5=0;
            Coins10=0;
         }
            CO1 = input(InCoins1);
            CO2 = input(InCoins5);
            CO3 = input(InCoins10);
         if(CO1==0&&f1==0){
            t=1;
            f1=1;
         }else if(CO1==1&&CO2==1&&CO3==1){
            f1=0;
         }
         if(CO2==0&&f2==0){
            t=5;
            f2=1;
         }else if(CO1==1&&CO2==1&&CO3==1){
            f2=0;
         }
         if(CO3==0&&f3==0){
            t=10;
            f3=1;
         }else if(CO1==1&&CO2==1&&CO3==1){
            f3=0;
         }
      }
      if(t==1){
         Coins1++;
      }else if(t==5){
         Coins5++;
      }else if(t==10){
         Coins10++;
      }
      
      t=0;
      Money=Coins1+(Coins5*5)+(Coins10*10);
      LCD();
   }
}
int LCD(){
   lcd_gotoxy(10,0);
   Test = Money;
   d=4;
   itoa(Money,10,m);
   ClearLCD();
   for (i=0;i<5;i++){
         lcd_putc(m[i]);
   }
   lcd_gotoxy(10,1);
   Test = Coins1;
   d=3;
   itoa(Coins1,10,c1);
   ClearLCD();
   for (i=0;i<5;i++){
         lcd_putc(c1[i]);
   }
   lcd_gotoxy(10,2);
   Test = Coins5;
   d=2;
   itoa(Coins5,10,c5);
   ClearLCD();
   for (i=0;i<5;i++){
         lcd_putc(c5[i]);
   }
   lcd_gotoxy(10,3);
   Test = Coins10;
   d=1;
   itoa(Coins10,10,c10);
   ClearLCD();
   for (i=0;i<5;i++){
         lcd_putc(c10[i]);
   }
   return 0;
}
int ClearLCD(){
   int a;
   int c;
   if(Test>=1000){
      c=4;
   }else if(Test>=100){
      c=3;
   }else if(Test>=10){
      c=2;
   }else{
      c=1;
   }
   for(a=c;a<5;a++){
      if(d==4){
         m[a]=0x20;
      }else if(d==3){
         c1[a]=0x20;
      }else if(d==2){
         c5[a]=0x20;
      }else if(d==1){
         c10[a]=0x20;
      }
   }
   return 0;
}
