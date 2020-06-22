#include "EasyOTA.h"
#include <ArduinoOTA.h>
#include <ArduinoLog.h>

const char * const TAG = "EasyOTA";

void initOTA()
{

  ArduinoOTA.onStart([]() {
    Log.notice("%s: onStart" CR, TAG);
  });

  ArduinoOTA.onEnd([]() {
    Log.notice("%s: onEnd invoked." CR, TAG);
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Log.notice("%s: Progress: %d" CR, TAG, progress / (total / 100) );
  });

  ArduinoOTA.onError([](ota_error_t error) {
    Log.error("%s: onError: %u" CR, TAG, error);
    if (error == OTA_AUTH_ERROR) {
      Log.error("%s: onError OTA_AUTH_ERROR" CR, TAG);
    } else if (error == OTA_BEGIN_ERROR){
      Log.error("%s: onError OTA_BEGIN_ERROR" CR, TAG);
    } else if (error == OTA_CONNECT_ERROR){
      Log.error("%s: onError OTA_CONNECT_ERROR" CR, TAG);
    } else if (error == OTA_RECEIVE_ERROR) {
      Log.error("%s: onError OTA_RECEIVE_ERROR" CR, TAG);
    } else if (error == OTA_AUTH_ERROR) {
      Log.error("%s: onError OTA_AUTH_ERROR" CR, TAG);
    }
  });

  ArduinoOTA.begin();
  Log.notice("%s: OTA started." CR, TAG);
}
