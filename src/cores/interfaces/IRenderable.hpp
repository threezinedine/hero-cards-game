#pragma once

#include <cores/commons/common.hpp>

namespace ntt
{
    class IRenderable
    {
    public:
        virtual ~IRenderable() = default;

        virtual void Render() = 0;
    };
}