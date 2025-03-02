#ifndef GPIO_HPP
#define GPIO_HPP

#include "STDTYPES.hpp"

// GPIO Base Addresses
constexpr uint32_t GPIOA_BASE = 0x40020000UL;
constexpr uint32_t GPIOB_BASE = 0x40020400UL;
constexpr uint32_t GPIOC_BASE = 0x40020800UL;
constexpr uint32_t GPIO_OFFSET = 0x400UL; // Offset between GPIO peripherals

typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;  // Added Output type register
    volatile uint32_t OSPEEDR; // Added Output speed register
    volatile uint32_t PUPDR;   // Added Pull-up/pull-down register
    volatile uint32_t IDR;
    volatile uint32_t ODR;
} GPIO_Registers_t;

// GPIO Ports
typedef enum {
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C
} GPIO_PORT;

// GPIO Pins
typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
} GPIO_PIN;

// GPIO Modes
typedef enum {
    GPIO_MODE_INPUT = 0b00,
    GPIO_MODE_OUTPUT = 0b01,
    GPIO_MODE_ALTERNATE = 0b10,
    GPIO_MODE_ANALOG = 0b11
} GPIO_MODE;

// GPIO States
typedef enum {
    GPIO_STATE_LOW = 0,
    GPIO_STATE_HIGH = 1
} GPIO_STATE;

// GPIO Class
class GPIO {
protected:
    GPIO_PORT port;  // GPIO port (e.g., GPIO_PORT_A)
    GPIO_PIN pin;    // GPIO pin (e.g., PIN5)
    GPIO_MODE mode;  // GPIO mode (e.g., GPIO_MODE_OUTPUT)
    GPIO_STATE state; // GPIO state (e.g., GPIO_STATE_HIGH)

    // Calculate GPIO base address based on port
    constexpr uint32_t Set_GPIO_Base(GPIO_PORT port) {
        return GPIOA_BASE + (static_cast<uint32_t>(port) * GPIO_OFFSET);
    }

    GPIO_Registers_t* gpioRegisters; 

public:
    // Constructor
    GPIO(GPIO_PORT port, GPIO_PIN pin, GPIO_MODE mode);

    // Set GPIO port
    void set_port(GPIO_PORT port);

    // Set GPIO pin
    void set_pin(GPIO_PIN pin);

    // Set GPIO mode
    void set_mode(GPIO_MODE mode);

    // Set GPIO pin state
    void set_pin_state(GPIO_STATE state);

    // Destructor
    ~GPIO();
};

#endif // GPIO_HPP