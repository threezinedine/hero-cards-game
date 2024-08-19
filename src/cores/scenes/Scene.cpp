#include "Scene.hpp"
#include <utils/utils.hpp>
#include <cores/resources/ResourceManager.hpp>
#include "ISceneManager.hpp"
#include <cores/entities/EntityManager.hpp>
#include <cores/scripts/ScriptManager.hpp>

namespace ntt
{
    Scene::Scene(String sceneName)
        : m_SceneManager(nullptr), m_SceneName(sceneName)
    {
        m_ResourceManager = CreateRef<ResourceManager>();
        m_EntityManager = CreateRef<EntityManager>(sceneName);
        m_ScriptManager = CreateRef<ScriptManager>();
    }

    Scene::~Scene()
    {
    }

    void Scene::AddScript(Ref<IScript> script)
    {
        m_ScriptManager->AddScript(script);
    }

    void Scene::Load()
    {
        SetIsLoaded(true);
        LoadConfigure(Config::GetSceneData(m_SceneName));

        GetResourceManager()->Load();
        GetEntityManager()->Load();
        m_ScriptManager->Load();

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
        m_ScriptManager->Update(delta);
        UpdateImpl(delta);
    }

    void Scene::UpdateImpl(float delta)
    {
    }

    void Scene::Unload()
    {
        GetResourceManager()->Unload();
        GetEntityManager()->Unload();
        m_ScriptManager->Unload();
        UnloadImpl();
        SetIsLoaded(false);
    }

    void Scene::UnloadImpl()
    {
    }
}