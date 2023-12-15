#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Model.hpp"
#include "View.hpp"
#include "Framework.hpp"

class Controller {
private:
    Model* model;
    View* view;
    Framework* framework;

public:
    Controller(Framework* fw, int screenWidth, int screenHeight);
    ~Controller();
    void LaunchGame();
};

#endif // CONTROLLER_HPP
