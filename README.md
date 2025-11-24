# NuttyFiOTA

[![GitHub release](https://img.shields.io/github/v/release/itsbhupendrasingh/NuttyFiOTA)](https://github.com/itsbhupendrasingh/NuttyFiOTA/releases/latest)
[![Release date](https://img.shields.io/github/release-date/itsbhupendrasingh/NuttyFiOTA)](https://github.com/itsbhupendrasingh/NuttyFiOTA/releases/latest)
[![Downloads](https://img.shields.io/github/downloads/itsbhupendrasingh/NuttyFiOTA/latest/total)](https://github.com/itsbhupendrasingh/NuttyFiOTA/releases/latest)

NuttyFiOTA is a library that provides Over-The-Air (OTA) update functionality for the NuttyFi board based on the ESP8266. This library allows you to easily add OTA update capability to your projects, making it possible to update firmware wirelessly without needing physical access to the device.

## Features

- Simple integration for OTA updates
- Easy-to-use API
- Example sketches included

## Installation

### Via Arduino Library Manager
Coming soon.

### Manual Installation

1. Download the ZIP file:
   - Go to https://github.com/itsbhupendrasingh/NuttyFiOTA
   - Click the "Code" button and select "Download ZIP"

2. Add the library to Arduino IDE:
   - Open the Arduino IDE
   - Go to `Sketch` > `Include Library` > `Add .ZIP Library...`
   - Select the downloaded ZIP file

## Usage

Include the library in your sketch and initialize the OTA functionality:

```cpp
#include <NuttyFiOTA.h>

void setup() {
  NuttyFi_OTA(); // Initialize OTA
}

void loop() {
  NuttyFi_OTA_Handle(); // Handle OTA updates
}
```

## OTA Password

When uploading code through OTA, you may be prompted for a password. The default password is set in the NuttyFiOTA library. Ensure you use the correct password when prompted.

**Default OTA Password**: `Nuttyfi123`

To change the password, modify the 'NuttyFiOTA.cpp' file:
```ArduinoOTA.setPassword("YourNewPassword"); ```

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Examples 

## Blink

```cpp
#include <NuttyFiOTA.h>

void setup() {
  NuttyFi_OTA(); // Initialize OTA

  pinMode(D4, OUTPUT); // Initialize the LED_BUILTIN pin as an output
}

void loop() {
  NuttyFi_OTA_Handle(); // Handle OTA updates

  digitalWrite(D4, HIGH); // Turn the LED off by making the voltage LOW 
  delay(500);             // Wait for half a second
  digitalWrite(D4, LOW);  // Turn the LED on (HIGH is the voltage level)
  delay(500);             // Wait for half a second
}

```

## Fade

```cpp
#include <NuttyFiOTA.h>

const int ledPin = 2;  // D4 pin
void setup() {
  NuttyFi_OTA();  // Initialize OTA
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

```
