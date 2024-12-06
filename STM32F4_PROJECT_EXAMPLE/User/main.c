#include "stm32f4xx.h"

static __IO uint32_t uwTimingDelay;

int main ()
{
	while(1)
	{      
    ;       
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

