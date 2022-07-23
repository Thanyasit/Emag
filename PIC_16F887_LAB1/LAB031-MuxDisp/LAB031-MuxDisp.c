#include "D:\Work T.Pongsak\Microcontroller\Work\LAB031-MuxDisp\LAB031-MuxDisp.h"
#use delay (clock=20M)

void main()
{
   char segment[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   int i,com1,com2;
   int data[]={1,0,0,6,4,0};
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
   set_tris_d(0x80);
   set_tris_c(0xc0);
   while(1){
      com1 = 0b00000001;
      for(i=0;i<6;i++){
         com2 = ~com1;
         output_c(com2);
         output_d(segment[data[i]]);
         delay_ms(150);
         com1 = com1<<1;
      }
   }
}
