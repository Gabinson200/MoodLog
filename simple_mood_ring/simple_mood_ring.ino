// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 2 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 12 // Popular NeoPixel ring size

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


//labels = np.array(["Sadness", "Joy", "Love", "Anger", "Fear", "Suprise"])
//colors = ["blue", "yellow", "pink", "red", "black", "orange"]
int ratios[] = {0, 9, 0, 0, 1, 0};

void setup() {
  strip.begin();
  strip.setBrightness(50);
  strip.show(); // Initialize all pixels to 'off' 
}

void loop() {
  strip.clear();
  colorWipe(strip.Color(0, 0, 125), 300*ratios[0]); // Blue
  delay(25);
  strip.clear();
  colorWipe(strip.Color(127, 127, 0), 300*ratios[1]); // Yellow
  delay(25);
  strip.clear();
  colorWipe(strip.Color(127, 0, 64), 300*ratios[2]); // Pink
  delay(25);
  strip.clear();
  colorWipe(strip.Color(127, 0, 0), 300*ratios[3]); // Red
  delay(25);
  strip.clear();
  colorWipe(strip.Color(51, 25, 0), 300*ratios[4]); // Brown
  delay(25);
  strip.clear();
  colorWipe(strip.Color(127, 64, 0), 300*ratios[5]); // Brown
  delay(25);

}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
