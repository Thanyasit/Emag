#include "D:\2557-class\CCS-project\I2C-Projects\master-device\master.h"


#define LCD_TYPE 2
#include <lcd.c>
void main()
{
   int incomming=9;
   lcd_init();
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_psp(PSP_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   lcd_putc("Recieve S1: ");
   
   
/* ********** send data to slave1 *********** */

   i2c_start(i2cM); 
   delay_ms(1);
   i2c_write(i2cM,0xA0);   // Slave address 
   delay_ms(1);
   i2c_write(i2cM,0);      // Register address
   delay_ms(1);
   i2c_write(i2cM,3);
   delay_ms(1);
   i2c_stop(i2cM); 
   
   delay_ms(10);
   i2c_start(i2cM); 
   delay_ms(1);
   i2c_write(i2cM,0xA0);   // Slave address 
   delay_ms(1);
   i2c_write(i2cM,1);      // Register address
   delay_ms(1);
   i2c_write(i2cM,7);
   delay_ms(1);
   i2c_stop(i2cM); 
 
 /* ****** read data from slave1 ******* */
 
   delay_ms(10);
   i2c_start(i2cM); 
   delay_ms(1);
   i2c_write(i2cM,0xA0);   // Slave address 
   delay_ms(1);
   i2c_write(i2cM,1);      // Register address
   delay_ms(1);
   i2c_start(i2cM);        //restart
   delay_ms(1);
   i2c_write(i2cM,0xA1);   // want to recieve
   incomming = i2c_read(i2cM,0);  // reading last byte, ack=0;
   i2c_stop(i2cM); 
   printf(lcd_putc,"%d",incomming);

   delay_ms(10);
   i2c_start(i2cM); 
   delay_ms(1);
   i2c_write(i2cM,0xA0);   // Slave address 
   delay_ms(1);
   i2c_write(i2cM,0);      // Register address
   delay_ms(1);
   i2c_start(i2cM);        //restart
   delay_ms(1);
   i2c_write(i2cM,0xA1);   // want to recieve
   incomming = i2c_read(i2cM,0);  // reading last byte, ack=0;
   i2c_stop(i2cM); 
   printf(lcd_putc,"%d",incomming);
   
   /* ********** send data to slave2 *********** */

   i2c_start(i2cM); 
   delay_ms(1);
   i2c_write(i2cM,0xB0);   // Slave address 
   delay_ms(1);
   i2c_write(i2cM,0);      // Register address
   delay_ms(1);
   i2c_write(i2cM,6);
   delay_ms(1);
   i2c_stop(i2cM); 
   
   delay_ms(10);
   i2c_start(i2cM); 
   delay_ms(1);
   i2c_write(i2cM,0xB0);   // Slave address 
   delay_ms(1);
   i2c_write(i2cM,1);      // Register address
   delay_ms(1);
   i2c_write(i2cM,9);
   delay_ms(1);
   i2c_stop(i2cM); 
 
 /* ****** read data from slave2 ******* */
 
   lcd_gotoxy(1,2);
   lcd_putc("Recieve S2: ");
   
   delay_ms(10);
   i2c_start(i2cM); 
   delay_ms(1);
   i2c_write(i2cM,0xB0);   // Slave address 
   delay_ms(1);
   i2c_write(i2cM,1);      // Register address
   delay_ms(1);
   i2c_start(i2cM);        //restart
   delay_ms(1);
   i2c_write(i2cM,0xB1);   // want to recieve
   incomming = i2c_read(i2cM,0);  // reading last byte, ack=0;
   i2c_stop(i2cM); 
   printf(lcd_putc,"%d",incomming);

   delay_ms(10);
   i2c_start(i2cM); 
   delay_ms(1);
   i2c_write(i2cM,0xB0);   // Slave address 
   delay_ms(1);
   i2c_write(i2cM,0);      // Register address
   delay_ms(1);
   i2c_start(i2cM);        //restart
   delay_ms(1);
   i2c_write(i2cM,0xB1);   // want to recieve
   incomming = i2c_read(i2cM,0);  // reading last byte, ack=0;
   i2c_stop(i2cM); 
   printf(lcd_putc,"%d",incomming);
   
   while(1);
}
