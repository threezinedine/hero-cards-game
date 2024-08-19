#include "EntityManager.hpp"
#include <utils/utils.hpp>
#include "IEntity.hpp"

namespace ntt
{
    EntityManager::EntityManager(String sceneName)
        : m_SceneName(sceneName)
    {
        FUNCTION_LOG();
    }

    EntityManager::~EntityManager()
    {
        FUNCTION_LOG();
    }

    void EntityManager::AddEntity(Scope<IEntity> entity)
    {
        FUNCTION_LOG();
        m_Entities[entity->GetEntityID()] = std::move(entity);
    }

    void EntityManager::Load()
    {
        FUNCTION_LOG();
        for (auto &entity : m_Entities)
        {
            entity.second->Load();
        }
    }

    void EntityManager::LoadConfigure(JSON config)
    {
        FUNCTION_LOG();
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

    void EntityManager::Unload()
    {
        FUNCTION_LOG();
        for (auto &entity : m_Entities)
        {
            entity.second->Unload();
        }
    }
} // namespace ntt
