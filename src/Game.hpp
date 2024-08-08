#pragma once
#include <common.hpp>
#include <cores/core.hpp>
#include "GameScene.hpp"
#include "HomeScene.hpp"

class Game : public Application
{
public:
    Game();
    ~Game();

    void ChangeScene(int index);

protected:
    void UpdateImpl(float delta) override;
    void RenderImpl() override;

private:
    List<Scope<Scene>> m_Scenes;
    int m_CurrentSceneIndex;
};