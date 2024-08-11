#pragma once

#include <common.hpp>
#include <components/components.hpp>

namespace ntt
{
    class Text : public Component
    {
    public:
        Text(String text = "", float posX = 10.0f,
             float posY = 10.0f, float fontSize = 20.0f,
             Color color = WHITE);
        ~Text();

        void SetText(String text);

    protected:
        void RenderImpl() override;

    private:
        String m_Text;
        float m_FontSize;
        Color m_Color;
    };
}