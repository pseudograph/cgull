#ifndef CGULL_CONFIG_H
#define CGULL_CONFIG_H

namespace Config {
    // dimensions
    const int SCREEN_WIDTH{ 1280 };
    const int SCREEN_HEIGHT{ 720 };
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
}
#endif //CGULL_CONFIG_H
