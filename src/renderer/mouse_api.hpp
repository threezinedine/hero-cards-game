#pragma once
#include <common.hpp>
#include <cores/datatypes.hpp>

namespace ntt::renderer
{
    enum class MouseButton
    {
        LEFT = 0,
    };

    const Point GetMousePosition();
    bool IsMouseButtonPressed(MouseButton button);
} // namespace ntt
