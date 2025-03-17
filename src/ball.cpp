#include "ball.h"

namespace cc7515
{
    Ball::Ball(Vector position, float radius, float mass)
        : position(position), radius(radius), mass(mass)
    {
    }

    void Ball::update(float dt)
    {
        Vector acceleration = {0, 0};
        for (auto &force : forces)
        {
            acceleration += force / mass;
        }

        Vector velocity = acceleration * dt;
        position += velocity * dt;

        forces.clear();
    }

    Ball &Ball::operator+=(const Vector &force)
    {
        forces.push_back(force);
        return *this;
    }

    std::ostream &operator<<(std::ostream &os, const Ball &ball)
    {
        os << "Ball { position: " << ball.position.x << ", " << ball.position.y
           << ", radius: " << ball.radius << ", mass: " << ball.mass << " }";
        return os;
    }
}
