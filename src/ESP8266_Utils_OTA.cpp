#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include "ESP8266_Utils_OTA.h"
#include <ArduinoOTA.h>
#include <ArduinoLog.h>

const char * const TAG = "EasyOTA";

void initOTA()
{

  ArduinoOTA.onStart([]() {
    Log.notice("%s: onStart", TAG);
  });

  ArduinoOTA.onEnd([]() {
    Log.notice("%s: onEnd invoked.", TAG);
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Log.notice("%s: Progress: %d", TAG, progress / (total / 100) );
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Log.error("%s: onError: %u", TAG, error);
    if (error == OTA_AUTH_ERROR) {
      Log.error("%s: onError OTA_AUTH_ERROR", TAG);
    } else if (error == OTA_BEGIN_ERROR){
      Log.error("%s: onError OTA_BEGIN_ERROR", TAG);
    } else if (error == OTA_CONNECT_ERROR){
      Log.error("%s: onError OTA_CONNECT_ERROR", TAG);
    } else if (error == OTA_RECEIVE_ERROR) {
      Log.error("%s: onError OTA_RECEIVE_ERROR", TAG);
    } else if (error == OTA_AUTH_ERROR) {
      Log.error("%s: onError OTA_AUTH_ERROR", TAG);
    }
  });

  ArduinoOTA.begin();
  Log.notice("%s: OTA started.", TAG);
}
