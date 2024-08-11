#include "ResourcePath.hpp"

namespace ntt
{
    ResourcePath::ResourcePath(String path) : RelativePath(path, RelativePath("resources"))
    {
    }

    ResourcePath::~ResourcePath()
    {
    }
}