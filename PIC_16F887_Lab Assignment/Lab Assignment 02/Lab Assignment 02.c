#include "/D:\Work T.Pongsak\Microcontroller\Work\Lab Assignment\Lab Assignment 02\Lab Assignment 02.h"
#use delay (clock=20M)
#define StartSw PIN_D4 
#define StopSw  PIN_D5
#define ResetSw PIN_D6
int time10=0,sec=0,sec1=0,f,seg1,i,A=0;
#int_timer0
void time0_isr(){
   time10++;
   set_timer0(61);
}
int LED(void);
void main()
{
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_DIV_256);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_TIMER0);
   set_tris_c(0x00);
   output_c(0x3f);
   while(1){
      if(A==1){
         if(time10==100){
            time10=0;
            sec++;
            if(sec==10){
               sec1++;
               sec=0;
               if(sec1==6){
                  sec1=0;
               }
            }
         }
      }
      if(!input(StartSw)){
         A=1;
//         enable_interrupts(INT_TIMER0);
         LED();
      }
      if(!input(StopSw)){
         A=0;
//         DISABLE_INTERRUPTS(INT_TIMER0);
         LED();
      }
      if(!input(ResetSw)){
         sec=0;
         sec1=0;
         time10=0;
         LED();
      }
      LED();
   }
}
int LED(){
   char segment[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
   seg1=0b11111101;
   for(i=0;i<2;i++){
      output_d(seg1);
      if(f==0){
         output_c(segment[sec]);
      }else{
         output_c(segment[sec1]);
      }
      delay_ms(1);
      seg1 = seg1>>1;
      f=~f;
   }
}
