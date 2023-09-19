#include "framework.hpp"

int main(int argc, char* argv[]) {
    Framework * fw = new Framework(100, 60, 20);
    while (true) {

        if(fw->GetInput()==SDLK_ESCAPE) break;

        fw->Update();
    }
}