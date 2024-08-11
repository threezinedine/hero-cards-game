#include "button.hpp"
#include <inputs/MouseInput.hpp>

namespace ntt
{
    Button::Button(Scope<IPath> path, float posX, float posY, float width)
        : Component(posX, posY, width),
          m_currentFrame(0)
    {
        m_Img = CreateScope<Img>(std::move(path), 1, 3);
    }

    Button::~Button()
    {
    }

    void Button::LoadImpl()
    {
        m_Img->Load();
        m_Img->SetIndexes(0, 0);
        m_Img->SetPosX(GetPosX());
        m_Img->SetPosY(GetPosY());
        m_Img->SetWidthKeepRatio(GetWidth());
    }

    void Button::UnloadImpl()
    {
        m_Img->Unload();
    }

    void Button::UpdateImpl(float delta)
    {
        if (IsHovered())
        {
            m_Img->SetIndexes(0, 1);

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            {
                m_OnClicked();
            }

            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                m_Img->SetIndexes(0, 2);
            }
        }
        else
        {
            m_Img->SetIndexes(0, 0);
        }
    }

    bool Button::IsHovered() const
    {
        auto mousePos = MouseInput::Get()->GetMousePos();
        auto buttonWidth = m_Img->GetWidth();
        auto buttonHeight = m_Img->GetHeight();

        return mousePos.x >= GetPosX() - buttonWidth / 2 &&
               mousePos.x <= GetPosX() + buttonWidth / 2 &&
               mousePos.y >= GetPosY() - buttonHeight / 2 &&
               mousePos.y <= GetPosY() + buttonHeight / 2;
    }

    void Button::RenderImpl()
    {
        m_Img->Render();
    }
}