#include <gtest/gtest.h>
#include "FunctionLog.hpp"

using namespace ntt;

class FunctionLogTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
    }

    void TearDown() override
    {
    }
};

TEST_F(FunctionLogTest, LogFunctionIsPutAtTheStartAndAutoReleaseAtTheEnd)
{
    {
        FunctionLog log("TestFunction", __FILE__, __LINE__);

        // Do something
    }
}
