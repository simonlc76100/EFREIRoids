#include "header/Controller.hpp"
#include "header/Framework.hpp"

int main(int argc, char* argv[]) {
    Framework *fw = new Framework(144, 60, 20);
    Controller *controller = new Controller(fw, fw->GetScreenWidth(), fw->GetScreenHeight());
    controller->LaunchGame();
    delete controller;
    delete fw;

    return 0;
}
