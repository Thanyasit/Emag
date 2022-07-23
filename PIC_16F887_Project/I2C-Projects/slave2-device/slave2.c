#include "D:\2557-class\CCS-project\I2C-Projects\slave2-device\slave2.h"
#define LCD_TYPE 2
#include <lcd.c>

BYTE address, buffer[16];
int1 rec=0,isMe=0;

#INT_SSP
void ssp_interupt ()
{
   BYTE incoming, state;

   state = i2c_isr_state(i2cS);
/* ******** check for send data to master only ************ */
/*
   if(state==0)isMe=1;
   if(isMe==1){
      if(state==1){
         incoming = i2c_read(i2cS);   //read address of register
         address = incoming;
      }
      if(state==0x80){
         i2c_write(i2cS,buffer[address]);  //send register to master
         isMe=0;
      }      
   }
*/
   
   if(state==0) isMe=1;
   
   if(isMe==1){
      if(state<0x80){     //Master send data to slave
         if(state==1){    // master send address of register
            incoming = i2c_read(i2cS);
            address = incoming;
         }
         if(state==2){     // master send data
            incoming = i2c_read(i2cS);  
            buffer[address] = incoming; 
            isMe=0;
            printf(lcd_putc,"%d",buffer[address]);
         }
      }else if(state==0x80){     //Master want to recieve
            i2c_write(i2cS,buffer[address]); //printf(lcd_putc,"%d",address);
            isMe=0;
      }
   }
}

void main()
{
   lcd_init();

   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);

   enable_interrupts(GLOBAL);
   enable_interrupts(INT_SSP);

   lcd_putc("slave2");lcd_gotoxy(1,2);
   lcd_putc("recieve : ");
   while (TRUE) {
   } 

}
