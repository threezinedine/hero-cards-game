#pragma once
#include <common.hpp>
#include <utils/utils.hpp>
#include <components/components.hpp>

class Img;

class Button : public Component
{
public:
    Button(Scope<IPath> path, const Vector2 &pos, const Vector2 &size);
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
    Vector2 m_Pos;
    Vector2 m_Size;

    int m_currentFrame = 0;
    std::function<void()> m_OnClicked;
};