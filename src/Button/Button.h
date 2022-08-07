
#ifndef CGULL_BUTTON_H
#define CGULL_BUTTON_H

#include "Config.h"
#include "Texture/Texture.h"

class Button : public Texture {
    enum class BUTTONSPRITE {
        BUTTON_SPRITE_MOUSE_OUT,
        BUTTON_SPRITE_MOUSE_OVER,
        BUTTON_SPRITE_MOUSE_DOWN,
        BUTTON_SPRITE_MOUSE_UP
    };
private:
    SDL_Point mPosition;
    BUTTONSPRITE mButtonStatus;
public:
    Button(double x, double y) {
        mPosition.x = x;
        mPosition.y = y;
        mButtonStatus = BUTTONSPRITE::BUTTON_SPRITE_MOUSE_OUT
    }

    void setPosition(double x, double y);
    void handleEvent(SDL_Event* e);
    void render();
};


#endif //CGULL_BUTTON_H
