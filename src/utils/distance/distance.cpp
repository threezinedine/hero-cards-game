#include "distance.hpp"

namespace ntt
{
    float CalculateDistance(const Point &a, const Point &b)
    {
        return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    }
}