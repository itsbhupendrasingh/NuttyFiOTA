# NuttyFiOTA

NuttyFiOTA is a library that provides Over-The-Air (OTA) update functionality for the Nuttyfi board based on the ESP8266. This library allows you to easily add OTA update capability to your projects, making it possible to update firmware wirelessly without needing physical access to the device.

## Features

- Simple integration for OTA updates
- Easy-to-use API
- Example sketches included

## Installation

### Via Arduino Library Manager

**Coming soon!** Stay tuned for updates.

### Manual Installation

1. **Download the ZIP File**:
   - Go to [NuttyFiOTA](https://github.com/itsbhupendrasingh/NuttyFiOTA).
   - Click on the `Code` button and select `Download ZIP`.

2. **Add the Library to Arduino IDE**:
   - Open the Arduino IDE.
   - Go to `Sketch` > `Include Library` > `Add .ZIP Library...`.
   - Navigate to the location where you downloaded the ZIP file and select it.
   - The library will be added to the Arduino IDE.

## Usage

Include the library in your sketch and initialize the OTA functionality:

```cpp
#include <NuttyFiOTA.h>

const char* password = "Nuttyfi123";

void setup() {
  NuttyFi_OTA(password); // Initialize OTA with password

  pinMode(D4, OUTPUT); // Initialize the LED_BUILTIN pin as an output
}

void loop() {
  NuttyFi_OTA_Handle(); // Handle OTA updates

  digitalWrite(D4, HIGH); // Turn the LED on (HIGH is the voltage level)
  delay(500);             // Wait for half a second
  digitalWrite(D4, LOW);  // Turn the LED off by making the voltage LOW
  delay(500);             // Wait for half a second
}
