#include "header/Missile.hpp"
#include <cmath>

Missile::Missile(double x, double y, double size, double speed, double angle)
        : FlyingObject(x, y, size), speed(speed), angle(angle) {}

// Getters
double Missile::GetSpeed() const {
    return speed;
}

double Missile::GetAngle() const {
    return angle;
}

// Setters
void Missile::SetSpeed(double speed) {
    this->speed = speed;
}

void Missile::SetAngle(double angle) {
    this->angle = angle;
}

void Missile::Move() {

    double rad = angle * (M_PI/180.0);

    SetX(GetX() + speed * cos(rad));
    SetY(GetY() + speed * sin(rad));
}

bool Missile::Move(double screenWidth, double screenHeight) {

    this->Move();

    //if(GetX()<0 || GetX() > screenWidth && GetY()<0 || GetY() > screenHeight)

    return true;
}

