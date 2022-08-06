
#ifndef CGULL_TEXTURE_H
#define CGULL_TEXTURE_H

#include <SDL.h>
#include <string>


class Texture {
public:
    SDL_Texture *mTexture;
    int mWidth;
    int mHeight;
    Uint32 mFormat;

public:
    Texture() : mTexture{ nullptr }, mWidth{ 0 }, mHeight{ 0 }
    {}

    Texture(const std::string& path) : Texture{} {
        loadFromFile(path);
    }

    Texture(Texture&& moveTex) {
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

    virtual void render(int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* centre = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE) const;
};


#endif //CGULL_TEXTURE_H
