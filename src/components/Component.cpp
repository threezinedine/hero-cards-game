#include "Component.hpp"
#include <inputs/MouseInput.hpp>

namespace ntt
{
    Component::Component(float posX, float posY, float width, float height)
        : m_PosX(posX), m_PosY(posY), m_Width(width), m_Height(height)
    {
        m_ScriptManager = CreateScope<ScriptManager>();
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

        m_ScriptManager->Update(this, nullptr);
        GeometryUpdate();
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

    void Component::OnHover()
    {
    }

    void Component::OnUnhover()
    {
    }

    void Component::OnLeftPressed()
    {
    }

    void Component::OnLeftPressing()
    {
    }

    void Component::OnLeftReleased()
    {
    }

    void Component::OnRightPressed()
    {
    }

    void Component::OnRightPressing()
    {
    }

    void Component::OnRightReleased()
    {
    }

    void Component::OnMiddlePressed()
    {
    }

    void Component::OnMiddlePressing()
    {
    }

    void Component::OnMiddleReleased()
    {
    }

    void Component::GeometryUpdate()
    {
        if (OnHovered())
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                OnLeftPressed();
            }
            else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                OnLeftReleased();
            }
            else if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                OnLeftPressing();
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
            {
                OnRightPressed();
            }
            else if (IsMouseButtonReleased(MOUSE_BUTTON_RIGHT))
            {
                OnRightReleased();
            }
            else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
            {
                OnRightPressing();
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE))
            {
                OnMiddlePressed();
            }
            else if (IsMouseButtonReleased(MOUSE_BUTTON_MIDDLE))
            {
                OnMiddleReleased();
            }
            else if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
            {
                OnMiddlePressing();
            }
            else
            {
                OnHover();
            }
        }
        else
        {
            OnUnhover();
        }
    }

    bool Component::OnHovered()
    {
        auto [mousePosX, mousePosY] = MouseInput::Get()->GetMousePos();

        float posX = GetPosX();
        float posY = GetPosY();
        float width = GetWidth();
        float height = GetHeight();

        return (
            mousePosX >= posX - width / 2 &&
            mousePosX <= posX + width / 2 &&
            mousePosY >= posY - height / 2 &&
            mousePosY <= posY + height / 2);
    }
}