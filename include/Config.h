#ifndef CGULL_CONFIG_H
#define CGULL_CONFIG_H

#include <string>

namespace Config {
    // properties
    const std::string WINDOW_TITLE{ "Ancient Astronauts" };
    // dimensions
    const int SCREEN_WIDTH{ 1280 };
    const int SCREEN_HEIGHT{ 960 };
    const int TEXTBOX_X{ SCREEN_WIDTH / 4 };
    const int TEXTBOX_Y{ SCREEN_HEIGHT * 3 / 4 };
    const int TEXTBOX_WIDTH{ SCREEN_WIDTH / 2 };
    const int TEXTBOX_HEIGHT{ SCREEN_HEIGHT * 1 / 4 };
    const int SCENE_X{ 0 };
    const int SCENE_Y{ 0 };
    const int SCENE_WIDTH{ SCREEN_WIDTH };
    const int SCENE_HEIGHT{ SCREEN_HEIGHT - TEXTBOX_HEIGHT };

    // timers
    const int SPLASH_FADE_DURATION{ 1000 };
    const int SPLASH_DURATION{ 1500 };

    // assets
    // splashes
    const std::string STUDIO{ "../assets/splashes/fullgarde.png" };
    const std::string ENGINE{ "../assets/splashes/cgull.png" };
}

namespace Errors {
    // main.cpp
    const std::string INIT_FAILED { "Failed to initialize" };
    const std::string INIT_SDL_FAILED{ "Failed to initialize SDL" };
    const std::string INIT_SETHINT_FAILED{ "Failed to set SDL hint" };
    const std::string INIT_WINDOW_FAILED{ "Failed to create window" };
    const std::string INIT_RENDERER_FAILED{ "Failed to create renderer" };
    const std::string IMGINIT_FAILED{ "Failed to initialize SDL_image" };
    const std::string TTFINIT_FAILED{ "Failed to initialize SDL_image" };
    // Texture.cpp
    const std::string TEXTURE_LOADFILE_FAILED{ "Texture::loadFromFile failed to load image" };
    const std::string TEXTURE_LOADTEXTURE_FAILED{ "Texture::loadFromFile failed to create texture from " };

}
#endif //CGULL_CONFIG_H
