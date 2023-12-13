cmake_minimum_required(VERSION 3.0.0)
project(SDLTEST VERSION 0.1.0 LANGUAGES C CXX)

set (SDL2_DIR ./)

file(COPY bin/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY images/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)

set(
        SRCS
        src/main.cpp
        src/Framework.cpp
)

set(
        HEADER
        include/header/Framework.hpp
        src/Asteroid.cpp
        src/FlyingObject.cpp
        include/header/FlyingObject.hpp
        src/Missile.cpp
        include/header/Missile.hpp
        include/header/Spaceship.hpp
        src/Spaceship.cpp
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDLTEST ${SRCS} ${HEADER})
target_link_libraries(SDLTEST ${SDL2_LIBRARIES})