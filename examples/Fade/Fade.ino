#include <NuttyFiOTA.h>

void setup() {
  NuttyFi_OTA();  // Initialize OTA

  pinMode(D4, OUTPUT);  // Initialize the LED_BUILTIN pin as an output
}

void loop() {
  NuttyFi_OTA_Handle();  // Handle OTA updates
  for (int brightness = 0; brightness <= 1023; brightness++) {
    analogWrite(D4, 1023 - brightness);
    delay(5);  // Delay to see the fading effect
  }

  // Fade the LED out (since it is active-low, invert the brightness)
  for (int brightness = 1023; brightness >= 0; brightness--) {
    analogWrite(D4, 1023 - brightness);
    delay(5);  // Delay to see the fading effect
  }
}
