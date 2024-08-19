#include "Application.hpp"
#include <utils/utils.hpp>
#include <renderer/renderer.hpp>
#include <cores/resources/ResourceManager.hpp>
#include <cores/scenes/SceneManager.hpp>

namespace ntt
{
    Application::Application()
        : m_Running(true)
    {
        const int screenWidth = Config::Get<int>("screenWidth", 800);
        const int screenHeight = Config::Get<int>("screenHeight", 600);
        const int fps = Config::Get<int>("fps", 60);

        String title = Config::Get<String>("title", "Hero Cards");

        renderer::Init(title, screenWidth, screenHeight, fps);

        m_SceneManager = CreateRef<SceneManager>();
        m_GlobalResourceManager = CreateRef<ResourceManager>();

        auto config = Config::GetGlobalResourceConfig();
        m_GlobalResourceManager->LoadConfigure(config);

        m_GlobalResourceManager->Load();
    }

    Application::~Application()
    {
        m_GlobalResourceManager->Unload();
        renderer::Release();
    }

    void Application::Update(float delta)
    {
        renderer::BeginDraw();

        if (renderer::IsWindowClosed())
        {
            m_Running = false;
        }

        m_SceneManager->Update(delta);
        UpdateImpl(delta);

        renderer::EndDraw();
    }

    void Application::UpdateImpl(float delta)
    {
    }
}