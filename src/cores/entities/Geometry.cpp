#include "Geometry.hpp"
#include <utils/log/log.hpp>

namespace ntt
{
    Geometry::Geometry()
    {
        FUNCTION_LOG();
    }

    Geometry::Geometry(const Point &position, const Size &size)
        : point(position), size(size)
    {
        FUNCTION_LOG();
    }

    Geometry::~Geometry()
    {
        FUNCTION_LOG();
    }

    void Geometry::LoadConfigure(JSON config)
    {
        FUNCTION_LOG();
        if (config.contains("position") && config["position"].is_object())
        {
            auto pointConfig = config["position"];
            if (pointConfig.contains("x") && pointConfig["x"].is_number())
            {
                point.x = pointConfig["x"];
            }

            if (pointConfig.contains("y") && pointConfig["y"].is_number())
            {
                point.y = pointConfig["y"];
            }
        }

        if (config.contains("size") && config["size"].is_object())
        {
            auto sizeConfig = config["size"];
            if (sizeConfig.contains("width") && sizeConfig["width"].is_number())
            {
                size.width = sizeConfig["width"];
            }

            if (sizeConfig.contains("height") && sizeConfig["height"].is_number())
            {
                size.height = sizeConfig["height"];
            }
        }
    }
}