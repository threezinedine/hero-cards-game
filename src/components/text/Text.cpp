#include "Text.hpp"

Text::Text(String text, float posX,
           float posY, float fontSize,
           Color color)
    : m_Text(text),
      m_PosX(posX),
      m_PosY(posY),
      m_FontSize(fontSize)
{
    m_Color = color;
}

Text::~Text()
{
}

void Text::Render()
{
    DrawText(m_Text.c_str(), m_PosX, m_PosY, m_FontSize, m_Color);
}

void Text::SetText(String text)
{
    m_Text = text;
}