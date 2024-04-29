#include "../HAL/LCD/LCD.h"
#include "../LIB/STD_TYPES.h"
#include "../HAL/HSWITCH/HSWITCH.h"
#include  "DEMO.h"


extern uint8_t DISPLAY_MODE ;


stopwatch_time G_stopwatch_current_time=

{
0,0,0,0
};



extern uint8_t buttonConditions;

uint8_t start_flag=1;
 uint8_t pause_flag=0;






void stopwatch()


{


if(start_flag ==0 || pause_flag == 1)
{
   if(start_flag == 0)
   {
        G_stopwatch_current_time.milliseconds=0;
        G_stopwatch_current_time.seconds=0;
        G_stopwatch_current_time.minutes=0;
        G_stopwatch_current_time.hours=0;
        
   }
   if(pause_flag == 1)
   {
 
   }
   
}

if(pause_flag == 0)
{
 if(start_flag==1 ||pause_flag == 1 )
    {
        G_stopwatch_current_time.milliseconds+=100;

    if(G_stopwatch_current_time.milliseconds==1000)
    {
        G_stopwatch_current_time.milliseconds=0;
        G_stopwatch_current_time.seconds++;

    }

    if(G_stopwatch_current_time.seconds==60)
    {
        G_stopwatch_current_time.seconds=0;
        G_stopwatch_current_time.minutes++;
    }

    if(G_stopwatch_current_time.minutes==60)
    {
        G_stopwatch_current_time.minutes=0;
        G_stopwatch_current_time.hours++;
    }
    
   
    }
 
 }
  
 }



