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

        void AddResource(Scope<IResource> resource) override;
        void Load() override;
        void Unload() override;

        void LoadConfigure(JSON config) override;

    private:
        Map<rid_t, Scope<IResource>> m_Resources;
    };
} // namespace ntt
