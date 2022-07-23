#line 1 "C:/Documents and Settings/witsarut/Desktop/robot_code/joy_servo/joy_servo.c"









unsigned char PSX_IN;
unsigned char PSX_ID;
unsigned char i;
unsigned char a;
unsigned char b;
unsigned char PSX_STATUS;
unsigned char PSX_Left;
unsigned char PSX_RIGHT;
unsigned char dec_[4];
unsigned char PSX_TxRx(unsigned char BYTE_OUT){
 unsigned char BYTE_IN=0;
 unsigned char j=0x01;
 for (i=0;i<8;i++){
 if ((BYTE_OUT&j)==j )
 {  PortA.F1 =1;}
 else
 {  PortA.F1 =0;}
  PortA.F0 =1;
 BYTE_IN=(BYTE_IN>>1);
 if ( PortA.F2 ==1){BYTE_IN=(BYTE_IN | 0x80);}
  PortA.F0 =0;
 j=j<<1;
 }
 return BYTE_IN;
}


void front()
{
 ANSELH=0x00;
 TRISD.F0=0;TRISD.F1=0;
 TRISB.F1=0;TRISB.F2=0;
 TRISC.F1=0;TRISC.F2=0;
 PORTC.F1=1;PORTC.F2=1;
 Pwm1_Change_Duty(230);
 Pwm2_Change_Duty(230);
 PORTD.F0=1;PORTD.F1=0;
 PORTB.F1=1;PORTB.F2=0;
}
void back()
{
 ANSELH=0x00;
 TRISD.F0=0;TRISD.F1=0;
 TRISB.F1=0;TRISB.F2=0;
 TRISC.F1=0;TRISC.F2=0;
 PORTC.F1=1;PORTC.F2=1;
 Pwm1_Change_Duty(230);
 Pwm2_Change_Duty(230);
 PORTD.F0=0;PORTD.F1=1;
 PORTB.F1=0;PORTB.F2=1;
}
void turn_right()
{
 ANSELH=0x00;
 TRISD.F0=0;TRISD.F1=0;
 TRISB.F1=0;TRISB.F2=0;
 TRISC.F1=0;TRISC.F2=0;
 PORTC.F1=0;PORTC.F2=1;
 Pwm1_Change_Duty(230);
 Pwm2_Change_Duty(230);
 PORTD.F0=1;PORTD.F1=0;
}
void turn_left()
{
 ANSELH=0x00;
 TRISD.F0=0;TRISD.F1=0;
 TRISB.F1=0;TRISB.F2=0;
 TRISC.F1=0;TRISC.F2=0;
 PORTC.F1=1;PORTC.F2=0;
 Pwm1_Change_Duty(230);
 Pwm2_Change_Duty(230);
 PORTD.F0=0;PORTD.F1=1;
 PORTB.F1=1;PORTB.F2=0;
}
void turn_around_right()
{
 ANSELH=0x00;
 TRISD.F0=0;TRISD.F1=0;
 TRISB.F1=0;TRISB.F2=0;
 TRISC.F1=0;TRISC.F2=0;
 PORTC.F1=1;PORTC.F2=1;
 Pwm1_Change_Duty(230);
 Pwm2_Change_Duty(230);
 PORTD.F0=1;PORTD.F1=0;
 PORTB.F1=0;PORTB.F2=1;
}
void turn_around_left()
{
 ANSELH=0x00;
 TRISD.F0=0;TRISD.F1=0;
 TRISB.F1=0;TRISB.F2=0;
 TRISC.F1=0;TRISC.F2=0;
 PORTC.F1=1;PORTC.F2=1;
 Pwm1_Change_Duty(230);
 Pwm2_Change_Duty(230);
 PORTD.F0=0;PORTD.F1=1;
 PORTB.F1=1;PORTB.F2=0;
}
void stop()
{
 Pwm1_Change_Duty(128);
 Pwm2_Change_Duty(128);
 PORTC.F1=0;PORTC.F2=0;
}
void start()
{
 Pwm1_Change_Duty(128);
 Pwm2_Change_Duty(128);
 PORTC.F1=1;PORTC.F2=1;
}
void crip_out()
{

 Delay_ms(10);
 PORTC.F5=1;
 Delay_ms(1);
 PORTC.F5=0;
 Delay_ms(20);
}
void crip_in()
{

 Delay_ms(10);
 PORTC.F5=1;
 Delay_ms(2);
 PORTC.F5=0;
 Delay_ms(20);
}
void start_pwm()
{

 Pwm1_Init(5000);
 Pwm2_Init(5000);
 Pwm1_Start();
 Pwm2_Start();
}
void stop_pwm()
{
 Pwm1_Stop();
 Pwm2_Stop();
 Pwm1_Change_Duty(128);
 Pwm2_Change_Duty(128);
 PORTC.F1=0;PORTC.F2=0;
}
void front_auto()
{
 while(( PortC.F6 ==1 &  PortC.F4 ==0 &  PortC.F3 ==1)|( PortC.F6 ==0 &  PortC.F4 ==1 &  PortC.F3 ==1)|( PortC.F6 ==1 &  PortC.F4 ==1 &  PortC.F3 ==0))
 {
 if( PortC.F6 ==1 &  PortC.F4 ==0 &  PortC.F3 ==1)
 {
 front(); Delay_ms(200);
 }
 else if( PortC.F6 ==0 &  PortC.F4 ==1 &  PortC.F3 ==1)
 {
 turn_around_left(); Delay_ms(200);
 }
 else if( PortC.F6 ==1 &  PortC.F4 ==1 &  PortC.F3 ==0)
 {
 turn_around_right(); Delay_ms(200);
 }
 }
}
void turn_right_auto()
{
 turn_around_right(); Delay_ms(2000);
}
void turn_left_auto()
{
 turn_around_left(); Delay_ms(2000);
}
void crip_out_auto()
 {
 for(i=0;i<=20;i++) crip_out();
 }
