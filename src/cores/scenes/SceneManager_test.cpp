#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "SceneManager.hpp"
#include "IScene.hpp"
#include <utils/configuration/ConfigurableObject.hpp>

using namespace ntt;

class MockScene : public IScene
{
public:
    inline const String &GetSceneName() const override { return m_SceneName; };
    inline void SetSceneName(const String &name) { m_SceneName = name; };
    inline void SetSceneManager(ISceneManager *sceneManager) override { m_SceneManager = sceneManager; };
    inline void AddScript(Ref<IScript> script) override {};

    MOCK_METHOD(void, Load, ());
    MOCK_METHOD(void, Update, (float));
    MOCK_METHOD(void, Unload, ());
    MOCK_METHOD(void, LoadConfigure, (ConfigurableObject &), (override));

private:
    String m_SceneName;
    ISceneManager *m_SceneManager;
};

class SceneManagerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_SceneManager = CreateScope<SceneManager>();
        m_Scene = CreateRef<MockScene>();
        m_Scene->SetSceneName("TestScene");

        m_Scene2 = CreateRef<MockScene>();
        m_Scene2->SetSceneName("TestScene2");
    }

    Ref<MockScene> m_Scene;
    Ref<MockScene> m_Scene2;
    Scope<SceneManager> m_SceneManager;
};

TEST_F(SceneManagerTest, AddScene_Load_SceneIsLoaded)
{
    EXPECT_CALL(*m_Scene, Load()).Times(1);
    EXPECT_CALL(*m_Scene2, Load()).Times(0);
    m_SceneManager->AddScene(m_Scene);
    m_SceneManager->AddScene(m_Scene2);
}

TEST_F(SceneManagerTest, ChangeScene_Load_SceneIsChanged)
{
    EXPECT_CALL(*m_Scene, Load()).Times(1);
    EXPECT_CALL(*m_Scene2, Load()).Times(1);
    m_SceneManager->AddScene(m_Scene);
    m_SceneManager->AddScene(m_Scene2);

    m_SceneManager->ChangeScene(m_Scene2->GetSceneName());
}

TEST_F(SceneManagerTest, DoesNotReloadIfSceneIsAllreadyLoaded)
{
    EXPECT_CALL(*m_Scene, Load()).Times(1);
    m_SceneManager->AddScene(m_Scene);
    m_SceneManager->AddScene(m_Scene2);

    m_SceneManager->ChangeScene(m_Scene->GetSceneName());
}

TEST_F(SceneManagerTest, NoErrorWhenChangeSceneToNonExistingScene)
{
    EXPECT_CALL(*m_Scene, Load()).Times(1);
    EXPECT_CALL(*m_Scene2, Load()).Times(0);
    m_SceneManager->AddScene(m_Scene);
    m_SceneManager->AddScene(m_Scene2);

    EXPECT_NO_THROW(m_SceneManager->ChangeScene("NonExistingScene"));
}

TEST_F(SceneManagerTest, WhenAdd2SceneWithSameName_OnlyTheFirstOneIsAdded)
{
    EXPECT_CALL(*m_Scene, Load()).Times(1);
    m_SceneManager->AddScene(m_Scene);
    m_SceneManager->AddScene(m_Scene2);
    m_SceneManager->AddScene(m_Scene);

    m_SceneManager->ChangeScene(m_Scene->GetSceneName());
}