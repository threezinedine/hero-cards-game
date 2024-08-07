#pragma once
#include <common.hpp>
#include "Enemy.hpp"
#include <utils/timer/AccTimer.hpp>
#include <components/components.hpp>

class Game
{
public:
    Game();
    ~Game();

    inline bool ShouldClose() const { return m_ShouldClose; }

    void Update(float delta);
    void Render();

protected:
    void InitializeVariables();
    void InitializeWindow();

    void UpdateEnemies(float delta);
    void SpawnEnemy();

    void RenderEnemies();

    void RenderScore();

private:
    bool m_ShouldClose = false;

    List<Scope<Enemy>> m_Enemies;
    AccTimer m_SpawnTimer;
    Text m_ScoreText;
    int m_Score = 0;
};