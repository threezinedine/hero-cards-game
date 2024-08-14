#include "Scene.hpp"
#include <utils/utils.hpp>
#include <cores/resources/ResourceManager.hpp>

namespace ntt
{
    Scene::Scene(String sceneName)
        : m_SceneManager(nullptr), m_SceneName(sceneName)
    {
        m_ResourceManager = CreateRef<ResourceManager>();
        m_EntityManager = CreateRef<EntityManager>(sceneName);
    }

    Scene::~Scene()
    {
    }

    void Scene::Load()
    {
        SetIsLoaded(true);
        LoadConfigure(Config::GetSceneData(m_SceneName));

        GetResourceManager()->Load();
        GetEntityManager()->Load();

        LoadImpl();
    }

    void Scene::LoadConfigure(JSON config)
    {
        if (config.is_object())
        {
            LoadConfigureImpl(config);

            if (config.contains("resources"))
            {
                GetResourceManager()->LoadConfigure(config["resources"]);
            }
            if (config.contains("entities"))
            {
                GetEntityManager()->LoadConfigure(config["entities"]);
            }
        }
    }

    void Scene::LoadConfigureImpl(JSON config)
    {
    }

    void Scene::LoadImpl()
    {
    }

    void Scene::Update(float delta)
    {
        m_EntityManager->Update(delta);
        UpdateImpl(delta);
    }

    void Scene::UpdateImpl(float delta)
    {
    }

    void Scene::Render()
    {
        m_EntityManager->Render();
        RenderImpl();
    }

    void Scene::RenderImpl()
    {
    }

    void Scene::Unload()
    {
        GetResourceManager()->Unload();
        GetEntityManager()->Unload();
        UnloadImpl();
        SetIsLoaded(false);
    }

    void Scene::UnloadImpl()
    {
    }
}