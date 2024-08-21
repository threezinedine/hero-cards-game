#pragma once
#include <cores/commons/common.hpp>
#include <utils/configuration/ConfigurableObject.hpp>

namespace ntt
{
    class IConfigurable
    {
    public:
        virtual void LoadConfigure(ConfigurableObject &config) = 0;
    };
} // namespace ntt
