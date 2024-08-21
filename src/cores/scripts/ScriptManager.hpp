#pragma once
#include <cores/commons/common.hpp>
#include "IScriptManager.hpp"

namespace ntt
{
    class IScript;

    class ScriptManager : public IScriptManager
    {
    public:
        ScriptManager();
        virtual ~ScriptManager();

        void Load() override;
        void Update(float delta) override;
        void Unload() override;

        void LoadConfigure(List<ConfigurableObject> configs);

        void AddScript(Ref<IScript> script) override;
        inline void SetSender(void *sender) override { m_Sender = sender; }

    private:
        Map<sid_t, Ref<IScript>> m_Scripts;
        void *m_Sender;
    };
} // namespace name
