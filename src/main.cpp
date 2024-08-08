#include <iostream>
#include <utils/utils.hpp>
#include "Game.hpp"
#include <inputs/MouseInput.hpp>

int main(int argc, char **argv)
{
    Config::Load("C:/Users/Acer/Games Dev/hero-cards-game/project.config.json");
    Game game;
    DeltaTimer timer;
    timer.Start();

    while (game.IsRunning())
    {
        timer.Start();
        game.Update(timer.GetDelta());

        game.Render();
    }

    return 0;
}