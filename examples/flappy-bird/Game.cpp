#include "Game.hpp"
#include <NTTEngine.hpp>

Game::Game(const ConfigurableObject &config)
    : Application(config)
{
    FUNCTION_LOG();
    GetSceneManager()->AddScene(CreateRef<HomeScene>());
    GetSceneManager()->AddScene(CreateRef<GameScene>());
}

Game::~Game()
{
}

Ref<Application> CreateApplication(ConfigurableObject &config)
{
    DEBUG_POINT();
    return CreateRef<Game>(config);
}

String GetCofigPath()
{
    return "C:/Users/Acer/Games Dev/hero-cards-game/examples/flappy-bird/project.config.json";
}