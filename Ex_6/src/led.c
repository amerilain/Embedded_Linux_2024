#include "pico/stdlib.h"
#include "../inc/led.h"

int main() {
    const uint LED_PIN = PIN_NUM; // Enter the pin for the onboard LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        sleep_ms(500);
    }
}
