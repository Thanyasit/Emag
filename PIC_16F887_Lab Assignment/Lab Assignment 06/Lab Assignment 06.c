#include "D:\Work T.Pongsak\Microcontroller\Work\Lab Assignment\Lab Assignment 06\Lab Assignment 06.h"
#include <lcd.c>
#include <stdlib.h>

void main()
{
   int32 adcVal;
   int full1ph[]={0x01,0x02,0x04,0x08};
   int i,A,B=0;
   int full2ph[]={0x03,0x06,0x0c,0x09};
   int halfstep[]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};
   setup_adc_ports(sAN0|VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
   set_adc_channel(0);
   set_tris_c(0b11110000);
   set_tris_d(0x00);
   lcd_init();
   lcd_gotoxy(2,1);
   printf(lcd_putc,"STEPPING MOTOR");
   while(1){
      if(!input(PIN_C6)){
         A=1;
         delay_ms(50);
      }
      if(!input(PIN_C7)){
         A=0;
         delay_ms(50);
      }
      while(!input(PIN_C6));
      while(!input(PIN_C7));
      if(!input(PIN_C5)){
         B=1;
      }else{
         B=0; 
      }
      if(A==1){
         for(i=0;i<8;i++){
            if(B=1){
               output_c(full2ph[i]);
            }else if(B=0){
               output_c(halfstep[i]);
            }
            delay_ms(300);
         }
      }
   }
}
