#pragma once
#include <common.hpp>

class MouseInput
{
public:
    MouseInput() = default;
    ~MouseInput() = default;

    void Update();
    inline Vector2 GetMousePosition() const { return m_MousePosition; }
    bool HasMouseLeftClicked() const { return IsMouseButtonPressed(MOUSE_LEFT_BUTTON); }

    static void Initialize();
    static MouseInput *Get();
    static void Release();

private:
    Vector2 m_MousePosition;

    static MouseInput *s_Instance;
};