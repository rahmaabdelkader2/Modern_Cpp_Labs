#include "GPIO.hpp"
#include "RCC.hpp"

// Constructor
GPIO::GPIO(GPIO_PORT port, GPIO_PIN pin, GPIO_MODE mode)
    : port(port), pin(pin), mode(mode), state(GPIO_STATE_LOW) {
        
    // Calculate GPIO base address
    uint32_t gpioBase = Set_GPIO_Base(port);
    gpioRegisters = reinterpret_cast<GPIO_Registers_t*>(gpioBase);

    // Enable GPIO clock
    RCC_EnableGPIOClock(port);

    // Configure GPIO mode
    gpioRegisters->MODER &= ~(0b11U << (pin * 2)); // Clear existing mode
    gpioRegisters->MODER |= (static_cast<uint32_t>(mode) << (pin * 2)); // Set new mode

    // Configure GPIO output type (push-pull by default)
    gpioRegisters->OTYPER &= ~(1U << pin); // Clear output type (push-pull)

    // Configure GPIO speed (low speed by default)
    gpioRegisters->OSPEEDR &= ~(0b11U << (pin * 2)); // Clear speed
    gpioRegisters->OSPEEDR |= (0b01U << (pin * 2)); // Set medium speed

    // Configure GPIO pull-up/pull-down (no pull by default)
    gpioRegisters->PUPDR &= ~(0b11U << (pin * 2)); // Clear pull-up/pull-down
}

// Set GPIO port
void GPIO::set_port(GPIO_PORT port) {
    this->port = port;
    uint32_t gpioBase = Set_GPIO_Base(port);
    gpioRegisters = reinterpret_cast<GPIO_Registers_t*>(gpioBase);
}

// Set GPIO pin
void GPIO::set_pin(GPIO_PIN pin) {
    this->pin = pin;
}

// Set GPIO mode
void GPIO::set_mode(GPIO_MODE mode) {
    this->mode = mode;
    gpioRegisters->MODER &= ~(0b11U << (pin * 2)); // Clear existing mode
    gpioRegisters->MODER |= (static_cast<uint32_t>(mode) << (pin * 2));  // Set new mode
}

// Set GPIO pin state
void GPIO::set_pin_state(GPIO_STATE state) {
    this->state = state;
    if (state == GPIO_STATE_HIGH) {
        gpioRegisters->ODR |= (1U << pin); // Set pin high
    } else {
        gpioRegisters->ODR &= ~(1U << pin); // Set pin low
    }
}

// Destructor
GPIO::~GPIO() {
   
}