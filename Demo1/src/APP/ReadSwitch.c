#include"DEMO.h"

#include "../LIB/STD_TYPES.h"
#include "../HAL/HSWITCH/HSWITCH.h"
#include "../MCAL/UART/UART.h"
#include <stdlib.h>


#define CHECKSUM_    0b0010
#define PREFIX_MASK 0b1100
#define PREFIX_VAL  0b0100

extern uint8_t start_flag;
extern uint8_t pause_flag;
extern uint8_t  DISPLAY_MODE ;
 uint16_t volatile buttonConditions = 0;
uint16_t prevButtonConditions = 0;
extern uint8_t  current_edit_position;

// Function to read switch conditions
void ReadSwitch(void) {
  


    static volatile uint8_t  receivedIndex = 0; // Variable to store received index as integer


    // Start receiving button index asynchronously
    USART_GetByteASynchronous(USART_Channel_2, &receivedIndex);


 switch ( receivedIndex ) {
            case START_STOP:
                buttonConditions = (1 << START_STOP);
                 start_flag^=1;
                 
                break;
            case CONT:
                buttonConditions = (1 << CONT);

                break;
            case PAUSE:
                buttonConditions = (1 << PAUSE);
                pause_flag^=1;
                break;
            case MODE:
                buttonConditions = (1 << MODE); 
                if ((buttonConditions & (1 << MODE))) 
                   { 
                   DISPLAY_MODE ^=1;

                  }
                break;
            case UP:
                buttonConditions = (1 << UP);
                break;
            case DOWN: //06
                buttonConditions = (1 << DOWN);
                break;
            case LEFT: //07
                buttonConditions = (1 << LEFT);
                  current_edit_position-=3;
                break;
            case RIGHT: //08
                buttonConditions = (1 << RIGHT);
                 current_edit_position += 3;
                
                break;
            default:
                break;
        }

receivedIndex =0;
}


   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   











