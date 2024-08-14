#pragma once
#include <cores/commons/common.hpp>
#include <cores/commons/datatypes.hpp>

namespace ntt::renderer
{
    enum class MouseButton
    {
        LEFT = 0,
    };

    const Point GetMousePosition();
    bool IsMouseButtonPressed(MouseButton button);
} // namespace ntt
