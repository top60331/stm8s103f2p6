#ifndef MAIN_H_
#define MAIN_H_

#ifdef __cplusplus
extern "C"
{
#endif

  
#include <stm8s.h>
  
#define STATUS_LED_ON()         GPIO_WriteLow(GPIOC , GPIO_PIN_7)
#define STATUS_LED_OFF()        GPIO_WriteHigh(GPIOC , GPIO_PIN_7)
#define STATUS_LED_TOG()        GPIO_WriteReverse(GPIOC , GPIO_PIN_7)
  
#define SSR_1_ON()              GPIO_WriteLow(GPIOD , GPIO_PIN_3)           
#define SSR_1_OFF()             GPIO_WriteHigh(GPIOD , GPIO_PIN_3) 
#define SSR_2_ON()              GPIO_WriteLow(GPIOD , GPIO_PIN_2)           
#define SSR_2_OFF()             GPIO_WriteHigh(GPIOD , GPIO_PIN_2) 
#define SSR_1_TOG()          GPIO_WriteReverse(GPIOD , GPIO_PIN_3)
#define SSR_2_TOG()          GPIO_WriteReverse(GPIOD , GPIO_PIN_2)

extern bool F_1sec;

#ifdef __cplusplus
}
#endif

#endif /* MAIN_H_ */