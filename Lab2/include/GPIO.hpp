#ifndef GPIO_HPP
#define GPIO_HPP

#define RCC_BASE_ADDRESS   0x40023800
#define RCC_AHB1ENR        *((volatile unsigned int*)(RCC_BASE_ADDRESS + 0x30))

#define GPIOA_BASE         0x40020000
#define GPIOB_BASE         0x40020400
#define GPIOC_BASE         0x40020800

class Gpio {
private:
    volatile unsigned int* MODER_r;
    volatile unsigned int* ODR_r;
    volatile unsigned int* BSRR_r;
    unsigned int pin;

public:
    enum Mode { INPUT = 0b00, OUTPUT = 0b01 };
    Gpio(unsigned int port, unsigned int pin, Mode mode);
    void setHigh();
    void setLow();
    void toggle();
};

#endif // GPIO_HPP