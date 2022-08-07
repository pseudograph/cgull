
#include "Button.h"

void Button::setPosition(double x, double y) {
    mPosition.x = static_cast<int>(x * Config::SCREEN_WIDTH);
    mPosition.y = static_cast<int>(y * Config::SCREEN_HEIGHT);
}
