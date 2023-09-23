// FlyingObject.hpp

#ifndef FLYINGOBJECT_HPP
#define FLYINGOBJECT_HPP

#include <cmath>

class FlyingObject {
private:
    double x;
    double y;
    double size;

public:
    // Constructeur
    FlyingObject(double x, double y, double size);

    double GetX() const;
    double GetY() const;
    double GetSize() const;

    void SetX(double x);
    void SetY(double y);
    void SetSize(double size);

    virtual void Move();
    virtual bool Move(double screenWidth, double screenHeight);

    static bool Collide(const FlyingObject& o1, const FlyingObject& o2);
};

#endif // FLYINGOBJECT_HPP
