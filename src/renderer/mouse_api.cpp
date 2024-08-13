#include "mouse_api.hpp"
#include <raylib.h>

namespace ntt::renderer
{
    const Point GetMousePosition()
    {
        auto pos = ::GetMousePosition();

        return Point{pos.x, pos.y};
    }
} // namespace ntt::renderer