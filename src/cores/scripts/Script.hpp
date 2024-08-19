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
        void Update(float delta) override;
        void Unload() override;

        void LoadConfigure(JSON config) override;

        inline sid_t GetScriptID() const override { return m_ScriptID; }
        inline void SetEntity(IEntity *entity) override { m_Entity = entity; }

    protected:
        virtual void LoadImpl();
        virtual void UpdateImpl(float delta);
        virtual void UnloadImpl();

        virtual void LoadConfigureImpl(JSON config);

        inline IEntity *GetEntity() const { return m_Entity; }

    private:
        sid_t m_ScriptID;
        IEntity *m_Entity;
    };
} // namespace ntt
