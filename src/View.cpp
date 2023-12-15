#include "header/View.hpp"
#include "header/Asteroid.hpp"
#include "header/Missile.hpp"
#include "header/Spaceship.hpp"

void View::RefreshDisplay(const std::vector<FlyingObject*>& objects) {

    for (const auto& obj : objects) {
        std::string typeName = obj->GetTypeName();
        if (typeName == "Asteroid") {
            Asteroid* asteroid = dynamic_cast<Asteroid*>(obj);
            if (asteroid) {
                framework->DrawAsteroid(asteroid->GetX(), asteroid->GetY(), asteroid->GetSize());
            }
        } else if (typeName == "Missile") {
            Missile* missile = dynamic_cast<Missile*>(obj);
            if (missile) {
                framework->DrawMissile(missile->GetX(), missile->GetY());
            }
        } else if (typeName == "Spaceship") {
            Spaceship* spaceship = dynamic_cast<Spaceship*>(obj);
            if (spaceship) {
                framework->DrawShip(spaceship->GetX(), spaceship->GetY(), spaceship->GetAngle(), 0.0, false);
            }
        }
    }
    framework->Update();
}

