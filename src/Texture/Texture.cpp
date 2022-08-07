//
// Created by iv on 8/4/22.
//

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include "Texture.h"
#include "Config.h"

extern SDL_Renderer* gRenderer;

bool Texture::loadFromFile(const std::string &path) {
    SDL_Texture* newTexture{ nullptr };
    newTexture = IMG_LoadTexture(gRenderer, path.c_str());
    // old loading method
    /**
    SDL_Surface* loadedSurface{ IMG_Load(path.c_str()) };
    if (loadedSurface == nullptr) {
        std::cerr << Errors::TEXTURE_LOADFILE_FAILED << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
    newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if (newTexture == nullptr) {
        std::cerr << Errors::TEXTURE_LOADTEXTURE_FAILED << path.c_str() << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }
    mWidth = loadedSurface->w;
    mHeight = loadedSurface->h;
    SDL_FreeSurface(loadedSurface);
    **/
    SDL_QueryTexture(newTexture, &mFormat, nullptr, &mWidth, &mHeight);
    mTexture = newTexture;
    return true;
}

void Texture::free() {
    if (mTexture != nullptr) {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* centre, SDL_RendererFlip flip) {
    SDL_Rect renderQuad{ x, y, mWidth, mHeight };
    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopy(gRenderer, mTexture, nullptr, nullptr);
}

void Texture::render() {
    Texture::render(mX, mY);
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    SDL_SetTextureColorMod(mTexture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blendMode) {
    SDL_SetTextureBlendMode(mTexture, blendMode);
}

void Texture::setAlpha(Uint8 alpha) {
    SDL_SetTextureAlphaMod(mTexture, alpha);
}

int Texture::getWidth() const {
    return mWidth;
}

int Texture::getHeight() const {
    return mHeight;
}

SDL_Texture *Texture::getTexture() const {
    return mTexture;
}
