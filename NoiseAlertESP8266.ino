/*********
  Rui Santos
  Complete project details at http://randomnerdtutorials.com
  Arduino IDE example: Examples > Arduino OTA > BasicOTA.ino
*********/

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#include "config.h"                   // Update with your network credentials 
#include "ESP8266_Utils.hpp"          // WiFi connection
#include "ESP8266_Utils_OTA.hpp"      // OTA connection

const int ESP_BUILTIN_LED = 2;

void setup() {
  Serial.begin(115200);

  ConnectWiFi_STA();
  
  InitOTA();
  
  pinMode(ESP_BUILTIN_LED, OUTPUT);
}

void loop() {
  ArduinoOTA.handle();
  
  digitalWrite(ESP_BUILTIN_LED, LOW);
  delay(2000);
  digitalWrite(ESP_BUILTIN_LED, HIGH);
  delay(2000);
}
