#pragma once
#include <cores/commons/common.hpp>

namespace ntt
{
    class IConfigurable
    {
    public:
        virtual void LoadConfigure(JSON config) = 0;
    };
} // namespace ntt
