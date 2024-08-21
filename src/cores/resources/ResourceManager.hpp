#pragma once
#include <cores/commons/common.hpp>
#include <cores/commons/datatypes.hpp>
#include "IResourceManager.hpp"

namespace ntt
{
    class ResourceManager : public IResourceManager
    {
    public:
        ResourceManager();
        ~ResourceManager();

        void AddResource(Ref<IResource> resource) override;
        void Load() override;
        void Unload() override;

        void LoadConfigure(List<ConfigurableObject> configs) override;

    private:
        Map<rid_t, Ref<IResource>> m_Resources;
    };
} // namespace ntt
