#include "RCC.hpp"

// RCC Register Structure
typedef struct {
    volatile uint32_t CR;            // Control register
    volatile uint32_t PLLCFGR;       // PLL configuration register
    volatile uint32_t CFGR;          // Clock configuration register
    volatile uint32_t CIR;           // Clock interrupt register
    volatile uint32_t AHB1RSTR;      // AHB1 peripheral reset register
    volatile uint32_t AHB2RSTR;      // AHB2 peripheral reset register
    volatile const uint64_t reserved1; // Reserved
    volatile uint32_t APB1RSTR;      // APB1 peripheral reset register
    volatile uint32_t APB2RSTR;      // APB2 peripheral reset register
    volatile const uint64_t reserved2; // Reserved
    volatile uint32_t AHB1ENR;       // AHB1 peripheral clock enable register
    volatile uint32_t AHB2ENR;       // AHB2 peripheral clock enable register
    volatile const uint64_t reserved3; // Reserved
    volatile uint32_t APB1ENR;       // APB1 peripheral clock enable register
    volatile uint32_t APB2ENR;       // APB2 peripheral clock enable register
    volatile const uint64_t reserved4; // Reserved
    volatile uint32_t AHB1LPENR;     
    volatile uint32_t AHB2LPENR;     
    volatile const uint64_t reserved5; // Reserved
    volatile uint32_t APB1LPENR;   
    volatile uint32_t APB2LPENR;   
    volatile const uint64_t reserved6; // Reserved
    volatile uint32_t BDCR;          
    volatile uint32_t CSR;           // Control/status register
    volatile const uint64_t reserved7; // Reserved
    volatile uint32_t SSCGR;        
    volatile uint32_t PLLI2SCFGR;   
    volatile const uint32_t reserved8; // Reserved
    volatile uint32_t DCKCFGR;       
} RCC_Register_t;


void RCC_EnableGPIOClock(GPIO_PORT port) {
    switch (port) {
        case GPIO_PORT_A:
            RCC->AHB1ENR |= (1U << 0); // Enable GPIOA clock
            break;
        case GPIO_PORT_B:
            RCC->AHB1ENR |= (1U << 1); // Enable GPIOB clock
            break;
        case GPIO_PORT_C:
            RCC->AHB1ENR |= (1U << 2); // Enable GPIOC clock
            break;
        default:
           
            break;
    }
}