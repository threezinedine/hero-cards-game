#include "Game.hpp"
#include <utils/utils.hpp>
#include <cores/commons/common.hpp>

Game::Game()
{
    GetSceneManager()->AddScene(CreateRef<HomeScene>());
    GetSceneManager()->AddScene(CreateRef<GameScene>());
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

Ref<Application> CreateApplication()
{
    return CreateRef<Game>();
}