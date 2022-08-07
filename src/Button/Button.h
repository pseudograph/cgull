
#ifndef CGULL_BUTTON_H
#define CGULL_BUTTON_H

#include <vector>
#include <iostream>
#include "Config.h"
#include "Texture/Texture.h"
#include "SDL2/SDL_image.h"

class Button : public Texture {
    enum class BUTTONSPRITE {
        BUTTON_SPRITE_MOUSE_OUT,
        BUTTON_SPRITE_MOUSE_OVER,
        BUTTON_SPRITE_MOUSE_DOWN,
        BUTTON_SPRITE_MOUSE_UP,
        BUTTON_SPRITE_COUNT
    };
private:
    SDL_Point mPosition{};
    Texture mSpriteSheet{};
    std::vector<SDL_Rect> mButtonSpriteVector;
    BUTTONSPRITE mButtonSprite;
public:
    Button(const std::string& path, double x, double y) : mSpriteSheet{ path } {
        setPosition(x, y);
        loadSpriteSheet(path);
        mButtonSprite = BUTTONSPRITE::BUTTON_SPRITE_MOUSE_OUT;
    }

    bool loadSpriteSheet(const std::string& path);
    void setPosition(double x, double y);
    void handleEvent(SDL_Event* e);
    void render();
};


#endif //CGULL_BUTTON_H
