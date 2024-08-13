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

        if (config.contains("scripts") && config["scripts"].is_array())
        {
            auto configScripts = config["scripts"];

            for (const auto &configScript : configScripts)
            {
                if (configScript.contains("sid") && configScript["sid"].is_number())
                {
                    auto sid = configScript["sid"];
                    m_Scripts[sid]->LoadConfigure(configScript);
                }
            }
        }
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

} // namespace ntt::entity