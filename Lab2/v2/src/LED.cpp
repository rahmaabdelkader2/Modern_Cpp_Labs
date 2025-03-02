#include "LED.hpp"

// Constructor
Led::Led(GPIO_PORT port, GPIO_PIN pin)
    : gpio(port, pin, GPIO_MODE_OUTPUT), pin(pin) {
  
    led_off();
}


void Led::led_on() {
    gpio.set_pin_state(GPIO_STATE_HIGH);
}

void Led::led_off() {
    gpio.set_pin_state(GPIO_STATE_LOW);
}

