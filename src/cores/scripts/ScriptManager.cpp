#include "ScriptManager.hpp"
#include "IScript.hpp"
#include <utils/log/log.hpp>

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

    void ScriptManager::LoadConfigure(JSON config)
    {
        FUNCTION_LOG();
        if (config.is_array())
        {
            for (const auto &cfg : config)
            {
                if (cfg.contains("sid") && cfg["sid"].is_number())
                {
                    sid_t sid = cfg["sid"];
                    if (m_Scripts.find(sid) != m_Scripts.end())
                    {
                        m_Scripts[sid]->LoadConfigure(cfg);
                    }
                }
            }
        }
    }
} // namespace ntt
