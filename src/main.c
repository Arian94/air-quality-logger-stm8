// #include <Arduino.h>
#include <DrawNumbers.h>

#define BUZZER PD1

void (*func_ptr[10])(uint8_t, uint8_t);

void setup() {
    init_listOfDrawings(func_ptr);
    pinMode(BUZZER, OUTPUT);
    display_begin(SSD1306_SWITCHCAPVCC, 0x3C, 0);
}

void loop() {
    int sensorValue = analogRead(PIN_A0);
    
    display_clearDisplay();
    draw_number(func_ptr, sensorValue);
    display_display();

    if (sensorValue < 400)
        pinMode(BUZZER, HIGH);
    else
        pinMode(BUZZER, LOW);

    delay(1000);
}
