#include "Arduino.h"
#include <SSD1306.h>

const char beatChars[4] = {'\\', '|', '/', '-'};

HeartBeat::HeartBeat(SSD1306 *display, uint x, uint y, uint interval) :
    _display(display),
    _x(x),
    _y(y),
    _interval(interval),
    _lastUpdate(0),
    _counter(0)
{
}

void HeartBeat::update() {
    const long now = millis();
    if (now > _lastUpdate + _interval) {
        _counter++;
        _lastUpdate = now;
    }
    String heartbeat = String("[ " + String(beatChars[_counter % 4]) + " ]");
    _display->setColor(BLACK);
    _display->fillRect(
        _x,
        _y - 10,
        40,
        30
    );
    _display->setColor(WHITE);
    _display->setFont(ArialMT_Plain_10);
    _display->drawString(_x, _y, heartbeat);
}