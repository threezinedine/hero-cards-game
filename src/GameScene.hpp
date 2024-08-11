#pragma once
#include <common.hpp>
#include <cores/core.hpp>
#include <utils/utils.hpp>
#include "Enemy.hpp"
#include <components/components.hpp>

using namespace ntt;

class GameScene : public Scene
{
public:
    GameScene();
    virtual ~GameScene();

protected:
    void InitImpl() override;
    void UpdateImpl(float delta) override;
    void RenderImpl() override;
    void ReleaseImpl() override;

    void UpdateEnemies(float delta);
    void SpawnEnemy();
    void RenderEnemies();

private:
    List<Scope<Enemy>> m_Enemies;
    AccTimer m_SpawnTimer;
    Scope<Text> m_ScoreText;
    int m_Score = 0;
};