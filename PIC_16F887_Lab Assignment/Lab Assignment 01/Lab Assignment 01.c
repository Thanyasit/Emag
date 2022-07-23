#include "D:\Work T.Pongsak\Microcontroller\Work\Lab Assignment\Lab Assignment 01\Lab Assignment 01.h"
#use delay (clock=20M)
#define ISw PIN_D6
#define DSw PIN_D7
int LED(void);
int count=0,count1=0,seg1,i,f=0;
void main()
{
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
   set_tris_d(0b11111100);
   output_d(0x00);
   while(1){
      if(!input(ISw)){
         count++;
         if(count==10){
            count=0;
            count1++;
               if(count1==10){
                  count1=0;
               }
         }
         LED();
         while(!input(Isw)){
            LED();
         }
      }
      if(!input(DSw)){
         count--;
         if(count==-1){
            count=9;
            count1--;
               if(count1==-1){
                  count1=9;
               }
         }
         LED();
         while(!input(Dsw)){
            LED();
         }
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
            output_c(segment[count]);
         }else{
            output_c(segment[count1]);
         }
         delay_ms(1);
         seg1 = seg1>>1;
         f=~f;
      }
      output_d(0b11111111);
}

