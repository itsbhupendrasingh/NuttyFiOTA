#include <NuttyFiOTA.h>

void setup() {
  NuttyFi_OTA(); // Initialize OTA

  pinMode(D4, OUTPUT); // Initialize the LED_BUILTIN pin as an output
}

void loop() {
  NuttyFi_OTA_Handle(); // Handle OTA updates

  digitalWrite(D4, HIGH); // Turn the LED on (HIGH is the voltage level)
  delay(500);             // Wait for half a second
  digitalWrite(D4, LOW);  // Turn the LED off by making the voltage LOW
  delay(500);             // Wait for half a second
}
