#include <stm8s.h>
#include <stm8s_gpio.h>
#include <stm8s_clk.h>
#include <delay.h>
#include "main.h"

int CLK_Config(void)
{
    ErrorStatus status = ERROR;

    CLK_DeInit();

    /* Configure the Fcpu to DIV1*/
    CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
   
    /* Configure the HSI prescaler to the optimal value */
    CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);

    /* Configure the system clock to use HSI clock source and to run at 16Mhz */
    status = CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
    
    return status;
}

int main( void )
{
//  disableInterrupts();
  while ( !CLK_Config() );
  
  GPIO_Init(GPIOB, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_SLOW);
  
  while(1)
  { 
    GPIO_WriteLow(GPIOB, GPIO_PIN_5);
    delay_ms(1000);
    GPIO_WriteHigh(GPIOB, GPIO_PIN_5);
    delay_ms(1000);
  }
}
