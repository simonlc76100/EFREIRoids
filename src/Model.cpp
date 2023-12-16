#include "header/Model.hpp"

Model::Model(Framework* fw, int screenWidth, int screenHeight)
        : framework(fw),
            screenWidth(screenWidth), screenHeight(screenHeight),
            asteroid(new Asteroid(screenWidth / 2, screenHeight / 2 - 300, 100, 0, 0)),
            missile(nullptr),
            spaceship(new Spaceship(screenWidth / 2, screenHeight / 2, 20, 0.0, 0.0, 0.0, 10.0)) {}

Model::~Model() {
    delete asteroid;
    delete missile;
    delete spaceship;
}

void Model::PlayerAction() {
    if (spaceship == nullptr) return;

    // Vérification des touches maintenues et réaction en conséquence
    if (framework->IsKeyPressed(SDLK_UP)) {
        spaceship->SpeedUp(0.2);
    }
    if (framework->IsKeyPressed(SDLK_DOWN)) {
        spaceship->SpeedDown(0.2);
    }
    if (framework->IsKeyPressed(SDLK_LEFT)) {
        spaceship->Rotate(-10.0);
    }
    if (framework->IsKeyPressed(SDLK_RIGHT)) {
        spaceship->Rotate(10.0);
    }
}


void Model::Update() {
    if (asteroid != nullptr) {
        asteroid->Move(screenWidth, screenHeight);
    }
    if (missile != nullptr) {
        bool missileOutOfBounds = missile->Move(screenWidth, screenHeight);
        if (missileOutOfBounds) {
            delete missile;
            missile = nullptr;
        } else if (asteroid != nullptr && FlyingObject::Collide(*missile, *asteroid)) {
            delete missile;
            delete asteroid;
            missile = nullptr;
            asteroid = nullptr;
        }
    }
    if (spaceship != nullptr) {
        spaceship->Move(screenWidth, screenHeight);
    }
}

std::vector<FlyingObject*> Model::GetFlyingObjects() {
    std::vector<FlyingObject*> objects;
    if (asteroid) objects.push_back(asteroid);
    if (missile) objects.push_back(missile);
    if (spaceship) objects.push_back(spaceship);
    return objects;
}
