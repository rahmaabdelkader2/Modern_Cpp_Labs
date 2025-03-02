#include "LED.hpp"

Led::Led(unsigned int port, unsigned int pinNumber)
    : gpio(port, pinNumber, Gpio::OUTPUT) {}

void Led::led_on() {
    gpio.setHigh(); // Turn LED on
}

void Led::led_off() {
    gpio.setLow(); // Turn LED off
}

void Led::led_toggle() {
    gpio.toggle(); // Toggle LED state
}