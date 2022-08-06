//
// Created by iv on 8/5/22.
//

#include "Sprite.h"
#include "Config.h"

extern SDL_Renderer* gRenderer;

void Sprite::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* centre, SDL_RendererFlip flip) const {
    SDL_Rect renderQuad{ x, y, mWidth, mHeight };
    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(gRenderer, mTexture, nullptr, &renderQuad, angle, centre, flip);
    SDL_RenderPresent(gRenderer);
}

void Sprite::renderLeft() {
    SDL_RenderClear(gRenderer);
    SDL_Rect leftViewport{ 0, 0, Config::SCENE_WIDTH / 2, Config::SCENE_HEIGHT };
    SDL_RenderSetViewport(gRenderer, &leftViewport);
    Texture::render(0, 0, &leftViewport);
}

void Sprite::renderRight() {
    SDL_RenderClear(gRenderer);
    SDL_Rect rightViewport{ Config::SCENE_WIDTH / 2, 0, Config::SCENE_WIDTH / 2, Config::SCENE_HEIGHT };
    SDL_RenderSetViewport(gRenderer, &rightViewport);
    Texture::render(0, 0, &rightViewport);
}

