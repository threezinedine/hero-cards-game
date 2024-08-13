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
        m_Entities.push_back(std::move(entity));
    }

    void EntityManager::Load()
    {
        auto config = Config::GetEntitiesMapOfScene(m_SceneName);

        for (auto &entity : m_Entities)
        {
            DEBUG_POINT();
            if (config.find(entity->GetEntityID()) == config.end())
            {
                continue;
            }
            DEBUG_POINT();
            entity->LoadConfigure(config[entity->GetEntityID()]);
        }

        for (auto &entity : m_Entities)
        {
            entity->Load();
        }
    }

    void EntityManager::Update(float delta)
    {
        for (auto &entity : m_Entities)
        {
            entity->Update(delta);
        }
    }

    void EntityManager::Render()
    {
        for (auto &entity : m_Entities)
        {
            entity->Render();
        }
    }

    void EntityManager::Unload()
    {
        for (auto &entity : m_Entities)
        {
            entity->Unload();
        }
    }
} // namespace ntt
