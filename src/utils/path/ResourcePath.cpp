#include "ResourcePath.hpp"

ResourcePath::ResourcePath(String path) : RelativePath(path, RelativePath("resources"))
{
}

ResourcePath::~ResourcePath()
{
}