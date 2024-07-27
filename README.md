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

## OTA Password

When uploading code through OTA, you may be prompted for a password. The default password is set in the NuttyFiOTA library. Ensure you use the correct password when prompted.

**Default OTA Password**: `Nuttyfi123`

If you want to change the default OTA password, modify the NuttyFiOTA.cpp file accordingly.
License

This project is licensed under the MIT License - see the LICENSE file for details.

## Test Code 

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



