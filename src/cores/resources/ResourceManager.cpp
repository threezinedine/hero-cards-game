#include "ResourceManager.hpp"
#include "IResource.hpp"
#include "ImageResource.hpp"
#include <utils/utils.hpp>

namespace ntt
{
    ResourceManager::ResourceManager()
    {
        FUNCTION_LOG();
    }

    ResourceManager::~ResourceManager()
    {
        FUNCTION_LOG();
    }

    void ResourceManager::AddResource(Ref<IResource> resource)
    {
        FUNCTION_LOG();
        m_Resources[resource->GetResourceID()] = resource;
    }

    void ResourceManager::Load()
    {
        FUNCTION_LOG();
        for (auto &resource : m_Resources)
        {
            resource.second->Load();
        }
    }

    void ResourceManager::LoadConfigure(List<ConfigurableObject> configs)
    {
        FUNCTION_LOG();
        for (auto &config : configs)
        {
            if (config.Get<rid_t>("rid", INVALID_RID) == INVALID_RID)
            {
                continue;
            }

            auto rid = config.Get<rid_t>("rid");

            if (auto type = config.Get<unsigned int>("type", -1); type != -1)
            {
                switch (type)
                {
                default:
                    m_Resources[rid] = CreateRef<ImageResource>(
                        rid,
                        path::relative("assets/images/button.png"));
                    m_Resources[rid]->LoadConfigure(config);
                }
            }
        }
    }

    void ResourceManager::Unload()
    {
        FUNCTION_LOG();
        for (auto &resource : m_Resources)
        {
            resource.second->Unload();
        }
    }
} // namespace ntt
