#pragma once
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IConfigurable.hpp>

namespace ntt
{
    class IResource;

    class IResourceManager : public Loadable, public IConfigurable
    {
    public:
        virtual ~IResourceManager() = default;

        virtual void AddResource(Scope<IResource> resource) = 0;
    };
} // namespace ntt
