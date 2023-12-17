#include "header/Missile.hpp"
#include <cmath>

Missile::Missile(double x, double y, double size, double speed, double angle)
        : FlyingObject(x, y, size), speed(speed), angle(angle) {}

double Missile::GetSpeed() const {
    return speed;
}

double Missile::GetAngle() const {
    return angle;
}

void Missile::SetSpeed(double speed) {
    this->speed = speed;
}

void Missile::SetAngle(double angle) {
    this->angle = angle;
}

void Missile::Move() {

    double radianAngle = M_PI * (angle - 90) / 180;

    SetX(GetX() + speed * cos(radianAngle));
    SetY(GetY() + speed * sin(radianAngle));
}

bool Missile::Move(double screenWidth, double screenHeight) {

    this->Move();

    if((GetX() < 0 || GetX() > screenWidth) || (GetY() < 0 || GetY() > screenHeight)){
        return true;
    }
    return false;
}

