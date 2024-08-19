#include "SceneManager.hpp"
#include "Scene.hpp"
#include <utils/configuration/configutation.hpp>

namespace ntt
{
    SceneManager::SceneManager()
        : m_CurrentScene(nullptr)
    {
    }

    SceneManager::~SceneManager()
    {
        for (auto &scene : m_Scenes)
        {
            if (scene.second->IsLoaded())
            {
                scene.second->Unload();
            }
        }
    }

    void SceneManager::AddScene(Ref<IScene> scene)
    {
        scene->SetSceneManager(this);
        m_Scenes[scene->GetSceneName()] = scene;

        if (m_Scenes.size() == 1)
        {
            ChangeScene(scene->GetSceneName());
        }
    }

    void SceneManager::Update(float delta)
    {
        m_CurrentScene->Update(delta);
    }

    void SceneManager::ChangeScene(String sceneName)
    {
        DEBUG_POINT();
        if (m_Scenes.find(sceneName) != m_Scenes.end())
        {
            DEBUG_POINT();
            if (m_CurrentScene == nullptr)
            {
                DEBUG_POINT();
                m_CurrentScene = m_Scenes[sceneName];
                DEBUG_POINT();
                if (!m_CurrentScene->IsLoaded())
                {
                    DEBUG_POINT();
                    m_CurrentScene->Load();
                    DEBUG_POINT();
                }
            }
            else
            {
                DEBUG_POINT();
                if (m_CurrentScene->IsLoaded())
                {
                    DEBUG_POINT();
                    m_CurrentScene->Unload();
                    DEBUG_POINT();
                }

                DEBUG_POINT();
                m_CurrentScene = m_Scenes[sceneName];
                DEBUG_POINT();
                if (!m_CurrentScene->IsLoaded())
                {
                    DEBUG_POINT();
                    m_CurrentScene->Load();
                    DEBUG_POINT();
                }
            }
        }
    }
}