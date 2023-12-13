#include "header/Framework.hpp"
#include "header/Asteroid.hpp"
#include "header/Missile.hpp"
#include "header/Spaceship.hpp"

int main(int argc, char* argv[]) {
    Framework *fw = new Framework(144, 60, 20);

    Asteroid *asteroid = new Asteroid(fw->GetScreenWidth()/2, fw->GetScreenHeight()/2-300, 100, 0, 0);
    Missile *missile = new Missile(fw->GetScreenWidth()/2, fw->GetScreenHeight()/2, 20, 1, 270.0);
    Spaceship *spaceship = new Spaceship(fw->GetScreenWidth()/2, fw->GetScreenHeight()/2, 20, 0.0, 0.0);

    while (true) {
        int key = fw->GetInput();

        if (key == SDLK_ESCAPE) break;

        switch (key) {
            case SDLK_UP:
                spaceship->SpeedUp(0.20);
                break;
            case SDLK_DOWN:
                spaceship->SpeedDown(0.20);
                break;
            case SDLK_LEFT:
                spaceship->Rotate(-10.0);
                break;
            case SDLK_RIGHT:
                spaceship->Rotate(10.0);
                break;
        }

        if (asteroid) {
            fw->DrawAsteroid(asteroid->GetX(), asteroid->GetY(), asteroid->GetSize());
        }

        if (missile) {
            fw->DrawMissile(missile->GetX(), missile->GetY());
            if (FlyingObject::Collide(*missile, *asteroid)) {
                delete missile; delete asteroid;
                missile = nullptr; asteroid = nullptr;
            } else if (missile->Move(fw->GetScreenWidth(), fw->GetScreenHeight())) {
                delete missile;
                missile = nullptr;
            }
        }

        if (spaceship) {
            spaceship->Move();
            fw->DrawShip(spaceship->GetX(), spaceship->GetY(), spaceship->GetAngle(), 0.0, false);
        }

        fw->Update();
    }

    delete asteroid;
    delete missile;
    delete spaceship;
    delete fw;

    return 0;
}
