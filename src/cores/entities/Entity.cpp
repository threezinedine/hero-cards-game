#include "Entity.hpp"
#include <cores/scripts/IScript.hpp>
#include <cores/scripts/ScriptManager.hpp>

namespace ntt
{
    Entity::Entity(eid_t entityId)
        : m_EntityID(entityId)
    {
        m_Geometry = CreateRef<Geometry>();
        m_ScriptManager = CreateRef<ScriptManager>();
        m_ScriptManager->SetSender(this);
    }

    Entity::~Entity()
    {
    }

    void Entity::Load()
    {
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
        if (config.is_object())
        {
            if (config.contains("geometry") && config["geometry"].is_object())
            {
                m_Geometry->LoadConfigure(config["geometry"]);
            }

            // if (config.contains("scripts") && config["scripts"].is_array())
            // {
            //     auto configScripts = config["scripts"];

            //     for (const auto &configScript : configScripts)
            //     {
            //         if (configScript.contains("sid") && configScript["sid"].is_number())
            //         {
            //             auto sid = configScript["sid"];
            //             if (m_Scripts.find(sid) != m_Scripts.end())
            //             {
            //                 m_Scripts[sid]->LoadConfigure(configScript);
            //             }
            //         }
            //     }
            // }
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