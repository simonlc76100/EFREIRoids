#ifndef MODEL_HPP
#define MODEL_HPP

#include "Asteroid.hpp"
#include "Missile.hpp"
#include "Spaceship.hpp"
#include "Framework.hpp"
#include <vector>

class Model {
private:
    int screenWidth;
    int screenHeight;
    Framework* framework;
    Asteroid* asteroid;
    Missile* missile;
    Spaceship* spaceship;

public:
    Model(Framework* fw, int screenWidth, int screenHeight);
    ~Model();

    void PlayerAction();
    void Update();
    std::vector<FlyingObject*> GetFlyingObjects();
    void InitializeAsteroid();

};

#endif // MODEL_HPP
