#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Scene.hpp"
#include "cores/scripts/Script.hpp"

using namespace ntt;

class TestScript : public Script
{
public:
    TestScript(sid_t scriptId) : Script(scriptId) {}
    ~TestScript() {}

    int LoadCount = 0;
    int UpdateCount = 0;
    int UnloadCount = 0;

protected:
    void LoadImpl() override { LoadCount++; }
    void UpdateImpl(float delta) override { UpdateCount++; }
    void UnloadImpl() override { UnloadCount++; }
};

class SceneTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_Scene = CreateScope<Scene>("TestScene");
    }

    void TearDown() override
    {
    }

    Scope<IScene> m_Scene;
};

TEST_F(SceneTest, TestSceneConstructor)
{
    EXPECT_EQ(m_Scene->GetSceneName(), "TestScene");
}

TEST_F(SceneTest, TestSceneLoad)
{
    EXPECT_FALSE(m_Scene->IsLoaded());

    m_Scene->Load();

    EXPECT_TRUE(m_Scene->IsLoaded());
}

TEST_F(SceneTest, WhenAddingScriptToScene_ThenScriptIsLoaded)
{
    auto script = CreateRef<TestScript>(1);
    m_Scene->AddScript(script);

    m_Scene->Load();

    EXPECT_EQ(script->LoadCount, 1);
}