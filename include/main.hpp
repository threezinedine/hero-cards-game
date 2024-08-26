#pragma once
#include <NTTEngine.hpp>

#ifdef _LIB

int main(int argc, char **argv)
{
#ifdef _TEST
    printf("Tracing mode\n");
#endif

    auto configPath = GetCofigPath();
    ntt::ConfigurableObject config;
    config.FromFile(configPath);
    ntt::path::setBasePath(config.Get<ntt::String>("root", "."));
    auto game = CreateApplication(config);
    ntt::DeltaTimer timer;
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