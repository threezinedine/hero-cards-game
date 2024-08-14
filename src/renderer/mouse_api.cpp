#include "mouse_api.hpp"
#include <raylib.h>

namespace ntt::renderer
{
    const Point GetMousePosition()
    {
        auto pos = ::GetMousePosition();

        return Point{pos.x, pos.y};
    }

    bool IsMouseButtonPressed(MouseButton button)
    {
        switch (button)
        {
        default:
            return ::IsMouseButtonDown(MOUSE_LEFT_BUTTON);
        }
    }
} // namespace ntt::renderer