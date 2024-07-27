#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include "NuttyFiOTA.h"

const char* ssid = "Nuttyfi";
const char* password = "Nuttyfi123";
const char* hostname = "NuttyFi";

void NuttyFi_OTA() {
  Serial.begin(115200);
  Serial.println("Bootloader started");

  // Set up WiFi as an Access Point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  // Set the hostname
  ArduinoOTA.setHostname(hostname);

  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  // Start OTA
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH)
      type = "sketch";
    else // U_SPIFFS
      type = "filesystem";

    Serial.println("Start updating " + type);
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    static unsigned int lastProgress = 0;
    unsigned int percentage = (progress / (total / 100));
    if (percentage - lastProgress >= 10) {
      Serial.printf(".................. %u%%\n", percentage);
      lastProgress = percentage;
    }
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });

  ArduinoOTA.begin();
  Serial.println("OTA Ready");
}

void NuttyFi_OTA_Handle() {
  ArduinoOTA.handle();
}
