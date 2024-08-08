#include "button.hpp"
#include <inputs/MouseInput.hpp>

Button::Button(const IPath &path, const Vector2 &pos, const Vector2 &size)
    : m_Img(path, 1, 3), m_Pos(pos),
      m_Size(size), m_currentFrame(0)
{
    m_Img.SetSize(size.x);
}

Button::~Button()
{
}

void Button::Update()
{
    if (IsHovered())
    {
        m_currentFrame = 1;
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            m_currentFrame = 2;
        }
    }
    else
    {
        m_currentFrame = 0;
    }
}

bool Button::IsHovered() const
{
    auto mousePos = MouseInput::Get()->GetMousePos();
    auto buttonSize = m_Img.GetSize();

    return mousePos.x >= m_Pos.x - buttonSize.x / 2 &&
           mousePos.x <= m_Pos.x + buttonSize.x / 2 &&
           mousePos.y >= m_Pos.y - buttonSize.y / 2 &&
           mousePos.y <= m_Pos.y + buttonSize.y / 2;
}

void Button::Draw()
{
    m_Img.Render(0, m_currentFrame, m_Pos.x, m_Pos.y);
}