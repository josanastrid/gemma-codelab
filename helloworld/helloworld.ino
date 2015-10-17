#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 1
#define NUM_OF_PIXELS 1

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_OF_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

int brightness = 0;
int fadeAmount = 5;

void setup() {
  pixels.begin();
  pixels.show();
}

void loop() {

  pixels.setPixelColor(0, pixels.Color(254,80,0));
  pixels.setBrightness(brightness);
  pixels.show();

  brightness = brightness + fadeAmount;

  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount;
  }

  delay(30);

}
