cmake_minimum_required(VERSION 3.22)
project(cgull)
set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(
        include
        src
        ${SDL2_INCLUDE_DIRS}
        ${SDL2IMAGE_INCLUDE_DIRS}
        ${SDL2TTF_INCLUDE_DIRS}
)

add_executable(cgull main.cpp src/Config.h src/Texture/Texture.cpp src/Texture/Texture.h src/Screen/Screen.cpp src/Screen/Screen.h src/Text/Text.cpp src/Text/Text.h src/Splash/Splash.cpp src/Splash/Splash.h src/Button/Button.cpp src/Button/Button.h src/Background/Background.cpp src/Background/Background.h src/Sprite/Sprite.cpp src/Sprite/Sprite.h)
target_link_libraries(cgull
        SDL2
        SDL2_image
        SDL2_ttf)
