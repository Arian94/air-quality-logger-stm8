#include <stdint.h>
#include <Mini_SSD1306.h>

#define OLED_RESET -1
Mini_SSD1306(display, OLED_RESET);
void display_drawLine(uint8_t x, uint8_t y, uint8_t length, uint8_t direction);
void draw_zero(uint8_t x, uint8_t y);
void draw_one(uint8_t x, uint8_t y);
void draw_two(uint8_t x, uint8_t y);
void draw_three(uint8_t x, uint8_t y);
void draw_four(uint8_t x, uint8_t y);
void draw_five(uint8_t x, uint8_t y);
void draw_six(uint8_t x, uint8_t y);
void draw_seven(uint8_t x, uint8_t y);
void draw_eight(uint8_t x, uint8_t y);
void draw_nine(uint8_t x, uint8_t y);
void draw_number(void (*drawings[10])(uint8_t, uint8_t), int16_t num);
void init_listOfDrawings(void (*func_ptr[10])(uint8_t, uint8_t));