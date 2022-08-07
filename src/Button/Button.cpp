
#include "Button.h"

extern SDL_Renderer* gRenderer;

bool Button::loadSpriteSheet(const std::string& path) {
    SDL_QueryTexture(mSpriteSheet.getTexture(), &mFormat, nullptr, &mWidth, &mHeight);
    std::cout << "mWidth: " << mWidth << std::endl;
    std::cout << "mHeight: " << mHeight << std::endl;
    mHeight /= static_cast<int>(BUTTONSPRITE::BUTTON_SPRITE_COUNT);
    for (int i{ 0 }; i < static_cast<int>(BUTTONSPRITE::BUTTON_SPRITE_COUNT); ++i) {
        std::cout << "emplacing" << std::endl;
        mButtonSpriteVector.emplace_back(SDL_Rect{ 0, i * mHeight, mWidth, mHeight });
    }
    if (mSpriteSheet.getTexture() == nullptr) {
        return false;
    }
    return true;
}

void Button::setPosition(double x, double y) {
    mPosition.x = static_cast<int>(x * Config::SCREEN_WIDTH);
    mPosition.y = static_cast<int>(y * Config::SCREEN_HEIGHT);
}

void Button::handleEvent(SDL_Event *e) {
    int x;
    int y;
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
        SDL_GetMouseState(&x, &y);
    }
    bool inside{ true };
    if      (x < mPosition.x)           { inside = false; }
    else if (x > mPosition.x + mWidth)  { inside = false; }
    else if (y < mPosition.y)           { inside = false; }
    else if (y > mPosition.y + mHeight) { inside = false; }
    if (!inside) {
        mButtonSprite = BUTTONSPRITE::BUTTON_SPRITE_MOUSE_OUT;
        return;
    }
    switch (e->type) {
    case SDL_MOUSEMOTION:
        mButtonSprite = BUTTONSPRITE::BUTTON_SPRITE_MOUSE_OVER;
        break;
    case SDL_MOUSEBUTTONDOWN:
        mButtonSprite = BUTTONSPRITE::BUTTON_SPRITE_MOUSE_DOWN;
        break;
    case SDL_MOUSEBUTTONUP:
        mButtonSprite = BUTTONSPRITE::BUTTON_SPRITE_MOUSE_UP;
        break;
    }
}

void Button::render() {
    mSpriteSheet.render(mPosition.x, mPosition.y, &mButtonSpriteVector[static_cast<int>(mButtonSprite)]);
}

