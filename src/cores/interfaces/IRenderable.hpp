#pragma once

#include <cores/commons/common.hpp>

namespace ntt
{
    class IRenderable
    {
    public:
        virtual ~IRenderable() = default;

        virtual void Update(float delta) = 0;
        virtual void Render() = 0;
    };
}