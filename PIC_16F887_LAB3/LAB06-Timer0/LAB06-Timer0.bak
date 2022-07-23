#include "D:\Work T.Pongsak\Microcontroller\Work\LAB06-Timer0\LAB06-Timer0.h"
#use delay (clock=20M)

void main()
{
   int time,time10,sec;
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
  // setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

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
            if(sec==60){
               sec = 0;
            }
            output_toggle(PIN_D0); //toggle change present 
         }
         set_timer0(61);
      }
   }
}

