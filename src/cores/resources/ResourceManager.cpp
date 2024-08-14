#include "ResourceManager.hpp"
#include "Resource.hpp"
#include <utils/utils.hpp>

namespace ntt
{
    ResourceManager::ResourceManager(const String &name)
        : m_SceneName(name)
    {
    }

    ResourceManager::~ResourceManager()
    {
    }

    void ResourceManager::AddResource(Scope<Resource> resource)
    {
        m_Resources[resource->GetResourceID()] = std::move(resource);
    }

    void ResourceManager::Load()
    {
        auto config = Config::GetResourcesMapOfScene(m_SceneName);
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
        if (config.contains("resources") && config["resources"].is_array())
        {
            for (const auto &rscCfg : config["resources"])
            {
                if (rscCfg.contains("rid") && rscCfg["rid"].is_number())
                {
                    if (m_Resources.find(rscCfg["rid"]) != m_Resources.end())
                    {
                        m_Resources[rscCfg["rid"]]->LoadConfigure(rscCfg);
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
