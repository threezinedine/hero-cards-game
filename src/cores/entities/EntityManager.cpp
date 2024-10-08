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

    void EntityManager::LoadConfigure(List<ConfigurableObject> configs)
    {
        FUNCTION_LOG();
        for (auto &config : configs)
        {
            if (eid_t eid = config.Get<rid_t>("eid", INVALID_EID); eid != INVALID_EID)
            {
                if (m_Entities.find(eid) != m_Entities.end())
                {
                    m_Entities[eid]->LoadConfigure(config);
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
