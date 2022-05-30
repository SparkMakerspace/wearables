// Example code which shows how to change the color of the DotStar pixel on the 
// Adafruit Gemma M0. This will cycle the pixel through Red->Green->Blue every 1/2 second.
// https://adafruit.github.io/Adafruit_DotStar/html/class_adafruit___dot_star.html
// You will need to install the Adafruit_DotStar library, use Tools -> Manage Libraries

#include <Adafruit_DotStar.h>

const int numberOfPixelsInStrip = 1;
const int dataPin = 3;
const int clockPin = 4;
const int delayTime = 500; // (half a second)
const int brightness = 10; // 0 = off, 255 = max

Adafruit_DotStar strip = Adafruit_DotStar(numberOfPixelsInStrip, dataPin, clockPin, DOTSTAR_BGR);

void setup() {

  // Initialize DotStar LED - it is a 'strip' of one
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
  strip.setBrightness(brightness);

  // For Debugging
  Serial.begin(9600);
}

void loop() {

  strip.setPixelColor(0, 0xFF0000); // red
  strip.show();
  delay(delayTime);

  strip.setPixelColor(0, 0x00FF00); // green
  strip.show();
  delay(delayTime);

  strip.setPixelColor(0, 0x0000FF); // blue
  strip.show();
  delay(delayTime);
}
