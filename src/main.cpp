#include "header/Framework.hpp"
#include "header/Asteroid.hpp"
#include "header/Missile.hpp"
#include "header/FlyingObject.hpp"

int main(int argc, char* argv[]) {
    Framework * fw = new Framework(144, 60, 20);

    Asteroid * asteroid = new Asteroid(fw->GetScreenWidth()/2, fw->GetScreenHeight()/2-300, 100, 0, 0);

    Missile * missile = new Missile(fw->GetScreenWidth()/2, fw->GetScreenHeight()/2,20,1,270.0);

    while (true) {

        if(fw->GetInput()==SDLK_ESCAPE) break;

        // Dessiner l'astéroïde
        if(asteroid)
            fw->DrawAsteroid(asteroid->GetX(), asteroid->GetY(), asteroid->GetSize());

        if (missile) { // On vérifie que missile existe
            fw->DrawMissile(missile->GetX(),missile->GetY());

            // On vérifie la collision entre le missile et l'astéroïde
            if (FlyingObject::Collide(*missile, *asteroid)) {
                delete missile;
                delete asteroid;

                missile = nullptr;
                asteroid = nullptr;

                // On vérifie si le missile sort de l'écran
            } else if (missile->Move(fw->GetScreenWidth(), fw->GetScreenHeight())) {
                delete missile;
                missile = nullptr;
            }
        }
        fw->Update();
    }
    return 0;
}
