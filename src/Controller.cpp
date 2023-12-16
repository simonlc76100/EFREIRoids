#include "header/Controller.hpp"

Controller::Controller(Framework* fw, int screenWidth, int screenHeight)
        : framework(fw), model(new Model(fw, screenWidth, screenHeight)), view(new View(fw)) {}

Controller::~Controller() {
    delete model;
    delete view;
}

void Controller::LaunchGame() {
    while (true) {

        framework->PollEvents(); // Mise à jour de l'état des touches

        if (framework->IsKeyPressed(SDLK_ESCAPE)) {
            break; // Sortir de la boucle et quitter le jeu
        }

        model->PlayerAction(); // Gère les actions du joueur en fonction des touches enfoncées
        model->Update();

        std::vector<FlyingObject*> objects = model->GetFlyingObjects();
        view->RefreshDisplay(objects);

        // Ajout d'un délai si nécessaire pour contrôler la vitesse de mise à jour du jeu
    }
}

