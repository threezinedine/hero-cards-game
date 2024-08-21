#pragma once
#include "IScript.hpp"

namespace ntt
{
    class IEntity;

    class Script : public IScript
    {
    public:
        Script(sid_t scriptId);
        Script(sid_t scriptId, IEntity *entity);
        virtual ~Script();

        void Load() override;
        void Update(void *sender, float delta) override;
        void Unload() override;

        void LoadConfigure(ConfigurableObject &config) override;

        inline sid_t GetScriptID() const override { return m_ScriptID; }

    protected:
        virtual void LoadImpl();
        virtual void UpdateImpl(void *sender, float delta);
        virtual void UnloadImpl();

        virtual void LoadConfigureImpl(ConfigurableObject &config);

    private:
        sid_t m_ScriptID;
    };
} // namespace ntt
