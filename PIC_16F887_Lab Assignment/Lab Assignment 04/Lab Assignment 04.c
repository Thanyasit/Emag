#include "D:\Work T.Pongsak\Microcontroller\Work\Lab Assignment\Lab Assignment 04\Lab Assignment 04.h"


void main()
{
   int i;
   char code[]={0x01,0x02,'A','-','C','-','1','2',0x03,0x04};
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
      delay_ms(500);
      for(i=0;i<10;i++){
                  putc(code[i]);
                  delay_ms(10);
      }
      while(1);
}
