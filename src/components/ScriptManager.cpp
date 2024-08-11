#include "ScriptManager.hpp"
#include "Script.hpp"

namespace ntt
{
    ScriptManager::ScriptManager()
    {
    }

    ScriptManager::~ScriptManager()
    {
    }

    void ScriptManager::Update(Component *sender, void *data)
    {
        for (auto &script : m_Scripts)
        {
            script->Update(sender, data);
        }
    }

    void ScriptManager::AddScript(Scope<Script> script)
    {
        m_Scripts.push_back(std::move(script));
    }
} // namespace ntt
