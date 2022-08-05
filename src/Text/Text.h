
#ifndef CGULL_TEXT_H
#define CGULL_TEXT_H

#include <iostream>
#include <SDL2/SDL_ttf.h>
#include "Texture/Texture.h"

class Text : Texture {
private:

public:
    bool loadFromRenderedText(const std::string& textureText, SDL_Color textColor);

};


#endif //CGULL_TEXT_H
