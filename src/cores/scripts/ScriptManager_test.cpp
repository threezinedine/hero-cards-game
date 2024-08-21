#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "IScript.hpp"
#include "ScriptManager.hpp"
#include <cores/entities/Entity.hpp>
#include "MockScript.hpp"
#include <cores/resources/MockResource.hpp>

using namespace ntt;

class ScriptManagerTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_ScriptManager = CreateRef<ScriptManager>();
        m_Script = CreateRef<MockScript>();
        m_Entity = CreateRef<Entity>(1);
    }

    void TearDown() override
    {
    }

    void SetupScript()
    {
        m_Script->SetScriptID(1);
        m_ScriptManager->AddScript(m_Script);
    }

    void SetupEntity()
    {
        m_ScriptManager->SetSender(m_Entity.get());
    }

    Ref<Entity> m_Entity;
    Ref<MockScript> m_Script;
    Ref<ScriptManager> m_ScriptManager;
};

TEST_F(ScriptManagerTest, AddScript_Load_ScriptIsLoaded)
{
    SetupScript();

    EXPECT_CALL(*m_Script, Load()).Times(1);
    m_ScriptManager->Load();
}

TEST_F(ScriptManagerTest, AddScript_Update_ScriptIsUpdated)
{
    float delta = 3.0f;
    SetupScript();
    SetupEntity();

    EXPECT_CALL(*m_Script, Update(m_Entity.get(), delta)).Times(1);

    m_ScriptManager->Update(delta);
}

TEST_F(ScriptManagerTest, AddScript_Unload_ScriptIsUnloaded)
{
    SetupScript();

    EXPECT_CALL(*m_Script, Unload()).Times(1);
    m_ScriptManager->Unload();
}