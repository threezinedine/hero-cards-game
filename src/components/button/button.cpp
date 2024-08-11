#include "button.hpp"
#include <inputs/MouseInput.hpp>

namespace ntt
{
    Button::Button(Scope<IPath> path, float posX,
                   float posY, float width,
                   const std::function<void()> &onClicked)
        : Component(posX, posY, width),
          m_currentFrame(0),
          m_OnClicked(onClicked)
    {
        m_Img = CreateScope<Img>(std::move(path), 1, 3);
    }

    Button::~Button()
    {
    }

    void Button::LoadImpl()
    {
        m_Img->Load();
        m_Img->SetIndexes(0, 0);
        m_Img->SetPosX(GetPosX());
        m_Img->SetPosY(GetPosY());
        m_Img->SetWidthKeepRatio(GetWidth());
    }

    void Button::UnloadImpl()
    {
        m_Img->Unload();
    }

    void Button::UpdateImpl(float delta)
    {
    }

    void Button::OnHover()
    {
        m_Img->SetIndexes(0, 1);
    }

    void Button::OnLeftPressing()
    {
        m_Img->SetIndexes(0, 2);
    }

    void Button::OnLeftReleased()
    {
        m_OnClicked();
    }

    void Button::OnUnhover()
    {
        m_Img->SetIndexes(0, 0);
    }

    void Button::RenderImpl()
    {
        m_Img->Render();
    }
}