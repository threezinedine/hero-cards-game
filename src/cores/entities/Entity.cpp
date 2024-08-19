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

    void Entity::LoadConfigure(JSON config)
    {
        FUNCTION_LOG();
        if (config.is_object())
        {
            if (config.contains("geometry") && config["geometry"].is_object())
            {
                m_Geometry->LoadConfigure(config["geometry"]);
            }

            if (config.contains("scripts"))
            {
                m_ScriptManager->LoadConfigure(config["scripts"]);
            }

            LoadConfigureImpl(config);
        }
    }

    void Entity::LoadConfigureImpl(JSON config)
    {
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