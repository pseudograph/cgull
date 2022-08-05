
#include "Button.h"

void Button::setX(double x, double y) {
    mX = static_cast<int>(x * Config::SCREEN_WIDTH);
    mY = static_cast<int>(y * Config::SCREEN_HEIGHT);
}

void Button::setX(int x, int y) {
    scaledX = x;
    scaledY = y;
}

void Button::updateStatus(SDL_Event *e) {
    if (e.type.mou)
}
