#pragma once

#include "RelativePath.hpp"

namespace ntt
{
    class ResourcePath : public RelativePath
    {
    public:
        ResourcePath(String path);
        virtual ~ResourcePath();
    };
}