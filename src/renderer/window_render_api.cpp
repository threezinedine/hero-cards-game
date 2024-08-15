#include "window_render_api.hpp"
#include <raylib.h>

namespace
{

}

namespace ntt::renderer
{
    void Init(String windowName, int width, int height, int fps)
    {
        InitWindow(width, height, windowName.c_str());
        SetTargetFPS(fps);
    }

    bool IsWindowClosed()
    {
        return WindowShouldClose();
    }

    float GetWindowWidth()
    {
        return GetScreenWidth();
    }

    float GetWindowHeight()
    {
        return GetScreenHeight();
    }

    void BeginDraw()
    {
        ClearBackground(BLACK);
        BeginDrawing();
    }

    void EndDraw()
    {
        EndDrawing();
    }

    void Release()
    {
        CloseWindow();
    }
} // namespace ntt
