#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "Texture/Texture.h"
#include "Button/Button.h"
#include "Background/Background.h"
#include "Screen/Screen.h"
#include "Splash/Splash.h"
#include "Sprite/Sprite.h"
#include "Text/Text.h"


bool init();
void close();

SDL_Window* gWindow{ nullptr };
SDL_Renderer* gRenderer{ nullptr };
TTF_Font* gFont{ nullptr };

int main() {
    if (!init()) {
        std::cerr << Errors::INIT_FAILED << std::endl;
        return -1;
    }
    std::vector<std::string> splashes{ Config::STUDIO, Config::ENGINE };
    Splash splashSequence{ splashes };
    splashSequence.render();
    std::cout << IMG_GetError() << std::endl;
    std::cout << SDL_GetError() << std::endl;
}

bool init() {
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << Errors::INIT_SDL_FAILED << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        std::cerr << Errors::INIT_SETHINT_FAILED << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }
    // create window
    gWindow = SDL_CreateWindow(Config::WINDOW_TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, 0);
    if (gWindow == nullptr) {
        std::cerr << Errors::INIT_WINDOW_FAILED << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }
    // create renderer
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == nullptr) {
        std::cerr << Errors::INIT_RENDERER_FAILED << std::endl;
        std::cerr << SDL_GetError() << std::endl;
        return false;
    }
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    int imgFlags{ IMG_INIT_PNG };
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << Errors::IMGINIT_FAILED << std::endl;
        std::cerr << IMG_GetError() << std::endl;
        return false;
    }
    if (TTF_Init() == -1) {
        std::cerr << Errors::TTFINIT_FAILED << std::endl;
        std::cerr << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

void close() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    gRenderer = nullptr;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

