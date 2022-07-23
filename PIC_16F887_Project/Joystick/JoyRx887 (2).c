#include "D:\Work T.Pongsak\Microcontroller\Work\Joystick\JoyRx887.h"
#use delay (clock=20m)
#include <lcd.c>
char save[];
int x=0,b=0,c=0,f=0,count=0,s=0,s1=0;
#INT_RDA
void rs232_isr(){
   x=getc();
//   lcd_putc(x);
   if(b==0){
      if(x=='W'){
         b=1;
         c=1;
      }else if(x=='Q'){
         b=1;
         c=2;
      }
   }else if(b==1){
      if(x==0x0d){
         b=0;
         f=1;
         s1=count;
      }else{
         if(x=='S'||x=='P'){
            s=count;
         }
         save[count]=x;
         count++;
      }
   }
}
void main()
{
   int i,sum=0,sum2=0,sc=0,a=0;
   setup_adc_ports(NO_ANALOGS|VSS_VDD);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);// This device COMP currently not supported by the PICWizard
//Setup_Oscillator parameter not selected from Intr Oscillotar Config tab

   // TODO: USER CODE!!
   enable_interrupts(GLOBAL);
   set_tris_d(0x00);
   set_tris_c(0x80);
   set_tris_b(0x00);
   output_c(0x00);
   output_b(0x00);
   lcd_init();
   do{
      x = getc();
   }while(x!='1');
   x=0;
   output_high(PIN_C0);
   enable_interrupts(INT_RDA);
   while(1){
      lcd_gotoxy(1,1);
      if(x=='O'){
         output_toggle(PIN_C2);
         lcd_putc(x);
      }else if(x=='J'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='K'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='I'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='H'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='G'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='A'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='B'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='C'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='D'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='E'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='F'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='M'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }else if(x=='N'){
         output_toggle(PIN_C1);
         lcd_putc(x);
      }
      if(f==1){
         sum=0;
         sum2=0;
         s1=s1-s;
         for(i=0;i<count;i++){
            if(save[i]=='S'||save[i]=='P'){
               i++;
               sc=1;
            }
            save[i]=save[i]&0x0f;
            if(sc==1){
               if(s1==4){
                  if(a==0){
                     save[i]=save[i]*100;
                     a++;
                  }else if(a==1){
                     save[i]=save[i]*10;
                     a++;
                  }
               }else if(s1==3){
                  if(a==0){
                     save[i]=save[i]*10;
                     a++;
                  }
               }
               sum2=sum2+save[i];
            }else{
               if(s==3){
                  if(i==0){
                     save[i]=save[i]*100;
                  }else if(i==1){
                     save[i]=save[i]*10;
                  }
               }else if(s==2||s==4){
                  if(i==0){
                     save[i]=save[i]*10;
                  }
               }
               sum=sum+save[i];
            }
         }
      //      output_b(sum);
//            output_high(PIN_C1);
     //       output_b(sum2);
         f=0;
         a=0;
         sc=0;
         count=0;
         lcd_putc('\f');
      }
      if(c==1){
         if(sum==0){
            if(sum2==127){
               printf(lcd_putc,"Up1");
            }
         }else if(sum==127){
            if(sum2==0){
               printf(lcd_putc,"Left1");           
            }else if(sum2==127){
               printf(lcd_putc,"Center1");
            }else if(sum2==255){
               printf(lcd_putc,"Right1");
            }
         }else if(sum==255){
            if(sum2==127){
               printf(lcd_putc,"Down1");
            }
         }
      }else if(c==2){
         if(sum==0){
            if(sum2==127){
               printf(lcd_putc,"Up");
            }
         }else if(sum==127){
            if(sum2==0){
               printf(lcd_putc,"Left");           
            }else if(sum2==127){
               printf(lcd_putc,"Center");
            }else if(sum2==255){
               printf(lcd_putc,"Right");
            }  
         }else if(sum==255){
            if(sum2==127){
               printf(lcd_putc,"Down");
            }
         }
      }  
   }
}


