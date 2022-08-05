
#ifndef CGULL_TEXTURE_H
#define CGULL_TEXTURE_H

#include <SDL.h>
#include <string>




class Texture {
protected:
    SDL_Texture *mTexture;
    int mWidth;
    int mHeight;

public:
    Texture() : mTexture{ nullptr }, mWidth{ 0 }, mHeight{ 0 }
    {}

    ~Texture() {
        free();
    }

    bool loadFromFile(const std::string& path);
    void setColor(Uint8 red, Uint8 green, Uint8 blue);
    void setBlendMode(SDL_BlendMode blendMode);
    void setAlpha(Uint8 alpha);

    void free();
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getHeight() const;

    virtual void render(int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* centre = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);
};


#endif //CGULL_TEXTURE_H
