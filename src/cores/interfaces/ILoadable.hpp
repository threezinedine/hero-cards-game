#pragma once

namespace ntt
{
    class ILoadable
    {
    public:
        virtual ~ILoadable() = default;

        virtual void Load() = 0;
        virtual void Unload() = 0;

        virtual bool IsLoaded() const = 0;
    };
} // namespace ntt
