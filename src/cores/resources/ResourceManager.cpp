#include "ResourceManager.hpp"
#include "IResource.hpp"
#include "ImageResource.hpp"
#include <utils/utils.hpp>

namespace ntt
{
    ResourceManager::ResourceManager()
    {
    }

    ResourceManager::~ResourceManager()
    {
    }

    void ResourceManager::AddResource(Scope<IResource> resource)
    {
        m_Resources[resource->GetResourceID()] = std::move(resource);
    }

    void ResourceManager::Load()
    {
        for (auto &resource : m_Resources)
        {
            if (resource.second->IsLoaded())
            {
                continue;
            }
            resource.second->Load();
        }
    }

    void ResourceManager::LoadConfigure(JSON config)
    {
        if (config.is_array())
        {
            for (const auto &rscCfg : config)
            {
                if (!rscCfg.is_object())
                {
                    continue;
                }

                if (!rscCfg.contains("rid") || !rscCfg["rid"].is_number_unsigned())
                {
                    continue;
                }

                auto rid = rscCfg["rid"].get<rid_t>();

                if (rscCfg.contains("type") && rscCfg["type"].is_number_unsigned())
                {
                    auto type = rscCfg["type"].get<ResourceType>();
                    switch (type)
                    {
                    default:
                        m_Resources[rid] = std::move(CreateScope<ImageResource>(
                            rid,
                            path::relative("assets/images/button.png")));
                        m_Resources[rid]->LoadConfigure(rscCfg);
                    }
                }
            }
        }
    }

    void ResourceManager::Unload()
    {
        for (auto &resource : m_Resources)
        {
            if (!resource.second->IsLoaded())
            {
                continue;
            }
            resource.second->Unload();
        }
    }
} // namespace ntt
