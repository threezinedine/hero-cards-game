#include <iostream>
#include "Game.hpp"

int main(int argc, char **argv)
{
    Game game{800, 600};

    while (!game.ShouldClose())
    {
        game.Update();
        game.Render();
    }

    return 0;
}