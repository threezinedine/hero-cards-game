#pragma once

#include <common.hpp>

class Text
{
public:
    Text(String text = "", float posX = 10.0f,
         float posY = 10.0f, float fontSize = 20.0f,
         Color color = WHITE);
    ~Text();

    void Render();
    void SetText(String text);

private:
    String m_Text;
    float m_PosX;
    float m_PosY;
    float m_FontSize;
    Color m_Color;
};