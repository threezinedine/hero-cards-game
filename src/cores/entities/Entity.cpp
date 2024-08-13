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

    void Entity::Load()
    {
        LoadImpl();

        for (const auto &script : m_Scripts)
        {
            script.second->Load();
        }
    }

    void Entity::LoadImpl()
    {
    }

    void Entity::Update(float delta)
    {
        UpdateImpl(delta);

        for (const auto &script : m_Scripts)
        {
            script.second->Update(delta);
        }
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

        DEBUG_POINT();
        if (config.contains("scripts") && config["scripts"].is_array())
        {
            DEBUG_POINT();
            auto configScripts = config["scripts"];

            DEBUG_POINT();
            for (const auto &configScript : configScripts)
            {
                DEBUG_POINT();
                if (configScript.contains("sid") && configScript["sid"].is_number())
                {
                    DEBUG_POINT();
                    auto sid = configScript["sid"];
                    if (m_Scripts.find(sid) != m_Scripts.end())
                    {
                        DEBUG_POINT();
                        std::cout << "config: " << configScript << std::endl;
                        m_Scripts[sid]->LoadConfigure(configScript);
                    }
                }
            }
        }
        DEBUG_POINT();
    }

    void Entity::AddScript(Scope<Script> script)
    {
        script->SetEntity(this);
        m_Scripts[script->GetScriptID()] = std::move(script);
    }

    void Entity::Render()
    {
        RenderImpl();

        for (const auto &script : m_Scripts)
        {
            script.second->Render();
        }
    }

    void Entity::RenderImpl()
    {
    }

    void Entity::Unload()
    {
        UnloadImpl();

        for (const auto &script : m_Scripts)
        {
            script.second->Unload();
        }
    }

    void Entity::UnloadImpl()
    {
    }
} // namespace ntt::entity