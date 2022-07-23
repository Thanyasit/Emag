#include "D:\Work T.Pongsak\Microcontroller\Work\Lab Assignment\Lab Assignment 03\Lab Assignment 03.h"
#use delay (clock=20M)
#include <lcd.c>
int matsw,x;
int matrixSw(void);
int matrixSwStop(void);
#define COL1 PIN_C2
#define COL2 PIN_C1
#define COL3 PIN_C0
#define ROW1 PIN_C4
#define ROW2 PIN_C5
#define ROW3 PIN_C6
#define ROW4 PIN_C7
void main()
{
   int i=6,s=0,A=0,b=0,h=12,l,c=6,d,e=6,f=0;
   char set[16]={1,2,3,4,5,6};
   char save[16];
   char sw[]={'0','1','2','3','4','5','6','7','8','9','*','#','-'};
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
   set_tris_c(0b00000111);
   lcd_init();
   lcd_gotoxy(3,1);
   printf(lcd_putc,"ENTERYOUR-PW");
   lcd_gotoxy(6,2);
   printf(lcd_putc,"------");
   while(1){
      matrixSw();
      if(b==1){
         if(matsw==10){
            lcd_putc('\f');
            lcd_gotoxy(1,1);
            printf(lcd_putc,"CHANGE THE CODE ");
            do{
               matrixSw();
            }while(matsw>9);
            c=matsw;
            lcd_gotoxy(8,2);
            lcd_putc(sw[c]);
            delay_ms(20);
            matrixSwStop();
            if(c==9){
               i=4;
               e=4;
            }if(c==8){
               i=5;
               e=5;
            }if(c==7){
               i=5;
               e=5;
            }if(c==6){
               i=6;
               e=6;
            }if(c==5){
               i=6;
               e=6;
            }if(c==4){
               i=7;
               e=7;
            }if(c==3){
               i=7;
               e=7;
            }if(c==2){
               i=8;
               e=8;
            }if(c==1){
               i=8;
               e=8;
            }
            matsw=11;
            delay_ms(300);
         }
         if(matsw==11){
            lcd_putc('\f');
            lcd_gotoxy(3,1);
            printf(lcd_putc,"NEW PASSWORD");
            h=e;
            for(d=0;d<c;d++){
               lcd_gotoxy(h,2);
               lcd_putc(sw[12]);
               h++;
            }
            h=e;
            for(s=0;s<c;s++){
               do{
                  matrixSw();
               }while(matsw>9);
               set[s]=matsw;
               lcd_gotoxy(h,2);
               lcd_putc(sw[matsw]);
               delay_ms(20);
               matrixSwStop();
               h++;
            }
            s=0;
            b=0;
            A=0;
            matsw=12;
            f=!f;
            delay_ms(300);
         }
      }
      if(matsw<10){
         save[s] = matsw;
         lcd_gotoxy(i,2);
         lcd_putc(sw[10]);
         i++;
         s++;
         delay_ms(20);
         matrixSwStop();
      }
      if(s==c){
         for(s=0;s<c;s++){
            if(save[s]==set[s]){
               l++;
            }
         }
         if(l==c){
            A=1;
            b=1;
         }
         l=0;
         if(A==1){
            lcd_putc('\f');
            lcd_gotoxy(7,1);
            printf(lcd_putc,"PASS");
            delay_ms(3000);
            A=0;
            f=1;
         }else{
            lcd_putc('\f');
            lcd_gotoxy(6,1);
            printf(lcd_putc,"NOPASS");
            delay_ms(3000);
            b=0;
            f=1;
         }
      }
      if(f==1){
         lcd_putc('\f');
         lcd_gotoxy(3,1);
         printf(lcd_putc,"ENTERYOUR-PW");
         h=e;
         for(d=0;d<c;d++){
         lcd_gotoxy(h,2);
         lcd_putc(sw[12]);
         h++;
         }
         i=e;
         s=0;
         f=!f;
      }
   }
}
int matrixSw(){
   matsw = 12;
   output_low(ROW1);
   output_high(ROW2);
   output_high(ROW3);
   output_high(ROW4);
   if(!input(COL1)){
      matsw = 1;
   }else if(!input(COL2)){
      matsw = 2;
   }else if(!input(COL3)){
      matsw = 3;
   }
   delay_ms(20);
   output_high(ROW1);
   output_low(ROW2);
   output_high(ROW3);
   output_high(ROW4);
   if(!input(COL1)){
      matsw = 4;
   }else if(!input(COL2)){
      matsw = 5;
   }else if(!input(COL3)){
      matsw = 6;
   }
   delay_ms(20);
   output_high(ROW1);
   output_high(ROW2);
   output_low(ROW3);
   output_high(ROW4);
   if(!input(COL1)){
      matsw = 7;
   }else if(!input(COL2)){
      matsw = 8;
   }else if(!input(COL3)){
      matsw = 9;
   }
   delay_ms(20);
   output_high(ROW1);
   output_high(ROW2);
   output_high(ROW3);
   output_low(ROW4);
   if(!input(COL1)){
      matsw = 10;
   }else if(!input(COL2)){
      matsw = 0;
   }else if(!input(COL3)){
      matsw = 11;
   }
   delay_ms(20);
   return matsw;
}
int matrixSwStop(){
   output_low(ROW1);
   output_high(ROW2);
   output_high(ROW3);
   output_high(ROW4);
   delay_ms(20);
   while(!input(COL1));
   while(!input(COL2));
   while(!input(COL3));
   output_high(ROW1);
   output_low(ROW2);
   output_high(ROW3);
   output_high(ROW4);
   delay_ms(20);
   while(!input(COL1));
   while(!input(COL2));
   while(!input(COL3));
   output_high(ROW1);
   output_high(ROW2);
   output_low(ROW3);
   output_high(ROW4);
   delay_ms(20);
   while(!input(COL1));
   while(!input(COL2));
   while(!input(COL3));
   output_high(ROW1);
   output_high(ROW2);
   output_high(ROW3);
   output_low(ROW4);
   delay_ms(20);
   while(!input(COL1));
   while(!input(COL2));
   while(!input(COL3));
}
