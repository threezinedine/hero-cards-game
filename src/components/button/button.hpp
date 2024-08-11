#pragma once
#include <common.hpp>
#include <utils/utils.hpp>
#include <components/components.hpp>

namespace ntt
{
    class Img;

    class Button : public Component
    {
    public:
        Button(Scope<IPath> path, float posX = 0.0f, float posY = 0.0f,
               float width = 100.0f);
        ~Button();

        inline void BindOnClicked(const std::function<void()> &func) { m_OnClicked = func; }

    protected:
        void LoadImpl() override;
        void UnloadImpl() override;

        void UpdateImpl(float delta) override;
        void RenderImpl() override;

        bool IsHovered() const;

    private:
        Scope<Img> m_Img;

        int m_currentFrame = 0;
        std::function<void()> m_OnClicked;
    };
}