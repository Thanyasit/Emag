#include "D:\Work T.Pongsak\Microcontroller\Work\LAB061-interrupt\LAB061-interrupt.h"
int time10=0;
#int_timer0
void time0_isr(){
   time10++;
   set_timer0(61);
}
void main()
{

   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_DIV_256);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

   // TODO: USER CODE!!
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_TIMER0);
   set_timer0(61);
   set_tris_d(0x00);
   output_d(0x00);
   while(1){
      if(time10==100){
         output_toggle(PIN_D0);
         time10=0;
      }
   }
   
}

