#ifndef CGULL_SPRITE_H
#define CGULL_SPRITE_H


#include "Texture/Texture.h"
#include "Config.h"

class Sprite : public Texture {

public:
    Sprite() : Texture{}
    {}

    explicit Sprite(const std::string& path) : Texture{ path }
    {}

    void render(int x,
                int y,
                SDL_Rect* clip = nullptr,
                double angle = 0.0,
                SDL_Point* centre = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE)
                override;
    void render(SDL_Rect* clip = nullptr,
                double angle = 0.0,
                SDL_Point* centre = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE) ;
    void renderLeft();
    void renderRight();
};


#endif //CGULL_SPRITE_H
