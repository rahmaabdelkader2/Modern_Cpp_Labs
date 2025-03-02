#ifndef LED_HPP
#define LED_HPP

#include "GPIO.hpp"

class Led {
private:
    GPIO gpio;      
    GPIO_PIN pin;    

public:
    // Constructor
    Led(GPIO_PORT port, GPIO_PIN pin);
    void led_on();
    void led_off();

 
};

#endif // LED_HPP