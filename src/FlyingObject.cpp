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

bool FlyingObject::Collide(const FlyingObject& o1, const FlyingObject& o2) {
    // On calcule la distance entre les centres des deux objets
    double deltaX = o1.GetX() - o2.GetX();
    double deltaY = o1.GetY() - o2.GetY();
    double distance = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));

    // On vérifie si la distance est inférieure à la somme des rayons (size/2) des deux objets
    return distance < (o1.GetSize()/2 + o2.GetSize()/2);
}
