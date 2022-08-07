
#include <chrono>
#include <thread>
#include "Splash.h"
#include "Config.h"

extern SDL_Renderer* gRenderer;

void Splash::render() {
    for (Texture& i : mSplashes) {
        SDL_RenderClear(gRenderer);
        i.render(0, 0);
        SDL_RenderPresent(gRenderer);
        std::this_thread::sleep_for(std::chrono::milliseconds(Config::SPLASH_DURATION));
    }
}
