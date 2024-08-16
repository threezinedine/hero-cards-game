#include <gtest/gtest.h>
#include "Random.hpp"

TEST(RandomTest, WhenGenerateRandomNumberInRange_ReturnNumberInRange)
{
    auto number = ntt::RandomFloatUniform(0, 10);

    ASSERT_GE(number, 0);
    ASSERT_LE(number, 10);
}

TEST(RandomTest, WhenGenerateRandomWithOnlyHighLimit_ReturnNumberInRangeFrom0)
{
    auto number = ntt::RandomFloatUniform(10);

    ASSERT_GE(number, 0);
    ASSERT_LE(number, 10);
}