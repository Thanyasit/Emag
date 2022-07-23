#include "D:\Work T.Pongsak\Microcontroller\Work\LAB-Test\LAB-Test.h"
#use delay (clock=20M)

void main()
{
   int time,time10,sec=0,s5,s10,s;
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
   setup_timer_0(RTCC_DIV_256);
   set_timer0(61);
   set_tris_d(0xf0);
   output_d(0x00);
   while(1){
      time = get_timer0();
      if(time==0){
         time10++;
         if(time10==100){
            time10 = 0;
            sec++;
            s = sec%2;
            s5 = sec%5;
            s10 = sec%10;
            if(s==0){
            output_toggle(PIN_D1);
            } 
            if(s5==0){
            output_toggle(PIN_D2);
            }
            if(s10==0){
            output_toggle(PIN_D3);
            } 
            output_toggle(PIN_D0); //toggle change present 
         }
         set_timer0(61);
     }
   }
}
