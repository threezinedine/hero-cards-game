#include <iostream>
#include <utils/timer/DeltaTimer.hpp>
#include "Game.hpp"
#include <inputs/MouseInput.hpp>

int main(int argc, char **argv)
{
    Game game;
    DeltaTimer timer;
    timer.Start();

    while (!game.ShouldClose())
    {
        timer.Start();
        game.Update(timer.GetDelta());

        game.Render();
    }

    return 0;
}