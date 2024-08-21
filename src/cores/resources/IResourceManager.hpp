#pragma once
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IConfigurable.hpp>

namespace ntt
{
    class IResource;

    class IResourceManager : public Loadable
    {
    public:
        virtual ~IResourceManager() = default;

        virtual void AddResource(Ref<IResource> resource) = 0;
        virtual void LoadConfigure(List<ConfigurableObject> configs) = 0;
    };
} // namespace ntt
