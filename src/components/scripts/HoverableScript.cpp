#include "HoverableScript.hpp"
#include <inputs/MouseInput.hpp>
#include <components/Component.hpp>

namespace ntt
{
    HoverableScript::HoverableScript(
        const std::function<void()> &onClickLeft,
        const std::function<void()> &onClickRight,
        const std::function<void()> &onClickMiddle,
        const std::function<void()> &onHover,
        const std::function<void()> &onUnhover)
        : m_OnClickLeft(onClickLeft), m_OnClickRight(onClickRight),
          m_OnClickMiddle(onClickMiddle),
          m_OnHover(onHover), m_OnUnhover(onUnhover)
    {
    }

    HoverableScript::~HoverableScript()
    {
    }

    void HoverableScript::UpdateImpl(Component *sender, void *data)
    {
        if (IsHovered(sender))
        {
            m_OnHover();

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
            {
                try
                {
                    std::cout << (m_OnClickLeft == nullptr) << std::endl;
                    m_OnClickLeft();
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << std::endl;
                }
            }
        }
        else
        {
            m_OnUnhover();
        }
    }

    bool HoverableScript::IsHovered(Component *sender)
    {
        auto [mousePosX, mousePosY] = MouseInput::Get()->GetMousePos();

        float posX = sender->GetPosX();
        float posY = sender->GetPosY();
        float width = sender->GetWidth();
        float height = sender->GetHeight();

        return (
            mousePosX >= posX - width / 2 &&
            mousePosX <= posX + width / 2 &&
            mousePosY >= posY - height / 2 &&
            mousePosY <= posY + height / 2);
    }
} // namespace ntt
