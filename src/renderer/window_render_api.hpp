#pragma once
#include <cores/commons/common.hpp>

namespace ntt::renderer
{
    void Init(String windowName, int width, int height, int fps);
    bool IsWindowClosed();

    float GetWindowWidth();
    float GetWindowHeight();

    void BeginUpdate();
    void EndUpdate();

    void BeginDraw();
    void EndDraw();

    void Release();

} // namespace ntt::renderer
