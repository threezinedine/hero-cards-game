#include "Game.hpp"
#include <utils/utils.hpp>
#include <common.hpp>

Game::Game()
{
    GetSceneManager()->AddScene(std::move(CreateScope<HomeScene>()));
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