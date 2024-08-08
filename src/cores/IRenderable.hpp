#pragma once

#include <common.hpp>

class IRenderable
{
public:
    virtual ~IRenderable() = default;

    virtual void Update(float delta) = 0;
    virtual void Render() = 0;
};