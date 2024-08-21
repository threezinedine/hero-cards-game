#include "Game.hpp"
#include <utils/utils.hpp>
#include <cores/commons/common.hpp>

Game::Game(const ConfigurableObject &config)
    : Application(config)
{
    CreateRef<HomeScene>();
    GetSceneManager()->AddScene(CreateRef<HomeScene>());
    GetSceneManager()->AddScene(CreateRef<GameScene>());
}

Game::~Game()
{
}

Ref<Application> CreateApplication(const ConfigurableObject &config)
{
    return CreateRef<Game>(config);
}

String GetCofigPath()
{
    return "C:/Users/Acer/Games Dev/hero-cards-game/examples/flappy-bird/project.config.json";
}