#include "Geometry.hpp"

namespace ntt
{
    Geometry::Geometry()
    {
    }

    Geometry::Geometry(const Point &position, const Size &size)
        : point(position), size(size)
    {
    }

    Geometry::~Geometry()
    {
    }

    void Geometry::LoadConfigure(JSON config)
    {
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