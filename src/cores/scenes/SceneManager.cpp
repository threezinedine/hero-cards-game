#include "SceneManager.hpp"
#include "Scene.hpp"

namespace ntt
{
    SceneManager::SceneManager()
        : m_CurrentSceneIndex(-1)
    {
    }

    SceneManager::~SceneManager()
    {
        for (auto &scene : m_Scenes)
        {
            if (scene->IsLoaded())
            {
                scene->Unload();
            }
        }
    }

    void SceneManager::AddScene(Scope<Scene> scene)
    {
        scene->SetSceneManager(this);
        m_Scenes.push_back(std::move(scene));

        if (m_Scenes.size() == 1)
        {
            ChangeScene(0);
        }
    }

    void SceneManager::Update(float delta)
    {
        if (m_CurrentSceneIndex != -1)
        {
            m_Scenes[m_CurrentSceneIndex]->Update(delta);
        }
    }

    void SceneManager::Render()
    {
        if (m_CurrentSceneIndex != -1)
        {
            m_Scenes[m_CurrentSceneIndex]->Render();
        }
    }

    void SceneManager::ChangeScene(int index)
    {
        if (index < 0 || index >= m_Scenes.size())
        {
            return;
        }
        else
        {
            if (m_CurrentSceneIndex != index)
            {
                if (m_CurrentSceneIndex >= 0 &&
                    m_CurrentSceneIndex < m_Scenes.size() &&
                    m_Scenes[m_CurrentSceneIndex]->IsLoaded())
                {
                    m_Scenes[m_CurrentSceneIndex]->Unload();
                }

                if (!m_Scenes[index]->IsLoaded())
                {
                    m_Scenes[index]->Load();
                }
            }

            m_CurrentSceneIndex = index;
        }
    }
}