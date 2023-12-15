#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "FlyingObject.hpp"

class Missile : public FlyingObject{

private:
    double speed;
    double angle;

public:
    Missile(double x, double y, double size, double speed, double angle);

    double GetSpeed() const;
    double GetAngle() const;

    void SetSpeed(double speed);
    void SetAngle(double angle);

    void Move() override;
    bool Move(double screenWidth, double screenHeight) override;

    std::string GetTypeName() const override { return "Missile"; }
};

#endif //MISSILE_HPP
