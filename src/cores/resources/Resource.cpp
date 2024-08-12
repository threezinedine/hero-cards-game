#include "Resource.hpp"
#include <utils/path/path.hpp>

namespace ntt
{
    Resource::Resource(rid_t id, Scope<IPath> path, ResourceType type)
        : m_ResourceID(id), m_Path(std::move(path)), m_Type(type)
    {
    }

    Resource::~Resource()
    {
    }

    void Resource::Load()
    {
        if (m_Loaded)
        {
            return;
        }
        LoadImpl();
        m_Loaded = true;
    }

    void Resource::LoadConfigure(JSON config)
    {
        if (config.contains("relPath"))
        {
            m_Path = CreateScope<ResourcePath>(config["relPath"].get<String>());
        }
    }

    void Resource::LoadImpl()
    {
    }

    void Resource::Unload()
    {
        if (!m_Loaded)
        {
            return;
        }
        UnloadImpl();
        m_Loaded = false;
    }

    void Resource::UnloadImpl()
    {
    }
} // namespace ntt
