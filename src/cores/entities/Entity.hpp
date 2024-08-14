#pragma once
#include <cores/commons/common.hpp>
#include <cores/commons/datatypes.hpp>
#include "Geometry.hpp"
#include <cores/interfaces/interfaces.hpp>
#include <cores/scripts/scripts.hpp>

namespace ntt
{
    class Entity : public IRenderable, public ILoadable, public IConfigurable
    {
    public:
        Entity(eid_t entityId, rid_t resourId);
        virtual ~Entity();

        inline Geometry &GetGeometry() { return m_Geometry; }
        inline eid_t GetEntityID() const { return m_EntityID; }
        inline rid_t GetResourceID() const { return m_ResourceID; }

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
        Geometry m_Geometry;
        eid_t m_EntityID;
        rid_t m_ResourceID;
        Map<sid_t, Scope<Script>> m_Scripts;
    };
} // namespace ntt
