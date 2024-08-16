#include <gtest/gtest.h>
#include "ConfigurableObject.hpp"

using namespace ntt;

class ConfigObjectTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_ConfigObject.LoadConfigure(m_ConfigData);
    }

    void TearDown() override
    {
    }

    String floatObjectKey = "floatKey";
    String intObjectKey = "intObject";
    String stringObjectKey = "stringKey";
    String boolObjectKey = "boolKey";
    String arrayObjectKey = "arrayKey";
    String objectObjectKey = "objectKey";
    String arrayOfObjectObjectKey = "arrayOfObjectKey";

    JSON m_ConfigData = {
        {floatObjectKey, 23.5f},
        {intObjectKey, 23},
        {stringObjectKey, "Hello"},
        {boolObjectKey, true},
        {arrayObjectKey, {1, 2, 3}},
        {objectObjectKey, {{"key", "value"}}},
        {arrayOfObjectObjectKey, {{{"key", "value"}, {"key2", "value2"}, {"key3", "value3"}}}}};
    ConfigurableObject m_ConfigObject;
};

TEST_F(ConfigObjectTest, WhenAskWithTheKeyAndValidType_ThenReturnValueOfThatType)
{
    EXPECT_EQ(m_ConfigObject.Get<float>(floatObjectKey, 0.0f),
              m_ConfigData[floatObjectKey].get<float>());

#if _DEBUG
    EXPECT_EQ(m_ConfigObject.Get<String>(stringObjectKey, ""),
              m_ConfigData[stringObjectKey].get<String>());

    EXPECT_EQ(m_ConfigObject.Get<int>(intObjectKey, 0),
              m_ConfigData[intObjectKey].get<int>());

    EXPECT_EQ(m_ConfigObject.Get<bool>(boolObjectKey, false),
              m_ConfigData[boolObjectKey].get<bool>());
#endif

    EXPECT_EQ(m_ConfigObject.Get<JSON>(objectObjectKey, {}),
              m_ConfigData[objectObjectKey]);
}

TEST_F(ConfigObjectTest, WhenAskBoolWithIntKey_ThenReturnDefault)
{
    EXPECT_EQ(m_ConfigObject.Get<bool>(intObjectKey, true), true);
    EXPECT_EQ(m_ConfigObject.Get<bool>(intObjectKey, false), false);
}

TEST_F(ConfigObjectTest, WhenAskNonExistedKey_ThenReturnsDefault)
{
    auto result = m_ConfigObject.Get<int>("nonExistedKey", 3);
    EXPECT_EQ(result, 3);
}

TEST_F(ConfigObjectTest, WhenAskList_ThenReturnList)
{
    EXPECT_EQ(m_ConfigObject.GetList<int>(arrayObjectKey), m_ConfigData[arrayObjectKey]);
}

TEST_F(ConfigObjectTest, WhenAskListWithNonExistedKey_ThenReturnAnEmptyList)
{
    auto result = m_ConfigObject.GetList<int>("nonExistedKey");
    EXPECT_EQ(result.size(), 0);
}

TEST_F(ConfigObjectTest, WhenAskFloatOfIntObject_ThenReturnThatCastedNumber)
{
    auto result = m_ConfigObject.Get<float>(intObjectKey, 0.0f);
    EXPECT_EQ(result, 23.0f);
}

TEST_F(ConfigObjectTest, WhenAskIntOfFloatObject_ThenReturnThatCastedNumber)
{
    auto result = m_ConfigObject.Get<int>(floatObjectKey, 0);
    EXPECT_EQ(result, 23);
}

TEST_F(ConfigObjectTest, WhenAskTheArrayOfObject_ThenReturnTheArrayOfObject)
{
    auto result = m_ConfigObject.GetList<JSON>(arrayOfObjectObjectKey);

    EXPECT_EQ(result.size(), m_ConfigData[arrayOfObjectObjectKey].size());

    EXPECT_TRUE(result[0].is_object());
}

TEST_F(ConfigObjectTest, WhenAskTheArrayOfObjectAsListOfConfigObject_ThenReturnTheListOfThem)
{
    auto result = m_ConfigObject.ExtractList(arrayOfObjectObjectKey);

    EXPECT_EQ(result.size(), m_ConfigData[arrayOfObjectObjectKey].size());
    EXPECT_EQ(result[0].Get<int>("test", -2), -2);
}