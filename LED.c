#include "main.h"

void Delay_Timer(uint32_t time)
{
    for (; time > 0; time--)
    {
    }
} // 딜레이 주겠다는 문

int main(void)
{
    RCC->APB2ENR |= 0x1 << 2;   //==0x4;PortA를 버스 탑승
    GPIOA->CRL &= ~(0x1 << 22); //==~0x400000;//pa5 출력, 속도 10MHz 선택
    GPIOA->CRL |= 0x1 << 20;    //==0x100000;
    while (1)
    {
        GPIOA->BSRR |= 0x1 << 5; //==0x20;LED ON
        Delay_Timer(100000);
        GPIOA->BSRR |= 0x1 << 21; //==20000 LED off
        Delay_Timer(100000);
    }
}
