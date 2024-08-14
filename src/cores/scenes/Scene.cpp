#include "Scene.hpp"
#include <utils/utils.hpp>
#include <cores/resources/ResourceManager.hpp>

namespace ntt
{
    Scene::Scene(String sceneName)
        : m_SceneManager(nullptr), m_SceneName(sceneName)
    {
        m_ResourceManager = CreateRef<ResourceManager>(sceneName);
        m_EntityManager = CreateRef<EntityManager>(sceneName);
    }

    Scene::~Scene()
    {
    }

    void Scene::Load()
    {
        m_Loaded = true;
        LoadConfigure(Config::GetSceneData(m_SceneName));

        GetResourceManager()->Load();
        GetEntityManager()->Load();

        LoadImpl();
    }

    void Scene::LoadConfigure(JSON config)
    {
        LoadConfigureImpl(config);
        GetResourceManager()->LoadConfigure(config);
        GetEntityManager()->LoadConfigure(config);
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
        UnloadImpl();
        m_Loaded = false;
    }

    void Scene::UnloadImpl()
    {
    }
}