#include "Game.hpp"
#include <inputs/MouseInput.hpp>
#include <utils/utils.hpp>
#include <common.hpp>

Game::Game()
    : m_CurrentSceneIndex(-1)
{
    m_Scenes.push_back(CreateScope<HomeScene>());
    m_Scenes.push_back(CreateScope<GameScene>());

    m_Scenes[0]->SetApplication(this);
    m_Scenes[1]->SetApplication(this);

    ChangeScene(0);
}

Game::~Game()
{
    m_Scenes[m_CurrentSceneIndex]->Release();
}

void Game::ChangeScene(int index)
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

void Game::UpdateImpl(float delta)
{
    if (m_CurrentSceneIndex >= 0 && m_CurrentSceneIndex < m_Scenes.size())
    {
        m_Scenes[m_CurrentSceneIndex]->Update(delta);
    }
}

void Game::RenderImpl()
{
    if (m_CurrentSceneIndex >= 0 && m_CurrentSceneIndex < m_Scenes.size())
    {
        m_Scenes[m_CurrentSceneIndex]->Render();
    }
}