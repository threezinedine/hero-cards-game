#include "EntityManager.hpp"
#include <utils/utils.hpp>

namespace ntt
{
    EntityManager::EntityManager(String sceneName)
        : m_SceneName(sceneName)
    {
    }

    EntityManager::~EntityManager()
    {
    }

    void EntityManager::AddEntity(Scope<Entity> entity)
    {
        m_Entities[entity->GetEntityID()] = std::move(entity);
    }

    void EntityManager::Load()
    {
        for (auto &entity : m_Entities)
        {
            entity.second->Load();
        }
    }

    void EntityManager::LoadConfigure(JSON config)
    {
        if (config.is_array())
        {
            for (const auto &enCfg : config)
            {
                if (enCfg.contains("eid") && enCfg["eid"].is_number())
                {
                    if (m_Entities.find(enCfg["eid"]) != m_Entities.end())
                    {
                        m_Entities[enCfg["eid"]]->LoadConfigure(enCfg);
                    }
                }
            }
        }
    }

    void EntityManager::Update(float delta)
    {
        for (auto &entity : m_Entities)
        {
            entity.second->Update(delta);
        }
    }

    void EntityManager::Render()
    {
        for (auto &entity : m_Entities)
        {
            entity.second->Render();
        }
    }

    void EntityManager::Unload()
    {
        for (auto &entity : m_Entities)
        {
            entity.second->Unload();
        }
    }
} // namespace ntt
