
#ifndef CGULL_TEXTURE_H
#define CGULL_TEXTURE_H

#include <SDL.h>
#include <string>
#include "Config.h"


class Texture {
protected:
    SDL_Texture *mTexture{};
    int mX{};
    int mY{};
    int mWidth{};
    int mHeight{};
    Uint32 mFormat{};

public:
    Texture() : mTexture{ nullptr }, mWidth{ 0 }, mHeight{ 0 }, mX{ Config::SCREEN_WIDTH / 2 }, mY{ Config::SCREEN_HEIGHT / 2 }
    {}

    explicit Texture(const std::string& path) : Texture{ path, 0, 0 }
    {}

    Texture(const std::string& path, int x, int y) {
        mX = x;
        mY = y;
        loadFromFile(path);
    }

    Texture(Texture&& moveTex)  noexcept {
        mTexture = moveTex.mTexture;
        moveTex.mTexture = nullptr;
        SDL_QueryTexture(mTexture, nullptr, nullptr, &mWidth, &mHeight);
    }

    Texture& operator=(Texture&& moveTex) noexcept {
        if (&moveTex == this) { return *this; }
        free();
        mTexture = moveTex.mTexture;
        moveTex.mTexture = nullptr;
        SDL_QueryTexture(mTexture, nullptr, nullptr, &mWidth, &mHeight);
        return *this;
    }

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
    virtual void render();
};


#endif //CGULL_TEXTURE_H
