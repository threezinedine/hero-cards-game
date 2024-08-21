#pragma once
#include <cores/commons/common.hpp>
#include <cores/commons/datatypes.hpp>
#include "Geometry.hpp"
#include "IEntity.hpp"
#include <cores/scripts/IScriptManager.hpp>

namespace ntt
{
    class Entity : public IEntity
    {
    public:
        Entity(eid_t entityId);
        virtual ~Entity();

        inline Ref<Geometry> GetGeometry() override { return m_Geometry; }
        inline eid_t GetEntityID() const override { return m_EntityID; }

        void Load() override;
        void Update(float delta) override;
        void Unload() override;

        void LoadConfigure(ConfigurableObject &object) override;

        void AddScript(Ref<IScript> script) override { m_ScriptManager->AddScript(script); }

    protected:
        virtual void LoadImpl();
        virtual void UpdateImpl(float delta);
        virtual void UnloadImpl();

    private:
        Ref<Geometry> m_Geometry;
        eid_t m_EntityID;
        // Map<sid_t, Scope<IScript>> m_Scripts;
        Ref<IScriptManager> m_ScriptManager;
    };
} // namespace ntt
