/***********Define Bit for Connect ZX-PSX********************/
#define CLK        PortA.F0
#define DOUT       PortA.F1
#define DIN        PortA.F2
#define CS         PortA.F3
#define C3         PortC.F3     //reflex c3
#define C4         PortC.F4     //reflex c4
#define C6         PortC.F6     //reflex c6

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
         for (i=0;i<8;i++){                             // Loop 8 Time for Send and Recieve Byte
             if ((BYTE_OUT&j)==j )                      // Test Bit 0 or 1
             { DOUT=1;}                                 // Set Dout
             else
             { DOUT=0;}
             CLK=1;                                     // Clock Pulse High
             BYTE_IN=(BYTE_IN>>1);                      // Receive Byte LSB First
             if (DIN==1){BYTE_IN=(BYTE_IN | 0x80);}
             CLK=0;                                     // Clock Pulse Low
             j=j<<1;
             }
         return BYTE_IN;
}
/*******************************Define Function*************************************************/

void front()
{
   ANSELH=0x00;
   TRISD.F0=0;TRISD.F1=0;         //initial M1
   TRISB.F1=0;TRISB.F2=0;         //initial M2
   TRISC.F1=0;TRISC.F2=0;         //Motor M-2 2E,Motor M-1 1E
   PORTC.F1=1;PORTC.F2=1;         //start Motor
   Pwm1_Change_Duty(230);         //Motor M-1 75% Speed
   Pwm2_Change_Duty(230);         //Motor M-2 75% Speed
   PORTD.F0=1;PORTD.F1=0;
   PORTB.F1=1;PORTB.F2=0;
}
void back()
{
   ANSELH=0x00;
   TRISD.F0=0;TRISD.F1=0;         //initial M1
   TRISB.F1=0;TRISB.F2=0;         //initial M2
   TRISC.F1=0;TRISC.F2=0;         //Motor M-2 2E,Motor M-1 1E
   PORTC.F1=1;PORTC.F2=1;         //start Motor
   Pwm1_Change_Duty(230);         //Motor M-1 75% Speed
   Pwm2_Change_Duty(230);         //Motor M-2 75% Speed
   PORTD.F0=0;PORTD.F1=1;
   PORTB.F1=0;PORTB.F2=1;
}
void turn_right()
{
   ANSELH=0x00;
   TRISD.F0=0;TRISD.F1=0;          //initial M1
   TRISB.F1=0;TRISB.F2=0;         //initial M2
   TRISC.F1=0;TRISC.F2=0;         //Motor M-2 2E,Motor M-1 1E
   PORTC.F1=0;PORTC.F2=1;         //start Motor
   Pwm1_Change_Duty(230);         //Motor M-1 75% Speed
   Pwm2_Change_Duty(230);         //Motor M-2 75% Speed
   PORTD.F0=1;PORTD.F1=0;
}
void turn_left()
{
   ANSELH=0x00;
   TRISD.F0=0;TRISD.F1=0;         //initial M1
   TRISB.F1=0;TRISB.F2=0;         //initial M2
   TRISC.F1=0;TRISC.F2=0;         //Motor M-2 2E,Motor M-1 1E
   PORTC.F1=1;PORTC.F2=0;         //start Motor
   Pwm1_Change_Duty(230);         //Motor M-1 75% Speed
   Pwm2_Change_Duty(230);         //Motor M-2 75% Speed
   PORTD.F0=0;PORTD.F1=1;
   PORTB.F1=1;PORTB.F2=0;
}
void turn_around_right()
{
   ANSELH=0x00;
   TRISD.F0=0;TRISD.F1=0;         //initial M1
   TRISB.F1=0;TRISB.F2=0;         //initial M2
   TRISC.F1=0;TRISC.F2=0;         //Motor M-2 2E,Motor M-1 1E
   PORTC.F1=1;PORTC.F2=1;         //start Motor
   Pwm1_Change_Duty(230);         //Motor M-1 75% Speed
   Pwm2_Change_Duty(230);         //Motor M-2 75% Speed
   PORTD.F0=1;PORTD.F1=0;
   PORTB.F1=0;PORTB.F2=1;
}
void turn_around_left()
{
   ANSELH=0x00;
   TRISD.F0=0;TRISD.F1=0;         //initial M1
   TRISB.F1=0;TRISB.F2=0;         //initial M2
   TRISC.F1=0;TRISC.F2=0;         //Motor M-2 2E,Motor M-1 1E
   PORTC.F1=1;PORTC.F2=1;         //start Motor
   Pwm1_Change_Duty(230);         //Motor M-1 75% Speed
   Pwm2_Change_Duty(230);         //Motor M-2 75% Speed
   PORTD.F0=0;PORTD.F1=1;
   PORTB.F1=1;PORTB.F2=0;
}
void stop()
{
   Pwm1_Change_Duty(128);              // Motor M-1 50% Speed
   Pwm2_Change_Duty(128);              // Motor M-2 50% Speed
   PORTC.F1=0;PORTC.F2=0;
}
void start()
{
   Pwm1_Change_Duty(128);              // Motor M-1 50% Speed
   Pwm2_Change_Duty(128);              // Motor M-2 50% Speed
   PORTC.F1=1;PORTC.F2=1;
}
void crip_out()
{
   //Servo Motor Turn Left Position
     Delay_ms(10);
     PORTC.F5=1; // High
     Delay_ms(1); // 1 ms Pulse
     PORTC.F5=0; // Low
     Delay_ms(20); // 20 ms
}
void crip_in()
{
   //Servo Motor Turn Right Position
     Delay_ms(10);
     PORTC.F5=1;
     Delay_ms(2); // 2 ms Pulse
     PORTC.F5=0;
     Delay_ms(20);
}
void start_pwm()
{

   Pwm1_Init(5000);                    // Initail PWM 1E
   Pwm2_Init(5000);                    // Initail PWM 2E
   Pwm1_Start();
   Pwm2_Start();
}
void stop_pwm()
{
   Pwm1_Stop();
   Pwm2_Stop();
   Pwm1_Change_Duty(128);              // Motor M-1 50% Speed
   Pwm2_Change_Duty(128);              // Motor M-2 50% Speed
   PORTC.F1=0;PORTC.F2=0;
}
void front_auto()
{
   while((C6==1 & C4==0 & C3==1)|(C6==0 & C4==1 & C3==1)|(C6==1 & C4==1 & C3==0))
   {
   if(C6==1 & C4==0 & C3==1)
   {
      front(); Delay_ms(200);
   }
   else if(C6==0 & C4==1 & C3==1)
   {
      turn_around_left(); Delay_ms(200);
   }
   else if(C6==1 & C4==1 & C3==0)
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
/*******************************Define Function*************************************************/
void main()
{
      char i;                                           // servo
      ANSEL=0x00;                                       // Set PORTA to digital I/O
      TRISA=0b00000100;
      TRISC.F5=0;                                       // SET RC5 to OUTPUT   (servo)
      ANSELH.F4=0;
      TRISB.F3=0;
      TRISC.F3=1;                                       // Set reflex input F3
      TRISC.F4=1;                                       // Set reflex input F4
      TRISC.F6=1;                                       // Set reflex input F6
      Lcd_Init(&PORTD);                                 // Initial LCD
      Lcd_Cmd(LCD_CURSOR_OFF);
      CLK=0;
      CS=1;
      DOUT=0;
      Delay_ms(500);
//********************************* Mode A Manual *********************************************
      while(1)
      {
      PORTB.F3=0;
      CS=0;
          PSX_IN=PSX_TxRx(0x01);                        // Send Start Command
          PSX_ID=PSX_TxRx(0x42);                        // Send Command Read Switch and Read ID
          PSX_STATUS=PSX_TxRx(0x00);                    // Read STATUS (0x5A)
          PSX_LEFT=PSX_TxRx(0x00);                      // Read Byte 0
          PSX_RIGHT=PSX_TxRx(0x00);                     // Read Byte 1
      CS=1;

          // front
          if(PSX_LEFT==222)   // ^ button
          {
             front();
          }
          // back
          if(PSX_LEFT==126)   // V button
          {
             back();
          }
          // stop
          if(PSX_LEFT==254)
          {
             stop();
          }
          //turn around right
          if(PSX_LEFT==190)   // > button
          {
             turn_around_right();
          }
          //turn around left
          if(PSX_RIGHT==254)   // < button
          {
             turn_around_left();
          }
          //turn left
          if(PSX_RIGHT==239)   // R1 button
          {
             turn_left();
          }
          // turn right
          if(PSX_RIGHT==247)   // L1 button
          {
             turn_right();
          }
          if(PSX_RIGHT==191)  // O button  control servo
          {
             crip_out();
          }
          if(PSX_RIGHT==127)  // X button  control servo
          {
             crip_in();
          }
          if(PSX_LEFT==238) // start button
          {
             start_pwm();
          }
          if(PSX_LEFT==252) // select button
          {
             stop_pwm();
          }

//********************************* Mode B Automatic *********************************************
    if(PORTB.F0==0)
    {
     b=1;
     //crip_out_auto();
     front(); Delay_ms(2000);
      while(1)
      {
        if(b==1)
        {
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            stop(); Delay_ms(500); crip_in_auto(); back(); Delay_ms(1000);
            turn_right_auto(); Delay_ms(4000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==1)
          {
            front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            stop(); Delay_ms(500); crip_out_auto(); back(); Delay_ms(1000);
            turn_right_auto(); Delay_ms(4000);
          }
          b++;
        }
        /*if(b==2)
        {
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            stop(); Delay_ms(500); crip_in_auto(); back(); Delay_ms(1000);
            turn_right_auto(); Delay_ms(4000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==1)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            stop(); Delay_ms(500); crip_out_auto(); back(); Delay_ms(1000);
            turn_right_auto(); Delay_ms(4000);
          }
          b++;
        }
        if(b==3)
        {
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            stop(); Delay_ms(500); crip_in_auto(); back(); Delay_ms(1000);
            turn_right_auto(); Delay_ms(4000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==1)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==1)
          {
            front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            stop(); Delay_ms(500); crip_out_auto(); back(); Delay_ms(1000);
            turn_right_auto(); Delay_ms(4000);
          }
          b++;
        }
        if(b==4)
        {
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==1)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
             front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            stop(); Delay_ms(500); crip_in_auto(); back(); Delay_ms(1000);
            turn_right_auto(); Delay_ms(4000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
             front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==1)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            stop(); Delay_ms(500); crip_out_auto(); back(); Delay_ms(1000);
            turn_right_auto(); Delay_ms(4000);
          }
          b++;
        }
        if(b==5)
        {
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==1)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
          stop(); Delay_ms(500); crip_in_auto(); back(); Delay_ms(1000);
          turn_right_auto(); Delay_ms(4000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_left_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1100); turn_right_auto();
          }
          front_auto();
          if(C6==0 & C4==0 & C3==1)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==0 & C4==0 & C3==0)
          {
            front(); Delay_ms(1000);
          }
          front_auto();
          if(C6==1 & C4==0 & C3==0)
          {
            stop(); Delay_ms(500); crip_out_auto(); back(); Delay_ms(1000);
            turn_right_auto(); Delay_ms(4000);
          }
          b++;
        } */
        else stop();





      }
    }
  }
}