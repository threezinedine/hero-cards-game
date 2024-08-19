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
        FUNCTION_LOG();
        m_ResourceManager = CreateRef<ResourceManager>();
        m_EntityManager = CreateRef<EntityManager>(sceneName);
        m_ScriptManager = CreateRef<ScriptManager>();
    }

    Scene::~Scene()
    {
        FUNCTION_LOG();
    }

    void Scene::AddScript(Ref<IScript> script)
    {
        FUNCTION_LOG();
        m_ScriptManager->AddScript(script);
    }

    void Scene::Load()
    {
        FUNCTION_LOG();
        SetIsLoaded(true);
        LoadConfigure(Config::GetSceneData(m_SceneName));

        GetResourceManager()->Load();
        GetEntityManager()->Load();
        m_ScriptManager->Load();

        LoadImpl();
    }

    void Scene::LoadConfigure(JSON config)
    {
        FUNCTION_LOG();
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
        FUNCTION_LOG();
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