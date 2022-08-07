//
// Created by iv on 8/4/22.
//

#include "Screen.h"

void Screen::render() {
    for (Texture& i : mTextures) {
        i.render();
    }
}
