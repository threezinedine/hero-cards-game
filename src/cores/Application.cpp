#include "Application.hpp"
#include <utils/utils.hpp>
#include <renderer/renderer.hpp>

namespace ntt
{
    Application::Application()
        : m_Running(true)
    {
        // MouseInput::Initialize();
        const int screenWidth = Config::Get<int>("screenWidth", 800);
        const int screenHeight = Config::Get<int>("screenHeight", 600);
        const int fps = Config::Get<int>("fps", 60);

        String title = Config::Get<String>("title", "Hero Cards");

        renderer::Init(title, screenWidth, screenHeight, fps);

        m_SceneManagement = CreateRef<SceneManagement>();
    }

    Application::~Application()
    {
        // MouseInput::Release();
        renderer::Release();
    }

    void Application::Update(float delta)
    {
        if (renderer::IsWindowClosed())
        {
            m_Running = false;
        }
        // MouseInput::Get()->Update();

        m_SceneManagement->Update(delta);
        UpdateImpl(delta);
    }

    void Application::UpdateImpl(float delta)
    {
        renderer::BeginUpdate();
        renderer::EndUpdate();
    }

    void Application::Render()
    {
        renderer::BeginDraw();
        m_SceneManagement->Render();
        renderer::EndDraw();
    }

    void Application::RenderImpl()
    {
    }
}