#include "Random.hpp"

namespace ntt
{
    float RandomFloatUniform(float min, float max)
    {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_real_distribution<float> distrib(min, max);

        return distrib(gen);
    }

    float RandomFloatUniform(float max)
    {
        return RandomFloatUniform(0, max);
    }
}