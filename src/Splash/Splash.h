
#ifndef CGULL_SPLASH_H
#define CGULL_SPLASH_H

#include <vector>
#include "Screen/Screen.h"
#include "Config.h"

class Splash {
private:
    std::vector<Screen> splashes;
public:
    void render();
};


#endif //CGULL_SPLASH_H
