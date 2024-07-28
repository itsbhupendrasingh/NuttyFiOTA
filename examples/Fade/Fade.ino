#include <NuttyFiOTA.h>

const int ledPin = 2;  // D4 pin
void setup() {
  NuttyFi_OTA();  // Initialize OTA
  pinMode(ledPin, OUTPUT);  // Set the ledPin as an output
}

void loop() {
  NuttyFi_OTA_Handle();  // Handle OTA updates

  // Fade the LED in
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, 255 - brightness);
    delay(5);  // Delay to see the fading effect
  }

  // Fade the LED out
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, 255 - brightness);
    delay(5);  // Delay to see the fading effect
  }

  delay(1000);  // Wait for 1 second before repeating the fade
}
