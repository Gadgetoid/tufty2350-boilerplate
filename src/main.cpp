#include "powman.h"
#include "picovector.hpp"
#include "primitive.hpp"
#include "color.hpp"
#include "brush.hpp"
#include "st7789.hpp"
#include "psram.h"

using namespace pimoroni;
using namespace picovector;


ST7789 display;

image_t* screen;

const uint led_gpios[4] = {BW_LED_1, BW_LED_2, BW_LED_3, BW_LED_0};


int main() {
    psram_setup(BW_PSRAM_CS);

    display.set_backlight(255);
    display.set_mode(false);
    screen = new image_t((void *)display.get_framebuffer(), 160, 120);
    screen->antialias(X4);

    brush_t* black = new color_brush_t(rgb_color_t(0, 0, 0, 255));
    brush_t* darkred = new color_brush_t(rgb_color_t(128, 0, 0, 255));
    brush_t* green = new color_brush_t(rgb_color_t(0, 255, 0, 255));
    shape_t* shape = squircle(0, 0, 30, 3.0f);

    unsigned a = 0;
    while (true) {
        screen->brush(darkred);
        screen->clear();
        screen->brush(black);
        screen->rectangle(rect_t(10, 10, 50, 50));
        screen->brush(green);
        mat3_t transform = mat3_t();
        transform.translate(80, 60);
        transform.rotate(a);
        shape->transform = transform;
        screen->shape(shape);
        display.update();
        a += 1;
    }
}