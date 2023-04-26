#include "main.h"

void Delay_Timer(uint32_t time)
{
    for (; time > 0; time--)
    {
    }
} // 딜레이 주겠다는 문

void set_led(uint8_t n)
{
    switch (n)
    {
    case 1:
        GPIOA->BSRR |= 0x1 << 12;
        break;
    case 2:

        GPIOA->BSRR |= 0x1 << 11;
        break;
    case 3:
        GPIOB->BSRR |= 0x1 << 12;
        break;
    case 4:
        GPIOB->BSRR |= 0x1 << 11;
        break;
    }
}
void reset_led()
{
    GPIOA->BSRR |= (0x1 << 27) | (0x1 << 28); // PA11 PA12 led reset
    GPIOB->BSRR |= (0x1 << 27) | (0x1 << 28); // PB11 PB12 led reset
}

int main(void)
{
    RCC->APB2ENR |= 0x4;    // 포트A
    RCC->APB2ENR |= 0x8;    // 포트B
    GPIOA->CRH &= ~0x44000; //~(0x10001<<14);//0x4400<<14
    GPIOA->CRH |= 0x11000;  //~(0x10001<<12);
    GPIOB->CRH &= ~0x44000; //~(0x10001<<14);
    GPIOB->CRH |= 0x11000;  //~(0x10001<<12);
    while (1)
    {
        for (uint8_t i = 1; i < 5; i++)
        {
            set_led(i);
            Delay_Timer(10000);
            reset_led();
            Delay_Timer(10000);
        }
    }
}
