#include "ScriptManager.hpp"
#include "IScript.hpp"
#include <utils/log/log.hpp>
#include <utils/configuration/ConfigurableObject.hpp>

namespace ntt
{
    ScriptManager::ScriptManager()
    {
    }

    ScriptManager::~ScriptManager()
    {
    }

    void ScriptManager::AddScript(Ref<IScript> script)
    {
        FUNCTION_LOG();
        m_Scripts[script->GetScriptID()] = script;
    }

    void ScriptManager::Load()
    {
        FUNCTION_LOG();
        for (auto &script : m_Scripts)
        {
            script.second->Load();
        }
    }

    void ScriptManager::Update(float delta)
    {
        for (auto &script : m_Scripts)
        {
            script.second->Update(m_Sender, delta);
        }
    }

    void ScriptManager::Unload()
    {
        FUNCTION_LOG();
        for (auto &script : m_Scripts)
        {
            script.second->Unload();
        }
    }

    void ScriptManager::LoadConfigure(List<ConfigurableObject> configs)
    {
        FUNCTION_LOG();
        for (auto &config : configs)
        {
            if (sid_t sid = config.Get<sid_t>("sid", INVALID_SID); sid != INVALID_SID)
            {
                if (m_Scripts.find(sid) != m_Scripts.end())
                {
                    m_Scripts[sid]->LoadConfigure(config);
                }
            }
        }
    }
} // namespace ntt
