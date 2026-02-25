#include "powman.h"
#include "picovector.hpp"
#include "primitive.hpp"
#include "color.hpp"
#include "brush.hpp"
#include "st7789.hpp"

using namespace pimoroni;
using namespace picovector;


ST7789 display;

image_t* screen;

const uint led_gpios[4] = {BW_LED_1, BW_LED_2, BW_LED_3, BW_LED_0};


int main() {
    display.set_backlight(255);
    display.set_mode(false);
    screen = new image_t((void *)display.get_framebuffer(), 160, 120);
    screen->antialias(X4);

    uint16_t v = 0;
    while (true) {
        brush_t* brush = new color_brush_t(rgb_color_t(128, 0, 0, 255));
        screen->brush(brush);
        screen->clear();
        brush = new color_brush_t(rgb_color_t(0, 0, 0, 255));
        screen->brush(brush);
        screen->rectangle(rect_t(10, 10, 50, 50));
        brush = new color_brush_t(rgb_color_t(0, 255, 0, 255));
        screen->brush(brush);
        shape_t* shape = squircle(80, 60, 30, 3.0f);
        screen->shape(shape);
        display.update();
    }
}