#include "stm32f4xx.h"
#include "Delay.h"

static __IO uint32_t uwTimingDelay;

int main ()
{

  // Enable the GPIOF Periph BUS AHB1 Clock.
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  // Config the LED GPIO_Pin_9 and GPIO_Pin_10.
  GPIO_InitTypeDef GPIO_Led;
  GPIO_Led.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_Led.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_Led.GPIO_OType = GPIO_OType_PP;
  GPIO_Led.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Led.GPIO_Speed = GPIO_High_Speed;

  // Init the GPIO.
  GPIO_Init(GPIOF, &GPIO_Led);

	while(1)
	{
    GPIO_SetBits(GPIOF, GPIO_Pin_9);	   
    GPIO_ResetBits(GPIOF, GPIO_Pin_10);

    Delay_ms(50);

    GPIO_SetBits(GPIOF, GPIO_Pin_10);	   
    GPIO_ResetBits(GPIOF, GPIO_Pin_9);

    Delay_ms(50);  
	}
}


/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (uwTimingDelay != 0x00)
  { 
    uwTimingDelay--;
  }
}

