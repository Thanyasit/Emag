#include "D:\Work T.Pongsak\Microcontroller\Work\LAB10-Stepping\LAB10-Stepping.h"


void main()
{
   int full1ph[]={0x01,0x02,0x04,0x08};
   int i;
   int full2ph[]={0x03,0x06,0x0c,0x09};
   int halfstep[]={0x01,0x03,0x02,0x06,0x04,0x0c,0x08,0x09};
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
   set_tris_c(0x00);
   while(1){
      for(i=8;i>0;i--){
         output_c(halfstep[i]);
         delay_ms(300);
      }
   }

}
