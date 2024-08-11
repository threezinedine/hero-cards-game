#include "distance.hpp"

namespace ntt
{
    float CalculateDistance(const Vector2 &a, const Vector2 &b)
    {
        return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    }
}