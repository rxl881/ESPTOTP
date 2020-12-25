#include "Arduino.h"
#include <SSD1306.h>

const uint maxBarHeight = 60;
const uint barWidth = 15;
const uint quantile = 2;

TimerDisplay::TimerDisplay(SSD1306 *display, uint displayWidth, uint displayHeight) :
    _display(display),
    _displayWidth(displayWidth),
    _displayHeight(displayHeight)
{
}

void TimerDisplay::update(unsigned long codeStart, unsigned long now) {
    long timeDiff = now - codeStart;
    int barHeight = 0;
    if (timeDiff > 30) {
        timeDiff = 30;
    } else if (timeDiff < 0) {
        timeDiff = 0;
    }
    barHeight = 30 - timeDiff;

    _display->setColor(BLACK);
    _display->fillRect(
        _displayWidth - barWidth,
        _displayHeight - maxBarHeight,
        barWidth,
        maxBarHeight
    );
    _display->setColor(WHITE);
    if (barHeight > 0) {
        barHeight = barHeight * quantile;
        _display->fillRect(
            _displayWidth - barWidth,
            _displayHeight - barHeight,
            barWidth,
            barHeight
        );
    }
    _display->drawRect(
        _displayWidth - barWidth,
        _displayHeight - maxBarHeight,
        barWidth,
        maxBarHeight
    );

    return;
}
