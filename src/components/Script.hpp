#pragma once
#include <common.hpp>
#include <cores/core.hpp>

namespace ntt
{
    class Component;

    class Script
    {
    public:
        Script();
        virtual ~Script();

        void Update(Component *sender, void *data);

    protected:
        virtual void UpdateImpl(Component *sender, void *data);
    };
} // namespace ntt
