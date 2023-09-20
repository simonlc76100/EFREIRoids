#include "header/asteroid.hpp"

// Constructeur
Asteroid::Asteroid(double x, double y, double size, double xSpeed, double ySpeed)
        : x(x), y(y), size(size), xSpeed(xSpeed), ySpeed(ySpeed) {}

// Getters
double Asteroid::GetX() const {
    return x;
}

double Asteroid::GetY() const {
    return y;
}

double Asteroid::GetXSpeed() const {
    return xSpeed;
}

double Asteroid::GetYSpeed() const {
    return ySpeed;
}

double Asteroid::GetSize() const {
    return size;
}

// Setters
void Asteroid::SetX(double x) {
    this->x = x;
}

void Asteroid::SetY(double y) {
    this->y = y;
}

void Asteroid::SetXSpeed(double xSpeed) {
    this->xSpeed = xSpeed;
}

void Asteroid::SetYSpeed(double ySpeed) {
    this->ySpeed = ySpeed;
}

void Asteroid::SetSize(double size) {
    this->size = size;
}

// Méthodes pour déplacer l'astéroïde
void Asteroid::Move() {
    x += xSpeed;
    y += ySpeed;
}

void Asteroid::Move(double screenWidth, double screenHeight) {
    x += xSpeed;
    y += ySpeed;

    if (x < 0) {
        x = screenWidth;
    } else if (x > screenWidth) {
        x = 0;
    }

    if (y < 0) {
        y = screenHeight;
    } else if (y > screenHeight) {
        y = 0;
    }
}
