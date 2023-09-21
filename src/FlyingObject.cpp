#include "header/FlyingObject.hpp"

// Constructeur
FlyingObject::FlyingObject(double x, double y, double size)
        : x(x), y(y), size(size) {}

// Getters
double FlyingObject::GetX() const {
    return x;
}

double FlyingObject::GetY() const {
    return y;
}

double FlyingObject::GetSize() const {
    return size;
}

// Setters
void FlyingObject::SetX(double x) {
    this->x = x;
}

void FlyingObject::SetY(double y) {
    this->y = y;
}

void FlyingObject::SetSize(double size) {
    this->size = size;
}

void FlyingObject::Move() {}

bool FlyingObject::Move(double screenWidth, double screenHeight){}