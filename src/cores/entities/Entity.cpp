#include "Entity.hpp"

namespace ntt
{
    Entity::Entity(eid_t entityId, rid_t resourceId)
        : m_EntityID(entityId), m_ResourceID(resourceId)
    {
    }

    Entity::~Entity()
    {
    }

    void Entity::Update(float delta)
    {
        UpdateImpl(delta);
    }

    void Entity::UpdateImpl(float delta)
    {
    }

    void Entity::LoadConfigure(JSON config)
    {
        if (config.contains("rid") && config["rid"].is_number())
        {
            m_ResourceID = config["rid"];
        }

        if (config.contains("geometry") && config["geometry"].is_object())
        {
            m_Geometry.LoadConfigure(config["geometry"]);
        }
    }

    void Entity::Render()
    {
        RenderImpl();
    }

    void Entity::RenderImpl()
    {
    }

} // namespace ntt::entity