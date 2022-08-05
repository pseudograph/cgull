
#ifndef CGULL_SCREEN_H
#define CGULL_SCREEN_H

#include <vector>
#include "Texture/Texture.h"
#include "Background/Background.h"
#include "Button/Button.h"


class Screen {
private:
    Background bg;
    std::vector<Button> buttons;
public:
    void render();
};


#endif //CGULL_SCREEN_H
