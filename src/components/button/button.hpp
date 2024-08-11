#pragma once
#include <common.hpp>
#include <utils/utils.hpp>
#include <components/components.hpp>
#include <components/scripts/scripts.hpp>

namespace ntt
{
    class Img;

    class Button : public Component
    {
    public:
        Button(Scope<IPath> path, float posX = 0.0f, float posY = 0.0f, float width = 100.0f, const std::function<void()> &onClicked = []() {});
        ~Button();

        inline void BindOnClicked(const std::function<void()> &func) { m_OnClicked = func; }

    protected:
        void LoadImpl() override;
        void UnloadImpl() override;

        void UpdateImpl(float delta) override;
        void RenderImpl() override;

        virtual void OnHover() override;
        virtual void OnLeftPressing() override;
        virtual void OnLeftReleased() override;
        virtual void OnUnhover() override;

    private:
        Scope<Img> m_Img;

        int m_currentFrame = 0;
        std::function<void()> m_OnClicked;
    };
}