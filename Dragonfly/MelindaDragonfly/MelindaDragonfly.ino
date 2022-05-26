
const int topWingPin = 2;
const int bottomWingPin = 0;

// Brightness will go from 0 to 255
int topWingBrightness = 0;   // current brightness of top wing
int topWingInterval = 1;     // How much to change the brightness
int bottomWingBrightness = 0;   // current brightness of bottom wing
int bottomWingInterval = 3;     // How much to change the brightness

void setup() {
  pinMode(topWingPin, OUTPUT);
  pinMode(bottomWingPin, OUTPUT);
  // For Debugging
  Serial.begin(9600);
}

void loop() {
  // Tell each wing to be the current brightness
  analogWrite(topWingPin, topWingBrightness);
  analogWrite(bottomWingPin, bottomWingBrightness);

  // change the brightness for next time through the loop:
  topWingBrightness = topWingBrightness + topWingInterval;
  bottomWingBrightness = bottomWingBrightness + bottomWingInterval;

  // reverse the direction of the fading at the ends of the fade:
  if (topWingBrightness <= 0) {
    topWingBrightness = 0;
    topWingInterval = -topWingInterval;
  }

  if (bottomWingBrightness <= 0) {
    bottomWingBrightness = 0;
    bottomWingInterval = -bottomWingInterval;
  }

  // reverse the direction of the fading at the ends of the fade:
  if (topWingBrightness >= 255) {
    topWingBrightness = 255;
    topWingInterval = -topWingInterval;
  }

  if (bottomWingBrightness >= 255) {
    bottomWingBrightness = 255;
    bottomWingInterval = -bottomWingInterval;
  }

  Serial.print(topWingBrightness);
  Serial.print(" ");
  Serial.println(bottomWingBrightness);

  // wait for 30 milliseconds to see the dimming effect
  delay(50);
}
