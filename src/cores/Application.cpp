#include "Application.hpp"
#include <utils/utils.hpp>
#include <renderer/renderer.hpp>
#include <cores/resources/ResourceManager.hpp>
#include <cores/scenes/SceneManager.hpp>

namespace ntt
{
    Application::Application(const ConfigurableObject &config)
        : m_Config(config), m_Running(true)
    {
        FUNCTION_LOG();
        const int screenWidth = m_Config.Get<int>("screenWidth", 800);
        const int screenHeight = m_Config.Get<int>("screenHeight", 600);
        const int fps = m_Config.Get<int>("fps", 60);
        String title = m_Config.Get<String>("title", "Hero Cards");

        renderer::Init(title, screenWidth, screenHeight, fps);

        m_SceneManager = CreateRef<SceneManager>();
        m_GlobalResourceManager = CreateRef<ResourceManager>();

        m_GlobalResourceManager->LoadConfigure(
            m_Config.GetList<ConfigurableObject>("resources"));

        m_GlobalResourceManager->Load();
        m_SceneManager->SetConfig(m_Config);
    }

    Application::~Application()
    {
        FUNCTION_LOG();
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

        renderer::EndDraw();
    }
}