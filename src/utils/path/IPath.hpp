#pragma once

#include <common.hpp>

class IPath
{
public:
    virtual ~IPath() = default;

    virtual String Get() const = 0;
};