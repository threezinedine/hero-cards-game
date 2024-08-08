#pragma once

#include <common.hpp>

class ILifetime
{
public:
    virtual ~ILifetime() = default;

    virtual void Init() = 0;
    virtual void Release() = 0;

    virtual bool IsInitialized() const = 0;
};