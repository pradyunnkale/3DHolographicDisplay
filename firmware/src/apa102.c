#include "apa102.h"

led_state create_led(uint8_t r, uint8_t z, uint8_t strip_index) {
    led_state led;
    led.r = r;
    led.theta0 = (360/LEDS_PER_STRIP)*z + 360/STRIPS_PER_LAYER * strip_index; 
    led.z = z;
    return led;
}
//Current angle = get_current_angle()
static inline uint8_t led_set(led_state* led, uint16_t current_angle) {
    led->status = led_map[led->r][(led->theta0 + current_angle) % 360][led->z];
    return APA_OK;
}


