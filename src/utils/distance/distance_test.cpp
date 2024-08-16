#include "distance.hpp"
#include <gtest/gtest.h>

TEST(DistanceTest, WhenGetTheDistanceBetweenAPointAndItself_Return0)
{
    auto point = ntt::Point{100, 100};

    auto distance = ntt::CalculateDistance(point, point);

    ASSERT_EQ(distance, 0);
}
