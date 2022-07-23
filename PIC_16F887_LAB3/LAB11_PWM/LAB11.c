#include "D:\Work T.Pongsak\Microcontroller\Work\LAB11\LAB11.h"


void main()
{
   int duty;
   setup_adc_ports(sAN0|VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DIV_BY_16,255,1);
   setup_ccp1(CCP_PWM);
   set_pwm1_duty(229);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
   
   while(1){
      duty = read_adc(ADC_START_AND_READ);
      set_pwm1_duty(duty);
   }

}
