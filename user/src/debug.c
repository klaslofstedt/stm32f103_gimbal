#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h" 
#include "misc.h" 
#include "stm32f4xx_exti.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_syscfg.h"

#include "debug.h"
#include "board.h"


void debug_init(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd(DEBUG_GPIO_CLK, ENABLE);
    
    GPIO_InitStructure.GPIO_Pin = DEBUG_IMU_TASK_PIN | DEBUG_TEL_TASK_PIN | DEBUG_MAIN_TASK_PIN | DEBUG_GPIOE_13 | DEBUG_GPIOE_15;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(DEBUG_GPIO_PORT, &GPIO_InitStructure);
}
