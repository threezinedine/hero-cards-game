#include "GameScene.hpp"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::InitImpl()
{
    m_Enemies.push_back(Enemy::SpawnRandomly());
    m_SpawnTimer.Reset();
    m_ScoreText = CreateScope<Text>("Score: 0", 20, 20, 40);
}

void GameScene::UpdateImpl(float delta)
{
    UpdateEnemies(delta);
    SpawnEnemy();
}

void GameScene::UpdateEnemies(float delta)
{
    for (const auto &enemy : m_Enemies)
    {
        enemy->Update(delta);

        if (!enemy->IsAlive())
        {
            m_Enemies.erase(std::remove(m_Enemies.begin(), m_Enemies.end(), enemy),
                            m_Enemies.end());
            m_Score++;
            m_ScoreText->SetText("Score: " + std::to_string(m_Score));
            break;
        }
    }
}

void GameScene::SpawnEnemy()
{
    if (m_SpawnTimer.GetDelta() >= 0.5f && m_Enemies.size() < 20)
    {
        m_Enemies.push_back(Enemy::SpawnRandomly());
        m_SpawnTimer.Reset();
    }
}

void GameScene::RenderImpl()
{
    for (const auto &enemy : m_Enemies)
    {
        enemy->Render();
    }

    m_ScoreText->Render();
}

void GameScene::ReleaseImpl()
{
}