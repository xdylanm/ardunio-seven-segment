#include <Adafruit_NeoPixel.h>

uint8_t const PIN_DATA = 0; // pin 1 is LED
uint8_t const PIN_LED = 1;//LED on Model B=PIN0, LED on Model A=PIN1

uint16_t const N_PIXELS = 14;

Adafruit_NeoPixel pixels (N_PIXELS,PIN_DATA,NEO_GRBW+NEO_KHZ800);

uint16_t last_pixel = N_PIXELS-1;
uint16_t cur_pixel = 0;

// digits                     Pgfedcba, P=decimal (not used)
uint8_t const SS_DIGITS[] = {B00111111, // zero
                             B00000110, // one
                             B01011011, // two
                             B01001111, // three
                             B01100110, // four
                             B01101101, // five
                             B01111101, // six
                             B00000111, // seven
                             B01111111, // eight
                             B01100111};// nine

uint8_t const SS_COLOR_RGBW[] = { 32, 0, 32, 0 };

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_LED, OUTPUT); 
  pixels.begin();
}



void drawDigit(int digit) 
{
  uint8_t pattern = SS_DIGITS[digit];
  for (int j = 0; j < 7; ++j) {
    if (0x01 & (pattern >> j)) {
      pixels.setPixelColor(2*j,
        SS_COLOR_RGBW[0],
        SS_COLOR_RGBW[1],
        SS_COLOR_RGBW[2],
        SS_COLOR_RGBW[3]);
      pixels.setPixelColor(2*j+1,
        SS_COLOR_RGBW[0],
        SS_COLOR_RGBW[1],
        SS_COLOR_RGBW[2],
        SS_COLOR_RGBW[3]);
    } else {
      pixels.setPixelColor(2*j,0,0,0,0);
      pixels.setPixelColor(2*j+1,0,0,0,0);
    }
  }
  pixels.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int digit = 9; digit >= 0; --digit) {
    drawDigit(digit);

    digitalWrite(PIN_LED, digit % 2);   // turn the LED on (HIGH is the voltage level)
    delay(1000);
  }
 
}
