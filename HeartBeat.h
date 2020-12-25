#ifndef HeartBeat_h
#define HeartBeat_h

#include "Arduino.h"

class HeartBeat
{
  public:
    HeartBeat(SSD1306 *display, uint x, uint y, uint interval);
    void update();
  private:
    SSD1306 *_display;
    uint _x;
    uint _y;
    uint _interval;
    uint _lastUpdate;
    uint _counter;
};

#endif
