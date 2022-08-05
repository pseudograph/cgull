
#ifndef CGULL_BUTTON_H
#define CGULL_BUTTON_H

#include "Config.h"
#include "Texture/Texture.h"

class Button : Texture {
    enum class BUTTONSTATUS {
        UP,
        DOWN,
        MOTION
    };
private:
    SDL_Rect box;
    SDL_Rect* clip;
    BUTTONSTATUS mButtonStatus;
public:
    Button(double x, double y, double w, double h);

    void setX(double x, double y);
    void setX(int x, int y);
    void updateStatus(SDL_Event* e);
};


#endif //CGULL_BUTTON_H
