#include "main.h"

int main(void)
{
    RCC->APB2ENR |= 0x14; // 0x101<<2 과 (0x1 << 2), (0x1<<4);
    GPIOA->CRL &= ~(0x1 << 22);
    GPIOA->CRL |= 0x1 << 20; // PA5 output
    GPIOC->CRH &= ~(0x1 << 22);
    GPIOC->CRH |= 0x1 << 23; // pc13 input
    GPIOC->ODR |= 0x1 << 13;

    while (1)
    {
        if (GPIOC->IDR & 0x1 << 13)
        {                             // 마프에서 비교시에는 &를 쓴다.
            GPIOA->BSRR |= 0x1 << 21; // reset 이유는 풀업이라 1을 상시 보내는 상태임
        }
        else
        {
            GPIOA->BSRR |= 0x1 << 5; // set
        }
    }
}
