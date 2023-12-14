#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "FlyingObject.hpp"

class Spaceship : public FlyingObject {
private:
    double angle;
    double xSpeed;
    double ySpeed;

public:
    Spaceship(double x, double y, double size, double angle, double xSpeed, double ySpeed);

    double GetAngle() const;

    void SpeedUp(double accelerationFactor);
    void SpeedDown(double decelerationFactor);
    bool Move(double screenWidth, double screenHeight) override;
    void Rotate(double rAngle);
};

#endif // SPACESHIP_HPP
