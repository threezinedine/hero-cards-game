#include <gtest/gtest.h>
#include "Config.hpp"
#include <cores/commons/commons.hpp>
#include <utils/files/files.hpp>

using namespace ntt;

class ConfigTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        CreateConfigureFile();
        Config::Load(m_ConfigPath);
    }

    void TearDown() override
    {
        DeleteFile(m_ConfigPath);
    }

    void CreateConfigureFile()
    {
        m_Config["resources"] = m_ResourceConfigs;

        CreateFile(m_ConfigPath, m_Config.dump());
    }

    String m_ConfigPath = "test.config.json";
    JSON m_Config = {
        {"root", "C:/Users/Acer"},
        {"title", "Hello World - Heros Card Game"},
        {"screenWidth", 1000},
        {"screenHeight", 600},
    };

    List<JSON> m_ResourceConfigs = {
        {
            {"rid", 2},
            {"relPath", "assets/images/hero.png"},
            {"type", "image"},
        },
        {
            {"rid", 3},
            {"relPath", "assets/images/hero.json"},
            {"type", "json"},
        },
    };
};

TEST_F(ConfigTest, WhenLoadTheValidConfigureFileWithRootComponent_CanGetTheRoot)
{
    auto result = Config::Get<String>("root", "default");

    EXPECT_EQ(result, m_Config["root"].get<String>());
}

TEST_F(ConfigTest, GivenLoadTheValidConfigureFile_WhenAskNonExistedKey_ThenReturnDefault)
{
    auto result = Config::Get<String>("nonExistedKey", "default");

    EXPECT_EQ(result, "default");
}

TEST_F(ConfigTest, GivenLoadTheValidConfigureFile_WhenAskKeyWithDifferentType_ThenReturnDefault)
{
    auto result = Config::Get<int>("title", 100);

    EXPECT_EQ(result, 100);
}

TEST_F(ConfigTest, GivenLoadSucess_WhenAskResourcesKey_ThenReturnsAList)
{
    auto result = Config::GetList("resources");

    EXPECT_GT(result.size(), 0);
}