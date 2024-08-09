#include "button.hpp"
#include <inputs/MouseInput.hpp>

Button::Button(Scope<IPath> path, const Vector2 &pos, const Vector2 &size)
    : m_Pos(pos),
      m_Size(size), m_currentFrame(0)
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
    m_Img->SetPosX(m_Pos.x);
    m_Img->SetPosY(m_Pos.y);
    m_Img->SetWidthKeepRatio(m_Size.x);
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

    return mousePos.x >= m_Pos.x - buttonWidth / 2 &&
           mousePos.x <= m_Pos.x + buttonWidth / 2 &&
           mousePos.y >= m_Pos.y - buttonHeight / 2 &&
           mousePos.y <= m_Pos.y + buttonHeight / 2;
}

void Button::RenderImpl()
{
    m_Img->Render();
}