#pragma once
#include <common.hpp>
#include <cores/core.hpp>
#include "GameScene.hpp"
#include "HomeScene.hpp"

using namespace ntt;

class Game : public Application
{
public:
    Game();
    ~Game();

protected:
    void UpdateImpl(float delta) override;
    void RenderImpl() override;

private:
};