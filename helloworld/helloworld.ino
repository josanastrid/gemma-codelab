#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN 1
#define NUM_OF_PIXELS 4

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_OF_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

int brightness = 0;
int fadeAmount = 5;

void setup() {
  pixels.begin();
  pixels.show();
}

uint32_t orange = pixels.Color(254,80,0);
uint32_t red = pixels.Color(255,0,0);
uint32_t oddColor = orange;
uint32_t evenColor = red;
int changeColor = 0;

void loop() {

  if (brightness == 0) {
    if( changeColor%2 ){
      oddColor = orange;
      evenColor = red;
    }else{
      oddColor = red;
      evenColor = orange;
    }
    changeColor++;
  }

  for(int i=0; i< NUM_OF_PIXELS; i++){
    if( i%2 ){
      pixels.setPixelColor(i, oddColor);
    }else{
      pixels.setPixelColor(i, evenColor);
    }
  }
  
  pixels.setBrightness(brightness);
  pixels.show();

  brightness = brightness + fadeAmount;

  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount;   
  }

  delay(30);

}
