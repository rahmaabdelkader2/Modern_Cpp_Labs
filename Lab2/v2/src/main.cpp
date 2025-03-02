#include "STDTYPES.hpp"
#include "GPIO.hpp"
#include "RCC.hpp"
#include "LED.hpp"

// int main() {
//     // Initialize GPIO for LED (assuming LED is on GPIO_PORT_A, PIN5)
//     GPIO led(GPIO_PORT_A, PIN5, GPIO_MODE_OUTPUT);

//     // Set the LED pin to high
//     led.set_pin_state(GPIO_STATE_HIGH);

//     // Simple delay loop (not accurate, just for demonstration)
//     for (volatile int i = 0; i < 1000000; i++);

//     // Set the LED pin to low
//     led.set_pin_state(GPIO_STATE_LOW);

//     while (1) {
//         // Toggle LED state
//         led.set_pin_state(GPIO_STATE_HIGH);
//         for (volatile int i = 0; i < 1000000; i++);
//         led.set_pin_state(GPIO_STATE_LOW);
//         for (volatile int i = 0; i < 1000000; i++);
//     }

//     return 0;
// }



int main() {
    
    Led led(GPIO_PORT_A, PIN5);

    // Turn the LED on
    led.led_off();


    // Toggle the LED in a loop
    while (1) {
        led.led_on();
        for (volatile int i = 0; i < 1000000; i++);
        led.led_off();
        for (volatile int i = 0; i < 1000000; i++);
       
    }

    return 0;
}