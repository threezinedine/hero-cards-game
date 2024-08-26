#include "Geometry.hpp"
#include <utils/log/log.hpp>

namespace ntt
{
    Geometry::Geometry()
    {
        FUNCTION_LOG();
    }

    Geometry::Geometry(const Point &position, const Size &size)
        : m_Point(position), m_Size(size)
    {
        FUNCTION_LOG();
    }

    Geometry::~Geometry()
    {
        FUNCTION_LOG();
    }

    void Geometry::LoadConfigure(ConfigurableObject &config)
    {
        FUNCTION_LOG();
        auto position = config.Get<ConfigurableObject>("position");
        m_Point.x = position.Get<float>("x", m_Point.x);
        m_Point.y = position.Get<float>("y", m_Point.y);

        auto size = config.Get<ConfigurableObject>("size");
        m_Size.width = size.Get<float>("width", m_Size.width);
        m_Size.height = size.Get<float>("height", m_Size.height);
    }
}