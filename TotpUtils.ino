#include "Arduino.h"
#include "TotpUtils.h"
#include "ESP8266TOTP.h"

Base32 base32;
unsigned char base32Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
unsigned char keyBytes[16];

TotpUtils::TotpUtils(char* secret){
  data.enabled = true;
  int secretLength = strlen(secret);
  unsigned char* inout32 = (unsigned char*)malloc(sizeof(char)*secretLength);
  strcpy((char*)inout32, secret);
  base32.Unmap32(inout32, secretLength, base32Alphabet);
  base32.Decode32(inout32, secretLength, keyBytes);
}

int TotpUtils::getCode(unsigned long timestamp){
  Serial.println("ts: " + String(timestamp));
  return ESP8266TOTP::GetTOTPToken(timestamp, keyBytes);
}
