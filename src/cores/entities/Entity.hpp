#pragma once
#include <cores/commons/common.hpp>
#include <cores/commons/datatypes.hpp>
#include "Geometry.hpp"
#include <cores/scripts/scripts.hpp>
#include <cores/interfaces/IConfigurable.hpp>
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IRenderable.hpp>

namespace ntt
{
    class Entity : public IRenderable, public Loadable, public IConfigurable
    {
    public:
        Entity(eid_t entityId);
        virtual ~Entity();

        inline Ref<Geometry> GetGeometry() { return m_Geometry; }
        inline eid_t GetEntityID() const { return m_EntityID; }

        void Load() override;
        void Update(float delta) override;
        void Render() override;
        void Unload() override;

        void LoadConfigure(JSON config) override;

        void AddScript(Scope<Script> script);

        inline bool IsLoaded() const override { return true; }

    protected:
        virtual void LoadImpl();
        virtual void UpdateImpl(float delta);
        virtual void RenderImpl();
        virtual void UnloadImpl();
        virtual void LoadConfigureImpl(JSON config);

    private:
        Ref<Geometry> m_Geometry;
        eid_t m_EntityID;
        Map<sid_t, Scope<Script>> m_Scripts;
    };
} // namespace ntt
