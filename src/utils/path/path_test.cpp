#include <gtest/gtest.h>
#include "path_tools.hpp"

TEST(PathTest, TestPathJoin)
{
    auto path = ntt::path::absolute("C:/Acer/Users");
    EXPECT_EQ(path, "C:/Acer/Users");
}

TEST(PathTest, GivenConfigurePath_WhenUseRelativePath_ThenReturnAbsolutePath)
{
    ntt::path::setBasePath("C:/Acer/Users");
    auto path = ntt::path::relative("assets");
    EXPECT_EQ(path, "C:\\Acer\\Users\\assets");
}

TEST(PathTest, WhenGetThePathWithUnneccesarySlash_ThenReturnCorrectPath)
{
    ntt::path::setBasePath("C:/Acer/Users/");
    auto path = ntt::path::relative("assets");
    EXPECT_EQ(path, "C:\\Acer\\Users\\assets");
}