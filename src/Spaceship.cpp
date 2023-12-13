#include "header/Spaceship.hpp"

Spaceship::Spaceship(double x, double y, double size, double angle, double speed)
        : FlyingObject(x, y, size), angle(angle), speed(speed){}

double Spaceship::GetAngle() const {
    return angle;
}

void Spaceship::SpeedUp(double accelerationFactor) {
    speed += accelerationFactor;
}

void Spaceship::SpeedDown(double decelerationFactor) {
    speed -= decelerationFactor;
    if (speed < 0) speed = 0;
}

void Spaceship::Move() {
    double radianAngle = M_PI * (angle-90) / 180;
    double dx = cos(radianAngle) * speed;
    double dy = sin(radianAngle) * speed;
    SetX(GetX() + dx);
    SetY(GetY() + dy);
}

void Spaceship::Rotate(double rAngle) {
    angle += rAngle;
}
