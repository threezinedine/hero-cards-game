#pragma once

#include <common.hpp>

namespace ntt
{
    class IPath
    {
    public:
        virtual ~IPath() = default;

        virtual String Get() const = 0;
    };
}