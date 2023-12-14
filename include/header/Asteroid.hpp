#ifndef ASTEROID_HPP
#define ASTEROID_HPP

#include "FlyingObject.hpp"

class Asteroid : public FlyingObject {
private:
    double xSpeed;
    double ySpeed;

public:
    Asteroid(double x, double y, double size, double xSpeed, double ySpeed);

    double GetXSpeed() const;
    double GetYSpeed() const;

    void SetXSpeed(double xSpeed);
    void SetYSpeed(double ySpeed);

    bool Move(double screenWidth, double screenHeight) override;
};

#endif // ASTEROID_HPP
