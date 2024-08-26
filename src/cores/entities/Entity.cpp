#include "Entity.hpp"
#include <cores/scripts/IScript.hpp>
#include <cores/scripts/ScriptManager.hpp>
#include <utils/log/log.hpp>

namespace ntt
{
    Entity::Entity(eid_t entityId)
        : m_EntityID(entityId)
    {
        FUNCTION_LOG();
        m_Geometry = CreateRef<Geometry>();
        m_ScriptManager = CreateRef<ScriptManager>();
        m_ScriptManager->SetSender(this);
    }

    Entity::~Entity()
    {
        FUNCTION_LOG();
    }

    void Entity::Load()
    {
        FUNCTION_LOG();
        LoadImpl();

        m_ScriptManager->Load();
    }

    void Entity::LoadImpl()
    {
    }

    void Entity::Update(float delta)
    {
        UpdateImpl(delta);

        m_ScriptManager->Update(delta);
    }

    void Entity::UpdateImpl(float delta)
    {
    }

    void Entity::LoadConfigure(ConfigurableObject &config)
    {
        FUNCTION_LOG_P("Entity ID: %d", m_EntityID);
        auto geometry = config.Get<ConfigurableObject>("geometry");
        m_Geometry->LoadConfigure(geometry);
        m_ScriptManager->LoadConfigure(config.GetList<ConfigurableObject>("scripts"));
    }

    void Entity::Unload()
    {
        UnloadImpl();

        m_ScriptManager->Unload();
    }

    void Entity::UnloadImpl()
    {
    }
} // namespace ntt::entity