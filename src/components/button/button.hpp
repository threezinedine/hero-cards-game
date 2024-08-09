#pragma once
#include <common.hpp>
#include <utils/utils.hpp>
#include <components/components.hpp>

class Button : Component
{
public:
    Button(const IPath &path, const Vector2 &pos, const Vector2 &size);
    ~Button();

    void Update();
    void Draw();

    inline void BindOnClicked(const std::function<void()> &func) { m_OnClicked = func; }

protected:
    bool IsHovered() const;

private:
    Img m_Img;
    Vector2 m_Pos;
    Vector2 m_Size;

    int m_currentFrame = 0;
    std::function<void()> m_OnClicked;
};