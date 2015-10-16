#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 1
#define NUM_OF_PIXELS 1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_OF_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
    pixels.setPixelColor(0, pixels.Color(255,255,255));
    pixels.show();
}
