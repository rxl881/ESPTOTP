#ifndef TotpUtils_h
#define TotpUtils_h

#include "Arduino.h"
#include "ESP8266TOTP.h"

class TotpUtils
{
  public:
    TotpUtils(char* secret);
    int getCode(unsigned long timestamp);
  private:
    totpData data;
    unsigned char* data32;

};

#endif
