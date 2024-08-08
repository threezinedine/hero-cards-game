#include "Application.hpp"
#include <inputs/MouseInput.hpp>
#include <utils/utils.hpp>

Application::Application()
    : m_Running(true)
{
    MouseInput::Initialize();
    const int screenWidth = Config::Get<int>("screenWidth", 800);
    const int screenHeight = Config::Get<int>("screenHeight", 600);
    const int fps = Config::Get<int>("fps", 60);

    String title = Config::Get<String>("title", "Hero Cards");

    InitWindow(screenWidth, screenHeight, title.c_str());
    SetTargetFPS(fps);
}

Application::~Application()
{
    MouseInput::Release();
    CloseWindow();
}

void Application::Update(float delta)
{
    if (WindowShouldClose())
    {
        m_Running = false;
    }
    MouseInput::Get()->Update();

    UpdateImpl(delta);
}

void Application::UpdateImpl(float delta)
{
}

void Application::Render()
{
    BeginDrawing();

    ClearBackground(BLACK);
    RenderImpl();

    EndDrawing();
}

void Application::RenderImpl()
{
}