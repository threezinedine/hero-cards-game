#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Scene.hpp"

using namespace ntt;

class SceneMock : public Scene
{
public:
    SceneMock(const String &name) : Scene(name) {}
    ~SceneMock() {}

protected:
    void LoadImpl() override { LoadImplCallCount++; }
    void UpdateImpl(float delta) override { UpdateImplCallCount++; }
    void UnloadImpl() override { UnloadImplCallCount++; }

    void LoadConfigureImpl(JSON config) override
    {
    }

public:
    int LoadImplCallCount = 0;
    int UpdateImplCallCount = 0;
    int UnloadImplCallCount = 0;
};

class SceneTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_Scene = CreateScope<SceneMock>("TestScene");
    }

    void TearDown() override
    {
    }

    Scope<SceneMock> m_Scene;
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