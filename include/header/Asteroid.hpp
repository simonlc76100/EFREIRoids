#ifndef ASTEROID_HPP
#define ASTEROID_HPP

class Asteroid {
private:
    double x;
    double y;
    double size;
    double xSpeed;
    double ySpeed;

public:
    // Constructeur
    Asteroid(double x, double y, double size, double xSpeed, double ySpeed);

    // Getters
    double GetX() const;
    double GetY() const;
    double GetXSpeed() const;
    double GetYSpeed() const;
    double GetSize() const;

    // Setters
    void SetX(double x);
    void SetY(double y);
    void SetXSpeed(double xSpeed);
    void SetYSpeed(double ySpeed);
    void SetSize(double size);

    // Méthodes pour déplacer l'astéroïde
    void Move();
    void Move(double screenWidth, double screenHeight);
};

#endif // ASTEROID_HPP
