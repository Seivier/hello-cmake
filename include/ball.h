#include <glm/glm.hpp>
#include <vector>
#include <iostream>

namespace cc7515
{
    using Vector = glm::vec2;
    class Ball
    {
    public:
        Ball(Vector position, float radius, float mass);
        void update(float dt);

        Ball &operator+=(const Vector &force);
        inline Vector getPosition() const { return position; }
        inline float getRadius() const { return radius; }
        inline float getMass() const { return mass; }

        friend std::ostream &operator<<(std::ostream &os, const Ball &ball);

    private:
        Vector position;
        float radius;
        float mass;

        std::vector<Vector> forces;
    };
}
