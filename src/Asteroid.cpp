#include "header/Asteroid.hpp"

// Constructeur
Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed)
        : FlyingObject(x, y, size), xSpeed(xSpeed), ySpeed(ySpeed) {}

// Getters
double Asteroid::GetXSpeed() const {
    return xSpeed;
}

double Asteroid::GetYSpeed() const {
    return ySpeed;
}

// Setters
void Asteroid::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void Asteroid::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

bool Asteroid::Move(double screenWidth, double screenHeight) {
    SetX(GetX() + xSpeed);
    SetY(GetY() + ySpeed);

    SetX(GetX() > screenWidth ? 0 : (GetX() < 0 ? screenWidth : GetX()));
    SetY(GetY() > screenHeight ? 0 : (GetY() < 0 ? screenHeight : GetY()));

    return true;
}

