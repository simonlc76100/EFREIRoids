cmake_minimum_required(VERSION 3.0.0)
project(SDLTEST VERSION 0.1.0 LANGUAGES C CXX)

set (SDL2_DIR ./)

file(COPY bin/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY assets/images/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/images/)

set(
        SRCS
        src/Asteroid.cpp
        src/Controller.cpp
        src/FlyingObject.cpp
        src/Framework.cpp
        src/main.cpp
        src/Missile.cpp
        src/Model.cpp
        src/Spaceship.cpp
        src/View.cpp
)

set(
        HEADER
        include/header/Asteroid.hpp
        include/header/Controller.hpp
        include/header/FlyingObject.hpp
        include/header/Framework.hpp
        include/header/Missile.hpp
        include/header/Model.hpp
        include/header/Spaceship.hpp
        include/header/View.hpp
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(SDLTEST ${SRCS} ${HEADER})
target_link_libraries(SDLTEST ${SDL2_LIBRARIES})