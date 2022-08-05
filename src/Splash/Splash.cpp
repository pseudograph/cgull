//
// Created by iv on 8/4/22.
//

#include "Splash.h"

extern SDL_Renderer* gRenderer;

void Splash::render() {
    for (auto i : splashes) {
        i.render();
    }
}
