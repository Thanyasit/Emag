#include "D:\Work T.Pongsak\Microcontroller\Work\LAB07-incDec\LAB07-incDec.h"
#use delay (clock=20M)
#define ISw PIN_B0
#define DSw PIN_B1
void main()
{
   char segment[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   int count=0;
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
   set_tris_b(0xff);
   set_tris_d(0x00);
   output_d(segment[0]);
   while(1){
      if(!input(ISw)){
        delay_ms(50);
        count++;
        if(count==10){
            count=0;
        }
      }
      if(!input(DSw)){
        delay_ms(50);
        count--;
        if(count==-1){
            count=9;
        }
      }
      output_d(segment[count]);
      while(!input(Isw));
      while(!input(Dsw));
      delay_ms(50);
   }
}
