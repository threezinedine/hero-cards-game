#include "SceneManagement.hpp"
#include "Scene.hpp"

namespace ntt
{
    SceneManagement::SceneManagement()
        : m_CurrentSceneIndex(-1)
    {
    }

    SceneManagement::~SceneManagement()
    {
        for (auto &scene : m_Scenes)
        {
            if (scene->IsInitialized())
            {
                scene->Release();
            }
        }
    }

    void SceneManagement::AddScene(Scope<Scene> scene)
    {
        scene->SetSceneManagement(this);
        m_Scenes.push_back(std::move(scene));

        if (m_Scenes.size() == 1)
        {
            ChangeScene(0);
        }
    }

    void SceneManagement::Update(float delta)
    {
        if (m_CurrentSceneIndex != -1)
        {
            m_Scenes[m_CurrentSceneIndex]->Update(delta);
        }
    }

    void SceneManagement::Render()
    {
        if (m_CurrentSceneIndex != -1)
        {
            m_Scenes[m_CurrentSceneIndex]->Render();
        }
    }

    void SceneManagement::ChangeScene(int index)
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
                    m_Scenes[m_CurrentSceneIndex]->IsInitialized())
                {
                    m_Scenes[m_CurrentSceneIndex]->Release();
                }

                if (!m_Scenes[index]->IsInitialized())
                {
                    m_Scenes[index]->Init();
                }
            }

            m_CurrentSceneIndex = index;
        }
    }
}