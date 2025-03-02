#ifndef RCC_HPP
#define RCC_HPP

#include "STDTYPES.hpp"
#include "GPIO.hpp"


constexpr uint32_t RCC_BASE_ADDRESS = 0x40023800UL;
#define RCC ((RCC_Register_t*)RCC_BASE_ADDRESS)


void RCC_EnableGPIOClock(GPIO_PORT port);

#endif // RCC_HPP