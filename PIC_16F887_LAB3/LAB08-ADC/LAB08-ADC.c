#include "D:\Work T.Pongsak\Microcontroller\Work\LAB08-ADC\LAB08-ADC.h"
#include <lcd.c>
#include <stdlib.h>

void main()
{
   int32 adcVal;
   int i;
   char string[4];
   setup_adc_ports(sAN0|VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
// set_tris_d(0x00);
   set_adc_channel(0);
   lcd_init();
   lcd_gotoxy(4,1);
   printf(lcd_putc,"LAB08-ADC");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"TEMP VALUE:    C");

/*
   lcd_gotoxy(8,2);
   itoa(100,16,string);
   for (i=0;i<4;i++){
      lcd_putc(string[i]);
   }
*/
   
   while(1){
      adcVal = read_adc(ADC_START_AND_READ);
      adcVal = (100*adcVal)/255;
      itoa(adcVal,10,string);
      lcd_gotoxy(12,2);
      for (i=0;i<3;i++){
         lcd_putc(string[i]);
      }
   }
}

