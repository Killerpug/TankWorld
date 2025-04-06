cmake_minimum_required(VERSION 3.27)
project(TankWorld)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

add_executable(TankWorld main.cpp
        graphics.cpp
        graphics.h
        texture.h
        texture.cpp
        player.cpp
        player.h)


target_link_libraries(TankWorld SDL2 SDL2_image)