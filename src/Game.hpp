#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game
{
public:
    Game(unsigned int width = 640, unsigned int height = 480);
    ~Game();

    inline const bool ShouldClose() const { return !m_isRunning; }

    void Update();
    void Render();

protected:
    void PollEvents();
    void InitVariables();
    void InitWindow(unsigned int width, unsigned int height);

private:
    sf::RenderWindow *m_window;
    bool m_isRunning = false;
};