#include "D:\Work T.Pongsak\Microcontroller\Work\LAB01 flowCon1\LAB01-FlowCon1.h"


void main()
{
   int a;
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

   // TODO: USER CODE!!
   set_tris_b(0b11111100); //0xFc 
   OUTPUT_LOW(PIN_B0);
   OUTPUT_LOW(PIN_B1);
   a = 4;
/*
   if(a<10){
      OUTPUT_HIGH(PIN_B0);
      OUTPUT_HIGH(PIN_B1);
   }

   if(a<10){
      OUTPUT_HIGH(PIN_B0);
   }else{
      OUTPUT_HIGH(PIN_B1);
   }
*/
   if(a>5){
      output_high(PIN_B0);
   }else if(a<4){
      output_high(PIN_B1);
   }else{
      output_high(PIN_B0);
      output_high(PIN_B1);
   }
   while(TRUE){  // TRUE : 1, FALSE : 0
   }
}
