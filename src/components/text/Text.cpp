#include "Text.hpp"

Text::Text(String text, float posX,
           float posY, float fontSize,
           Color color)
    : m_Text(text),
      m_FontSize(fontSize)
{
    m_Color = color;
    SetPosX(posX);
    SetPosY(posY);
}

Text::~Text()
{
}

void Text::RenderImpl()
{
    DrawText(m_Text.c_str(), GetPosX(), GetPosY(), m_FontSize, m_Color);
}

void Text::SetText(String text)
{
    m_Text = text;
}