#include "Game.hpp"
#include <inputs/MouseInput.hpp>

Game::Game()
    : m_ScoreText("", 20, 20, 40)
{
    MouseInput::Initialize();
    InitializeWindow();
    InitializeVariables();
}

Game::~Game()
{
    MouseInput::Release();
    CloseWindow();
}

void Game::InitializeVariables()
{
    m_Enemies.push_back(Enemy::SpawnRandomly());
    m_SpawnTimer.Reset();
}

void Game::InitializeWindow()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Hero Cards");
    SetTargetFPS(100);

    m_ScoreText.SetText("Score: 0");
}

void Game::Update(float delta)
{
    if (WindowShouldClose())
    {
        m_ShouldClose = true;
    }

    UpdateEnemies(delta);
    SpawnEnemy();
}

void Game::UpdateEnemies(float delta)
{
    for (const auto &enemy : m_Enemies)
    {
        enemy->Update(delta);

        if (!enemy->IsAlive())
        {
            m_Enemies.erase(std::remove(m_Enemies.begin(), m_Enemies.end(), enemy), m_Enemies.end());
            m_Score++;
            break;
        }
    }
}

void Game::SpawnEnemy()
{
    if (m_SpawnTimer.GetDelta() >= 0.5f && m_Enemies.size() < 20)
    {
        m_Enemies.push_back(Enemy::SpawnRandomly());
        m_SpawnTimer.Reset();
    }
}

void Game::Render()
{
    BeginDrawing();

    ClearBackground(BLACK);

    RenderEnemies();
    RenderScore();

    EndDrawing();
}

void Game::RenderEnemies()
{
    for (const auto &enemy : m_Enemies)
    {
        enemy->Render();
    }
}

void Game::RenderScore()
{
    m_ScoreText.SetText("Score: " + std::to_string(m_Score));
    m_ScoreText.Render();
}