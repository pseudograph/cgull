
#ifndef CGULL_SPLASH_H
#define CGULL_SPLASH_H

#include <vector>
#include <iostream>
#include "Config.h"
#include "Texture/Texture.h"

class Splash {
public:
    std::vector<Texture> mSplashes;
public:
    Splash(const std::vector<std::string>& splashStrings) {
        for (const auto& i : splashStrings) {
            mSplashes.emplace_back(i);
        }
    }
    void render();
};


#endif //CGULL_SPLASH_H
