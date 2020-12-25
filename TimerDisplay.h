#ifndef TimerDisplay_h
#define TimerDisplay_h

#include "Arduino.h"
#include <SSD1306.h>

class TimerDisplay
{
  public:
    TimerDisplay(SSD1306 *display, uint displayWidth, uint displayHeight);
    void update(unsigned long codeStart, unsigned long now);
  private:
    SSD1306 *_display;
    uint _displayWidth;
    uint _displayHeight;
};

#endif
