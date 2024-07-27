# NuttyFiOTA

NuttyFiOTA is a library that provides Over-The-Air (OTA) update functionality for the Nuttyfi board based on the ESP8266. This library allows you to easily add OTA update capability to your projects, making it possible to update firmware wirelessly without needing physical access to the device.

## Features

- Simple integration for OTA updates
- Easy-to-use API
- Example sketches included

## Installation

To install this library, use the Arduino Library Manager:

1. Open the Arduino IDE.
2. Go to `Sketch` > `Include Library` > `Manage Libraries...`.
3. Search for `NuttyFiOTA`.
4. Click `Install`.

Alternatively, you can download this repository as a ZIP file and install it manually:

1. Download the ZIP file.
2. In the Arduino IDE, go to `Sketch` > `Include Library` > `Add .ZIP Library...`.
3. Select the downloaded ZIP file.

## Usage

Include the library in your sketch and initialize the OTA functionality:

```cpp
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

