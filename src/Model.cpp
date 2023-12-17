#include "header/Model.hpp"
#include <random>
#include <cmath>

Model::Model(Framework* fw, int screenWidth, int screenHeight)
        : framework(fw), screenWidth(screenWidth), screenHeight(screenHeight),
          asteroid(nullptr), missile(nullptr),
          spaceship(new Spaceship(screenWidth / 2, screenHeight / 2, 20, 0.0, 0.0, 0.0, 10.0)) {
    InitializeAsteroid();
}

Model::~Model() {
    delete asteroid;
    delete missile;
    delete spaceship;
}

void Model::PlayerAction() {
    if (spaceship == nullptr) return;

    if (framework->IsKeyPressed(SDLK_UP)) {
        spaceship->SpeedUp(0.05);
    }
    if (framework->IsKeyPressed(SDLK_DOWN)) {
        spaceship->SpeedDown(0.05);
    }
    if (framework->IsKeyPressed(SDLK_LEFT)) {
        spaceship->Rotate(-3.0);
    }
    if (framework->IsKeyPressed(SDLK_RIGHT)) {
        spaceship->Rotate(3.0);
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

void Model::InitializeAsteroid() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> zone_dist(0, 7);
    int zone = zone_dist(gen);
    if (zone >= 4) zone++;

    int zoneWidth = screenWidth / 3;
    int zoneHeight = screenHeight / 3;
    int minX = (zone % 3) * zoneWidth;
    int minY = (zone / 3) * zoneHeight;

    std::uniform_real_distribution<> x_dist(minX, minX + zoneWidth);
    std::uniform_real_distribution<> y_dist(minY, minY + zoneHeight);

    delete asteroid;
    double x = x_dist(gen);
    double y = y_dist(gen);
    double speed = 1.0;
    std::uniform_real_distribution<> angle_dist(-180.0, 180.0);
    double angle = angle_dist(gen);
    double xSpeed = speed * cos(angle * M_PI / 180);
    double ySpeed = speed * sin(angle * M_PI / 180);
    asteroid = new Asteroid(x, y, 100, xSpeed, ySpeed);
}

void Model::FireMissile(){

    if(!missile) {
        double x = spaceship->GetX();
        double y = spaceship->GetY();
        double speed = 5.0;
        double angle = spaceship->GetAngle();
        missile = new Missile(x, y, 10, speed, angle);
    }
}

