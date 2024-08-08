#pragma once

#include "RelativePath.hpp"

class ResourcePath : public RelativePath
{
public:
    ResourcePath(String path);
    virtual ~ResourcePath();
};