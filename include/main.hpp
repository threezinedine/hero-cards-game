#pragma once

#include <NTTEngine.hpp>

#ifdef _LIB
#include "Game.hpp"

int main(int argc, char **argv)
{
    Config::Load("project.config.json");
    auto game = CreateApplication();
    DeltaTimer timer;
    timer.Start();

    while (game->IsRunning())
    {
        timer.Start();
        game->Update(timer.GetDelta());

        game->Render();
    }

    return 0;
}
#else
#endif