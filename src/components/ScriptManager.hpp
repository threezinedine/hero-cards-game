#pragma once

#include <common.hpp>
#include <cores/core.hpp>

namespace ntt
{
    class Script;
    class Component;

    class ScriptManager
    {
    public:
        ScriptManager();
        ~ScriptManager();

        void Update(Component *sender, void *data);
        void AddScript(Scope<Script> script);

    private:
        List<Scope<Script>> m_Scripts;
    };
} // namespace ntt
