#include <DrawNumbers.h>

#define HORIZ 0
#define VERT 1
#define NUMBER_WIDTH 10
#define NUMBER_HEIGHT 20

void init_listOfDrawings(void (*func_ptr[10])(uint8_t, uint8_t)) {
    func_ptr[0] = draw_zero;
    func_ptr[1] = draw_one;
    func_ptr[2] = draw_two;
    func_ptr[3] = draw_three;
    func_ptr[4] = draw_four;
    func_ptr[5] = draw_five;
    func_ptr[6] = draw_six;
    func_ptr[7] = draw_seven;
    func_ptr[8] = draw_eight;
    func_ptr[9] = draw_nine;
}

void display_drawLine(uint8_t x, uint8_t y, uint8_t length, uint8_t direction) {
    switch (direction) {
        case HORIZ:
            for (uint8_t i = x; i < x + length; i++) {
                display_drawPixel(i, y, 1);
            }
            break;
        case VERT:
            for (uint8_t i = y; i < y + length; i++) {
                display_drawPixel(x, i, 1);
            }
            break;
    }
}

void draw_zero(uint8_t x, uint8_t y) {
    uint8_t h = NUMBER_HEIGHT / 2;
    display_drawLine(x, y, NUMBER_WIDTH, 0);
    display_drawLine(x, y + NUMBER_HEIGHT, NUMBER_WIDTH, 0);
    display_drawLine(x, y, NUMBER_HEIGHT, 1);
    display_drawLine(x + NUMBER_WIDTH, y, NUMBER_HEIGHT, 1);
}

void draw_one(uint8_t x, uint8_t y) {
    display_drawLine(x + NUMBER_WIDTH, y, NUMBER_HEIGHT, 1);
}

void draw_two(uint8_t x, uint8_t y) {
    uint8_t h = NUMBER_HEIGHT / 2;
    display_drawLine(x, y, NUMBER_WIDTH, 0);
    display_drawLine(x + NUMBER_WIDTH, y, h, 1);
    display_drawLine(x, y + h, NUMBER_WIDTH, 0);
    display_drawLine(x, y + h, h, 1);
    display_drawLine(x, y + NUMBER_HEIGHT, NUMBER_WIDTH, 0);
}

void draw_three(uint8_t x, uint8_t y) {
    uint8_t h = NUMBER_HEIGHT / 2;
    display_drawLine(x, y, NUMBER_WIDTH, 0);
    display_drawLine(x, y + h, NUMBER_WIDTH, 0);
    display_drawLine(x, y + NUMBER_HEIGHT, NUMBER_WIDTH, 0);
    display_drawLine(x + NUMBER_WIDTH, y, NUMBER_HEIGHT, 1);
}

void draw_four(uint8_t x, uint8_t y) {
    uint8_t h = NUMBER_HEIGHT / 2;
    display_drawLine(x, y, h, 1);
    display_drawLine(x, y + h, NUMBER_WIDTH, 0);
    display_drawLine(x + NUMBER_WIDTH, y, NUMBER_HEIGHT, 1);
}

void draw_five(uint8_t x, uint8_t y) {
    uint8_t h = NUMBER_HEIGHT / 2;
    display_drawLine(x, y, NUMBER_WIDTH, 0);
    display_drawLine(x, y, h, 1);
    display_drawLine(x, y + h, NUMBER_WIDTH, 0);
    display_drawLine(x + NUMBER_WIDTH, y + h, h, 1);
    display_drawLine(x, y + NUMBER_HEIGHT, NUMBER_WIDTH, 0);
}

void draw_six(uint8_t x, uint8_t y) {
    uint8_t h = NUMBER_HEIGHT / 2;
    display_drawLine(x, y, NUMBER_WIDTH, 0);
    display_drawLine(x, y + h, NUMBER_WIDTH, 0);
    display_drawLine(x, y + NUMBER_HEIGHT, NUMBER_WIDTH, 0);
    display_drawLine(x + NUMBER_WIDTH, y + h, h, 1);
    display_drawLine(x, y, NUMBER_HEIGHT, 1);
}

void draw_seven(uint8_t x, uint8_t y) {
    uint8_t h = NUMBER_HEIGHT / 2;
    display_drawLine(x, y, NUMBER_WIDTH, 0);
    display_drawLine(x + NUMBER_WIDTH, y, NUMBER_HEIGHT, 1);
}

void draw_eight(uint8_t x, uint8_t y) {
    uint8_t h = NUMBER_HEIGHT / 2;
    display_drawLine(x, y, NUMBER_WIDTH, 0);
    display_drawLine(x, y + h, NUMBER_WIDTH, 0);
    display_drawLine(x, y + NUMBER_HEIGHT, NUMBER_WIDTH, 0);
    display_drawLine(x, y, NUMBER_HEIGHT, 1);
    display_drawLine(x + NUMBER_WIDTH, y, NUMBER_HEIGHT, 1);
}

void draw_nine(uint8_t x, uint8_t y) {
    uint8_t h = NUMBER_HEIGHT / 2;
    display_drawLine(x, y, NUMBER_WIDTH, 0);
    display_drawLine(x, y + h, NUMBER_WIDTH, 0);
    display_drawLine(x, y + NUMBER_HEIGHT, NUMBER_WIDTH, 0);
    display_drawLine(x, y, h, 1);
    display_drawLine(x + NUMBER_WIDTH, y, NUMBER_HEIGHT, 1);
}

void draw_number(void (*drawings[10])(uint8_t, uint8_t), int16_t num) {
    int arr[5];
    int i = 0;
    int j, r;

    while (num != 0) {
        r = num % 10;
        arr[i] = r;
        i++;
        num = num / 10;
    }

    uint8_t x = 30;
    uint8_t y = 22;

    for (j = i - 1; j > -1; j--) {
        drawings[arr[j]](x + 15 * (i - j), y);
    }
}