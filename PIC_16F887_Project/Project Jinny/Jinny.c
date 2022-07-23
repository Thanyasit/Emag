#include "D:\Work T.Pongsak\Microcontroller\Work\Project Jinny\Jinny.h"
#use delay (clock=8M)
#include <stdlib.h>
int temp=50;
#INT_RDA
void rs232_isr(){
   temp=getc();
}
void main()
{
   int32 adcVal=0;
   setup_adc_ports(sAN2|VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
   set_tris_e(0x00);
   set_adc_channel(2);
   output_e(0x00);
   enable_interrupts(GLOBAL);
//   enable_interrupts(INT_RDA);
   while(1){
//      adcVal = read_adc(ADC_START_AND_READ); //get sensor
//      adcVal = (25*adcVal)/255;
//      adcVal = adcVal+25;
      putc(adcVal); // sent temp to computer
      if(adcVal>=temp){
         output_low(PIN_E2); //off Heater
      }else{
         output_high(PIN_E2); // on Heater
      }
   }
}
