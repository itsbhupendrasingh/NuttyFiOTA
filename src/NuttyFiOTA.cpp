#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>
#include "NuttyFiOTA.h"

const char* ssid = "Nuttyfi";
const char* password = "Nuttyfi123";
const char* hostname = "NuttyFi-OTA";  // Updated hostname to make it more descriptive

void printVersion() {
  Serial.println(F("\n\n"));
  Serial.println(F("****************************************************"));
  Serial.println(F("*                                                  *"));
  Serial.println(F("*              NuttyFi OTA V1.0.0                  *"));
  Serial.println(F("*                                                  *"));
  Serial.println(F("****************************************************"));
  Serial.println(F("\n\n"));
}

void NuttyFi_OTA() {
  Serial.begin(115200);
  printVersion();
  delay(1000); // Wait for 1 second to display the banner
  Serial.println("Bootloader started");

  // Set up WiFi as an Access Point
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  // Set the hostname
  ArduinoOTA.setHostname(hostname);

  // Start mDNS service with additional service text
  if (MDNS.begin(hostname)) {
    Serial.println("mDNS responder started");
    // Advertise a custom service with descriptive text
    MDNS.addService("arduino", "tcp", 8266);
    MDNS.addServiceTxt("arduino", "tcp", "description", "NuttyFi OTA (Over the Air) Wireless Firmware");
    MDNS.addServiceTxt("arduino", "tcp", "board", "NodeMCU ESP8266");
    MDNS.addServiceTxt("arduino", "tcp", "firmware", "v1.0.0");
  }

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
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
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
