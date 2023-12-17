#include "header/Controller.hpp"

Controller::Controller(Framework* fw, int screenWidth, int screenHeight)
        : framework(fw), model(new Model(fw, screenWidth, screenHeight)), view(new View(fw)) {}

Controller::~Controller() {
    delete model;
    delete view;
}

void Controller::LaunchGame() {
    while (true) {

        framework->PollEvents();

        if (framework->IsKeyPressed(SDLK_ESCAPE)) {
            break;
        }
        if (framework->IsKeyPressed(SDLK_SPACE)) {
            model->FireMissile();
        }

        model->PlayerAction();
        model->Update();

        std::vector<FlyingObject*> objects = model->GetFlyingObjects();
        view->RefreshDisplay(objects);
    }
}

