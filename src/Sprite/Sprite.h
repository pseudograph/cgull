#ifndef CGULL_SPRITE_H
#define CGULL_SPRITE_H


#include "Texture/Texture.h"
#include "Config.h"

class Sprite : public Texture {

public:
    Sprite() : Texture{}
    {}

    Sprite(const std::string& path) : Texture{ path }
    {}

    void render(int x = Config::SCENE_WIDTH / 2,
                int y = Config::SCENE_HEIGHT - getHeight(),
                SDL_Rect* clip = nullptr,
                double angle = 0.0,
                SDL_Point* centre = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE)
                const override;
    void renderLeft();
    void renderRight();
};


#endif //CGULL_SPRITE_H
