
#ifndef CGULL_SPLASH_H
#define CGULL_SPLASH_H

#include <vector>
#include "Config.h"
#include "Texture/Texture.h"
#include <cstdarg>

class Splash {
private:
    std::vector<Texture> splashes;
public:
    Splash(const std::string& splashes...) {

    }
    void render();
};


#endif //CGULL_SPLASH_H
