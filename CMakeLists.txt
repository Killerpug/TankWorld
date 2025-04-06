cmake_minimum_required(VERSION 3.27)
project(TankWorld)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

add_executable(TankWorld main.cpp
        graphics/graphics.cpp
        graphics/graphics.h
        graphics/texture.h
        graphics/texture.cpp
        entities/player.cpp
        entities/player.h
        game/world.cpp
        game/world.h
        graphics/drawable.h
)


target_link_libraries(TankWorld SDL2 SDL2_image)