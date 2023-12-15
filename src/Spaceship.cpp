#include "header/Spaceship.hpp"

Spaceship::Spaceship(double x, double y, double size, double angle, double xSpeed, double ySpeed, double maxSpeed)
        : FlyingObject(x, y, size), angle(angle), xSpeed(xSpeed), ySpeed(ySpeed), maxSpeed(maxSpeed){}

double Spaceship::GetAngle() const {
    return angle;
}

void Spaceship::SpeedUp(double accelerationFactor) {
    double radianAngle = M_PI * (angle-90) / 180;
    xSpeed += cos(radianAngle) * accelerationFactor;
    ySpeed += sin(radianAngle) * accelerationFactor;

    double speed = sqrt(xSpeed*xSpeed + ySpeed*ySpeed);
    if (speed > maxSpeed) {
        xSpeed = (xSpeed / speed) * maxSpeed;
        ySpeed = (ySpeed / speed) * maxSpeed;
    }
}

void Spaceship::SpeedDown(double decelerationFactor) {
    double radianAngle = M_PI * (angle-90) / 180;
    xSpeed -= cos(radianAngle) * decelerationFactor;
    ySpeed -= sin(radianAngle) * decelerationFactor;

    double speed = sqrt(xSpeed * xSpeed + ySpeed * ySpeed);

    if (speed > maxSpeed) {
        xSpeed = (xSpeed / speed) * maxSpeed * (xSpeed < 0 ? -1 : 1);
        ySpeed = (ySpeed / speed) * maxSpeed * (ySpeed < 0 ? -1 : 1);
    }
}

bool Spaceship::Move(double screenWidth, double screenHeight) {
    SetX(GetX() > screenWidth ? 0 : (GetX() < 0 ? screenWidth : GetX()));
    SetY(GetY() > screenHeight ? 0 : (GetY() < 0 ? screenHeight : GetY()));

    SetX(GetX() + xSpeed);
    SetY(GetY() + ySpeed);

    return true;
}

void Spaceship::Rotate(double rAngle) {
    angle += rAngle;
}
