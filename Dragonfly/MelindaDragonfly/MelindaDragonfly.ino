
const int topWing = 2;
const int bottomWing = A0;
const int bottomWingDigital = 0;

// Brightness will go from 0 to 255
int brightness = 0;   // current brightness of bottom wing
int interval = 1;     // How much to change the brightness

void setup() {
  // The top wing is always on
  pinMode(topWing, OUTPUT);
  digitalWrite(topWing, HIGH);

  pinMode(bottomWingDigital, OUTPUT);
  // For Debugging
  Serial.begin(9600);
}

void loop() {

  fadeAnalog(bottomWing);
  fadeDigital(bottomWingDigital);

  // change the brightness for next time through the loop:
  brightness = brightness + interval;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0) {
    interval = -interval;
  }

  // reverse the direction of the fading at the ends of the fade:
  if (brightness >= 255) {
    brightness = 255;
    interval = -interval;
  }

  Serial.println(brightness);

  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

void fadeAnalog(int pin) {

  // Analog output goes from 0 to 1023
  // at 600 the red LED is always on
  int analogBrightness = map(brightness, 0, 255, 600, 1023);

  // set the analog brightness
  analogWrite(pin, analogBrightness);
}

void fadeDigital(int pin) {
  // set the digital brightness
  analogWrite(pin, brightness);
}
