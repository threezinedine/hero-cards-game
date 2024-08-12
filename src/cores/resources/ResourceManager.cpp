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
        m_Resources.push_back(std::move(resource));
    }

    void ResourceManager::Load()
    {
        auto config = Config::GetResourcesMapOfScene(m_SceneName);
        for (auto &resource : m_Resources)
        {
            if (resource->IsLoaded())
            {
                continue;
            }

            auto it = config.find(resource->GetResourceID());
            if (it != config.end())
            {
                resource->LoadConfigure(it->second);
            }

            resource->Load();
        }
    }

    void ResourceManager::Unload()
    {
        for (auto &resource : m_Resources)
        {
            if (!resource->IsLoaded())
            {
                continue;
            }
            resource->Unload();
        }
    }
} // namespace ntt
