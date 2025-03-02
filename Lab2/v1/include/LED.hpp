#ifndef LED_HPP
#define LED_HPP

#include "GPIO.hpp"

class Led {
private:
    Gpio gpio;
    unsigned int pin;

public:
    Led(unsigned int port, unsigned int pin);
    void led_on();
    void led_off();
    void led_toggle();
};

#endif // LED_HPP