void crip_in_auto()
 {
 for(i=0;i<=20;i++) crip_in();
 }

void main()
{
 char i;
 ANSEL=0x00;
 TRISA=0b00000100;
 TRISC.F5=0;
 ANSELH.F4=0;
 TRISB.F3=0;
 TRISC.F3=1;
 TRISC.F4=1;
 TRISC.F6=1;
 Lcd_Init(&PORTD);
 Lcd_Cmd(LCD_CURSOR_OFF);
  PortA.F0 =0;
  PortA.F3 =1;
  PortA.F1 =0;
 Delay_ms(500);

 while(1)
 {
 PORTB.F3=0;
  PortA.F3 =0;
 PSX_IN=PSX_TxRx(0x01);
 PSX_ID=PSX_TxRx(0x42);
 PSX_STATUS=PSX_TxRx(0x00);
 PSX_LEFT=PSX_TxRx(0x00);
 PSX_RIGHT=PSX_TxRx(0x00);
  PortA.F3 =1;


 if(PSX_LEFT==222)
 {
 front();
 }

 if(PSX_LEFT==126)
 {
 back();
 }

 if(PSX_LEFT==254)
 {
 stop();
 }

 if(PSX_LEFT==190)
 {
 turn_around_right();
 }

 if(PSX_RIGHT==254)
 {
 turn_around_left();
 }

 if(PSX_RIGHT==239)
 {
 turn_left();
 }

 if(PSX_RIGHT==247)
 {
 turn_right();
 }
 if(PSX_RIGHT==191)
 {
 crip_out();
 }
 if(PSX_RIGHT==127)
 {
 crip_in();
 }
 if(PSX_LEFT==238)
 {
 start_pwm();
 }
 if(PSX_LEFT==252)
 {
 stop_pwm();
 }


 if(PORTB.F0==0)
 {
 b=1;

 front(); Delay_ms(2000);
 while(1)
 {
 if(b==1)
 {
 front_auto();
 if( PortC.F6 ==1 &  PortC.F4 ==0 &  PortC.F3 ==0)
 {
 front(); Delay_ms(1100); turn_right_auto();
 }
 front_auto();
 if( PortC.F6 ==1 &  PortC.F4 ==0 &  PortC.F3 ==0)
 {
 front(); Delay_ms(1100); turn_right_auto();
 }
 front_auto();
 if( PortC.F6 ==0 &  PortC.F4 ==0 &  PortC.F3 ==0)
 {
 stop(); Delay_ms(500); crip_in_auto(); back(); Delay_ms(1000);
 turn_right_auto(); Delay_ms(4000);
 }
 front_auto();
 if( PortC.F6 ==0 &  PortC.F4 ==0 &  PortC.F3 ==0)
 {
 front(); Delay_ms(1100); turn_right_auto();
 }
 front_auto();
 if( PortC.F6 ==0 &  PortC.F4 ==0 &  PortC.F3 ==0)
 {
 front(); Delay_ms(1100); turn_left_auto();
 }
 front_auto();
 if( PortC.F6 ==0 &  PortC.F4 ==0 &  PortC.F3 ==1)
 {
 front(); Delay_ms(1100); turn_left_auto();
 }
 front_auto();
 if( PortC.F6 ==0 &  PortC.F4 ==0 &  PortC.F3 ==0)
 {
 stop(); Delay_ms(500); crip_out_auto(); back(); Delay_ms(1000);
 turn_right_auto(); Delay_ms(4000);
 }
 b++;
 }
#line 558 "C:/Documents and Settings/witsarut/Desktop/robot_code/joy_servo/joy_servo.c"
 else stop();





 }
 }
 }
}
