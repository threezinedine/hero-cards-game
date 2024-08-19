#include "SceneManager.hpp"
#include "Scene.hpp"
#include <utils/configuration/configutation.hpp>
#include <utils/log/log.hpp>

namespace ntt
{
    SceneManager::SceneManager()
        : m_CurrentScene(nullptr)
    {
        FUNCTION_LOG();
    }

    SceneManager::~SceneManager()
    {
        FUNCTION_LOG();
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
        FUNCTION_LOG();
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
        FUNCTION_LOG();
        if (m_Scenes.find(sceneName) != m_Scenes.end())
        {
            if (m_CurrentScene == nullptr)
            {
                m_CurrentScene = m_Scenes[sceneName];
                if (!m_CurrentScene->IsLoaded())
                {
                    m_CurrentScene->Load();
                }
            }
            else
            {
                if (m_CurrentScene->IsLoaded())
                {
                    m_CurrentScene->Unload();
                }

                m_CurrentScene = m_Scenes[sceneName];
                if (!m_CurrentScene->IsLoaded())
                {
                    m_CurrentScene->Load();
                }
            }
        }
    }
}