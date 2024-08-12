#include "Game.hpp"
#include <utils/utils.hpp>
#include <common.hpp>

Game::Game()
{
    GetSceneManagement()->AddScene(std::move(CreateScope<HomeScene>()));
    // GetSceneManagement()->AddScene(std::move(CreateScope<GameScene>()));
}

Game::~Game()
{
}

void Game::UpdateImpl(float delta)
{
}

void Game::RenderImpl()
{
}