#include "header/Spaceship.hpp"

Spaceship::Spaceship(double x, double y, double size, double angle, double xSpeed, double ySpeed)
        : FlyingObject(x, y, size), angle(angle), xSpeed(xSpeed), ySpeed(ySpeed){}

double Spaceship::GetAngle() const {
    return angle;
}

void Spaceship::SpeedUp(double accelerationFactor) {
    double radianAngle = M_PI * (angle-90) / 180;
    xSpeed += cos(radianAngle) * accelerationFactor;
    ySpeed += sin(radianAngle) * accelerationFactor;
}

void Spaceship::SpeedDown(double decelerationFactor) {
    double radianAngle = M_PI * (angle-90) / 180;
    xSpeed -= cos(radianAngle) * decelerationFactor;
    ySpeed -= sin(radianAngle) * decelerationFactor;
}

bool Spaceship::Move(double screenWidth, double screenHeight) {
    SetX(GetX() + xSpeed);
    SetY(GetY() + ySpeed);

    SetX(GetX() > screenWidth ? 0 : (GetX() < 0 ? screenWidth : GetX()));
    SetY(GetY() > screenHeight ? 0 : (GetY() < 0 ? screenHeight : GetY()));

    return true;
}


void Spaceship::Rotate(double rAngle) {
    angle += rAngle;
}
