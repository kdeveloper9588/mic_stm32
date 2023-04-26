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
    RCC->APB2ENR |= 0x1C;   // 포트 A B C
    GPIOA->CRH &= ~0x44000; //~(0x10001<<14);//0x4400<<14
    GPIOA->CRH |= 0x11000;  //~(0x10001<<12); port A11, A!2 output
    GPIOB->CRH &= ~0x44000; //~(0x10001<<14);
    GPIOB->CRH |= 0x11000;  //~(0x10001<<12); B11, B12 output
    GPIOC->CRH &= ~0x4;     // 0x1<<2
    GPIOC->CRH |= 0x8;      // portc 8 input
    GPIOC->ODR |= 0x1 << 8; // 입력일 때 추가 설정

    uint8_t i = 1;
    while (1)
    {
        if (GPIOC->IDR & 0x1 << 8)
        {
            reset_led();
        }
        else
        {
            set_led(i);
            Delay_Timer(300000);
            reset_led();
            Delay_Timer(300000);
            i++;
            if (i == 5)
            {
                i = 1;
            }
        }
    }
}
