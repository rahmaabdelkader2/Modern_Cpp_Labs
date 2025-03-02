#include "GPIO.hpp"
#include "LED.hpp"
#include <stdint.h> // Add this line


#define LED_PORT GPIOA_BASE // Use GPIOA base address
#define LED_PIN  5          // Change to the actual pin number connected to the LED

// Busy-wait delay function
void delay_ms(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 1000; i++) {
        __asm__ volatile("nop"); // No operation (prevents compiler optimization)
    }
}

int main() {
    // Initialize the LED
    Led led(LED_PORT, LED_PIN);

    while (1) {
        led.led_toggle();  // Toggle LED state
        delay_ms(500);     // Wait 500ms
    }

    return 0;
}