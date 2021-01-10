# ESPTOTP

An ESP8266-based TOTP desktop display based on the Wemos D1 ESP-Wroom-02 Motherboard (ESP8266 Mini-WiFi NodeMCU Module ESP8266+18650 Battery+0.96 OLED development board).

![Alt Wemos display board](/images/wemos_d1_display_board.webp?raw=true "Wemos display board")

## Firmware

The device firmware is written using Arduino for ESP8266 - https://github.com/esp8266/Arduino. See this page for details on getting a dev. env. up and running.

### Dependencies

* cpp-base32 - https://github.com/jjssoftware/cpp-base32.git
* ArduinoJson - https://github.com/bblanchon/ArduinoJson
* ESP8266TrueRandom - https://github.com/jjssoftware/ESP8266TrueRandom
* Cryptosuite - https://github.com/jjssoftware/Cryptosuite
* ESP8266TOTP - https://github.com/jjssoftware/ESP8266TOTP.git
* ESP8266Ping - https://github.com/dancol90/ESP8266Ping.git
* WiFiManager
* LittleFS_esp32
* ...

## Enclosure

The display enclosure can be CNC milled using the included Gcode

![Alt text](/images/wemos_front.png?raw=true "Display enclosure front")
![Alt text](/images/wemos_back.png?raw=true "Display enclosure back")

## Manually uploading firmware

You can upload a firmware image without setting up a full Arduino dev. env. by using esptool (https://github.com/espressif/esptool - Install esptool with `pip install esptool`) and the folling command:

```
sudo esptool.py --chip esp8266 --port /dev/cu.usbserial-0001 --baud 921600 write_flash 0x0 ./firmware/ESPTOTP.ino.bin
```

The current / default firmware can be found in the `/firmware` folder of this repository.
