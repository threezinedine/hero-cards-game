#include "Scene.hpp"
#include <utils/utils.hpp>
#include <cores/resources/ResourceManager.hpp>

namespace ntt
{
    Scene::Scene(String sceneName)
        : m_SceneManagement(nullptr), m_SceneName(sceneName)
    {
        // m_ComponentManagement = CreateScope<ComponentManagement>(sceneName);
        m_ResourceManager = CreateRef<ResourceManager>(sceneName);
        m_EntityManager = CreateRef<EntityManager>(sceneName);
    }

    Scene::~Scene()
    {
    }

    void Scene::Load()
    {
        m_Loaded = true;
        GetResourceManager()->Load();
        GetEntityManager()->Load();

        LoadImpl();
    }

    void Scene::LoadImpl()
    {
    }

    void Scene::Update(float delta)
    {
        m_EntityManager->Update(delta);
        UpdateImpl(delta);
        // m_ComponentManagement->Update(delta);
    }

    void Scene::UpdateImpl(float delta)
    {
    }

    void Scene::Render()
    {
        m_EntityManager->Render();
        RenderImpl();
        // m_ComponentManagement->Render();
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