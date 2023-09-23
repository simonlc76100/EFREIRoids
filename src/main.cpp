#include "header/Framework.hpp"
#include "header/Asteroid.hpp"
#include "header/Missile.hpp"

int main(int argc, char* argv[]) {
    Framework * fw = new Framework(144, 60, 20);

    Asteroid * a = new Asteroid(fw->GetScreenWidth()/2, fw->GetScreenHeight()/2, 100, -1, 0);

    Missile * m1 = new Missile(fw->GetScreenWidth()/2, fw->GetScreenHeight()/2,20,1,0.0);

    while (true) {

        if(fw->GetInput()==SDLK_ESCAPE) break;

        //fw->DrawAsteroid(a->GetX(), a->GetY(), a->GetSize());

        //a->Move(fw->GetScreenWidth(), fw->GetScreenHeight());

        fw->DrawMissile(m1->GetX(),m1->GetY());

        m1->Move();

        fw->Update();
    }
}