#include"DEMO.h"



void UART_init()
{




















uint8_t volatile data_recieved=0;

USART_SendByteAsynchronous(USART_Channel_2, 'a');
USART_GetByteASynchronous(USART_Channel_2, &data_recieved);
if(data_recieved == 'y')
{

}
}