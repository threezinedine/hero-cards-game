#pragma once
#include "ILoadable.hpp"

namespace ntt
{
    class Loadable : public ILoadable
    {
    public:
        virtual ~Loadable() = default;

        virtual void Load() = 0;
        virtual void Unload() = 0;

        inline bool IsLoaded() const override { return m_IsLoaded; }

    protected:
        inline void SetIsLoaded(bool isLoaded) { m_IsLoaded = isLoaded; }

    private:
        bool m_IsLoaded = false;
    };
} // namespace ntt