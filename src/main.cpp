#include "header/Framework.hpp"
#include "header/Asteroid.hpp"
#include "header/Missile.hpp"

int main(int argc, char* argv[]) {
    Framework * fw = new Framework(144, 60, 20);

    Asteroid * a = new Asteroid(fw->GetScreenWidth()/2, fw->GetScreenHeight()/2, 100, -1, 0);

    Missile * missile = new Missile(fw->GetScreenWidth()/2, fw->GetScreenHeight()/2,20,10,0.0);

    while (true) {

        if(fw->GetInput()==SDLK_ESCAPE) break;

        if (missile) { // On vérifie que missile existe dans un premier temps
            fw->DrawMissile(missile->GetX(),missile->GetY());

            if (missile->Move(fw->GetScreenWidth(), fw->GetScreenHeight())) {
                // Si le missile sort de l'écran, on supprime l'objet
                delete missile;
                missile = nullptr;
            }
        }
        fw->Update();
    }
}