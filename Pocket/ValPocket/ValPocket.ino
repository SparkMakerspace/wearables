
const int firstHalfPin = 2;
const int secondHalfPin = A0;

// Brightness will go from 0 to 255
int firstHalfBrightness = 0;   // current brightness of 
int firstHalfInterval = 1;     // How much to change the brightness
int secondHalfBrightness = 0;   // current brightness of 
int secondHalfInterval = 1;     // How much to change the brightness

void setup() {
  pinMode(firstHalfPin, OUTPUT);
  // For Debugging
  Serial.begin(9600);
}

void loop() {
  // Tell each wing to be the current brightness
  analogWrite(firstHalfPin, firstHalfBrightness);
  int analogBrightness = map(secondHalfBrightness, 0, 255, 600, 1023);

  analogWrite(secondHalfPin, analogBrightness);

  // change the brightness for next time through the loop:
  firstHalfBrightness = firstHalfBrightness + firstHalfInterval;
  secondHalfBrightness = secondHalfBrightness + secondHalfInterval;

  // reverse the direction of the fading at the ends of the fade:
  if (firstHalfBrightness <= 0) {
    firstHalfBrightness = 0;
    firstHalfInterval = -firstHalfInterval;
  }

  if (secondHalfBrightness <= 0) {
    secondHalfBrightness = 0;
    secondHalfInterval = -secondHalfInterval;
  }

  // reverse the direction of the fading at the ends of the fade:
  if (firstHalfBrightness >= 255) {
    firstHalfBrightness = 255;
    firstHalfInterval = -firstHalfInterval;
  }

  if (secondHalfBrightness >= 255) {
    secondHalfBrightness = 255;
    secondHalfInterval = -secondHalfInterval;
  }

  Serial.print(firstHalfBrightness);
  Serial.print(" ");
  Serial.println(secondHalfBrightness);

  // wait for 30 milliseconds to see the dimming effect
  delay(5);
}
