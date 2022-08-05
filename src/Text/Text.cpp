
#include "Text.h"

extern SDL_Renderer* gRenderer;
extern TTF_Font *gFont;

bool Text::loadFromRenderedText(const std::string& textureText, SDL_Color textColor) {
    free();
    SDL_Surface* textSurface{ TTF_RenderText_Solid(gFont, textureText.c_str(), textColor) };
    if (textSurface == nullptr) {
        std::cout << "Failed to render text surface" << std::endl;
        return false;
    }
    mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
    if (mTexture == nullptr) {
        std::cout << "Failed to create texture from rendered text" << std::endl;
        return false;
    }
    mWidth = textSurface->w;
    mHeight = textSurface->h;
    SDL_FreeSurface(textSurface);
    return mTexture != nullptr;
}
