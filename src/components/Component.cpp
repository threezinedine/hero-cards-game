#include "Component.hpp"

namespace ntt
{
    Component::Component(float posX, float posY, float width, float height)
        : m_PosX(posX), m_PosY(posY), m_Width(width), m_Height(height)
    {
    }

    void Component::Load()
    {
        if (!m_Loaded)
        {
            LoadImpl();
            m_Loaded = true;
        }
    }

    void Component::LoadImpl()
    {
    }

    void Component::Unload()
    {
        if (m_Loaded)
        {
            UnloadImpl();
            m_Loaded = false;
        }
    }

    void Component::UnloadImpl()
    {
    }

    void Component::Update(float delta)
    {
        if (!m_Loaded)
        {
            Load();
        }
        UpdateImpl(delta);
    }

    void Component::UpdateImpl(float delta)
    {
    }

    void Component::Render()
    {
        if (!m_Loaded)
        {
            Load();
        }
        RenderImpl();
    }

    void Component::RenderImpl()
    {
    }

    void Component::ConfigLoad(JSON config)
    {
        if (config.contains("position"))
        {
            auto position = config["position"];
            if (position.contains("x") && position["x"].is_number())
            {
                SetPosX(position["x"]);
            }
            if (position.contains("y") && position["y"].is_number())
            {
                SetPosY(position["y"]);
            }
        }

        if (config.contains("size"))
        {
            auto size = config["size"];
            if (size.contains("width") && size["width"].is_number())
            {
                SetWidth(size["width"]);
            }
            if (size.contains("height") && size["height"].is_number())
            {
                SetHeight(size["height"]);
            }
        }

        ConfigLoadImpl(config);
        m_ConfigLoaded = true;
    }

    void Component::ConfigLoadImpl(JSON config)
    {
    }
}