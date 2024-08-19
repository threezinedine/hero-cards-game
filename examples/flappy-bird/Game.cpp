#include "Game.hpp"
#include <utils/utils.hpp>
#include <cores/commons/common.hpp>

Game::Game()
{
    CreateRef<HomeScene>();
    GetSceneManager()->AddScene(CreateRef<HomeScene>());
    GetSceneManager()->AddScene(CreateRef<GameScene>());
}

Game::~Game()
{
}

Ref<Application> CreateApplication()
{
    return CreateRef<Game>();
}

String GetCofigPath()
{
    return "C:/Users/Acer/Games Dev/hero-cards-game/examples/flappy-bird/project.config.json";
}