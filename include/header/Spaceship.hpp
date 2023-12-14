#ifndef SPACESHIP_HPP
#define SPACESHIP_HPP

#include "FlyingObject.hpp"

class Spaceship : public FlyingObject {
private:
    double angle;
    double speed;

public:
    Spaceship(double x, double y, double size, double angle, double speed);

    double GetAngle() const;

    void SpeedUp(double accelerationFactor);
    void SpeedDown(double decelerationFactor);
    void Move() override;
    void Rotate(double rAngle);
};

#endif // SPACESHIP_HPP
