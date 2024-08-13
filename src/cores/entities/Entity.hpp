#pragma once
#include <common.hpp>
#include <cores/datatypes.hpp>
#include "Geometry.hpp"
#include <cores/IRenderable.hpp>
#include <cores/scripts/scripts.hpp>

namespace ntt
{
    class Entity : public IRenderable
    {
    public:
        Entity(eid_t entityId, rid_t resourId);
        virtual ~Entity();

        inline const Geometry &GetGeometry() const { return m_Geometry; }
        inline eid_t GetEntityID() const { return m_EntityID; }
        inline rid_t GetResourceID() const { return m_ResourceID; }

        void Update(float delta) override;
        void Render() override;

        void LoadConfigure(JSON config);

        void AddScript(Scope<Script> script);

    protected:
        virtual void UpdateImpl(float delta);
        virtual void RenderImpl();

    private:
        Geometry m_Geometry;
        eid_t m_EntityID;
        rid_t m_ResourceID;
        Map<sid_t, Scope<Script>> m_Scripts;
    };
} // namespace ntt
