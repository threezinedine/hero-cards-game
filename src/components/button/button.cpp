#include "button.hpp"
#include <inputs/MouseInput.hpp>

Button::Button(Scope<IPath> path, const Vector2 &pos, const Vector2 &size)
    : m_Pos(pos),
      m_Size(size), m_currentFrame(0)
{
    m_Img = CreateScope<Img>(std::move(path), 1, 3);
    m_Img->SetIndexes(0, 0);
    m_Img->SetPosition(m_Pos.x, m_Pos.y);
}

Button::~Button()
{
}

void Button::LoadImpl()
{
    m_Img->Load();
    m_Img->SetPosition(m_Pos.x, m_Pos.y);
    m_Img->SetSize(m_Size.x);
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
    auto buttonSize = m_Img->GetSize();

    return mousePos.x >= m_Pos.x - buttonSize.x / 2 &&
           mousePos.x <= m_Pos.x + buttonSize.x / 2 &&
           mousePos.y >= m_Pos.y - buttonSize.y / 2 &&
           mousePos.y <= m_Pos.y + buttonSize.y / 2;
}

void Button::RenderImpl()
{
    m_Img->Render();
}