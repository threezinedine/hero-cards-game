#include "Game.hpp"

Game::Game(unsigned int width, unsigned int height)
    : m_isRunning(true)
{
    InitVariables();
    InitWindow(width, height);
}

Game::~Game()
{
    delete m_window;
    m_window = nullptr;
}

void Game::Update()
{
    PollEvents();
}

void Game::Render()
{
    m_window->clear(sf::Color::Black);

    m_window->display();
}

void Game::PollEvents()
{
    while (const auto &event = m_window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            m_isRunning = false;
        }

        if (event->is<sf::Event::KeyPressed>())
        {
            auto keyEvent = event->getIf<sf::Event::KeyPressed>();

            if (keyEvent->code == sf::Keyboard::Key::Escape)
            {
                m_isRunning = false;
            }
        }
    }
}

void Game::InitVariables()
{
    m_window = nullptr;
    m_window = new sf::RenderWindow(sf::VideoMode({640, 480}), "SFML works");
}

void Game::InitWindow(unsigned int width, unsigned int height)
{
    m_window = new sf::RenderWindow(sf::VideoMode({width, height}), "SFML works");
}