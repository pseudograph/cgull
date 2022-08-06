//
// Created by iv on 8/5/22.
//

#include "Sprite.h"
#include "Config.h"

extern SDL_Renderer* gRenderer;

void Sprite::renderLeft() {
    SDL_Rect leftViewport{ 0, 0, Config::SCENE_WIDTH / 2, Config::SCENE_HEIGHT / 2 };
    SDL_RenderSetViewport(gRenderer, &leftViewport);
    render(0, 0, &leftViewport);
}

void Sprite::renderRight() {
    SDL_Rect rightViewport{ Config::SCENE_WIDTH / 2, 0, Config::SCENE_WIDTH / 2, Config::SCENE_HEIGHT };
    SDL_RenderSetViewport(gRenderer, &rightViewport);
    render(0, 0, &rightViewport);
}
