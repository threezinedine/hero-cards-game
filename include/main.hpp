#pragma once

#include <NTTEngine.hpp>

#ifdef _LIB
#include "Game.hpp"

int main(int argc, char **argv)
{
    auto configPath = GetCofigPath();
    Config::Load(configPath);
    ntt::path::setBasePath(Config::Get<String>("root", "."));
    auto game = CreateApplication();
    DeltaTimer timer;
    timer.Start();

    while (game->IsRunning())
    {
        timer.Start();
        game->Update(timer.GetDelta());
    }

    return 0;
}
#else
#endif