#pragma once

#include <common.hpp>
#include <components/Script.hpp>

namespace ntt
{
    // empty void function
    class HoverableScript : public Script
    {
    public:
        HoverableScript(
            const std::function<void()> &onClickLeft = []() {},
            const std::function<void()> &onClickRight = []() {},
            const std::function<void()> &onClickMiddle = []() {},
            const std::function<void()> &onHover = []() {},
            const std::function<void()> &onUnhover = []() {});
        virtual ~HoverableScript();

    protected:
        virtual void UpdateImpl(Component *sender, void *data) override;

        bool IsHovered(Component *sender);

    private:
        std::function<void()> m_OnClickLeft;
        std::function<void()> m_OnClickRight;
        std::function<void()> m_OnClickMiddle;
        std::function<void()> m_OnHover;
        std::function<void()> m_OnUnhover;
    };
} // namespace ntt
