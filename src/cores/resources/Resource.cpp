#include "Resource.hpp"
#include <utils/path/path.hpp>
#include <utils/log/log.hpp>
#include <utils/path/path.hpp>

namespace ntt
{
    Resource::Resource(rid_t id, String path, ResourceType type)
        : m_ResourceID(id), m_Path(path), m_Type(type)
    {
        FUNCTION_LOG();
    }

    Resource::~Resource()
    {
        FUNCTION_LOG();
    }

    void Resource::Load()
    {
        FUNCTION_LOG();
        if (IsLoaded())
        {
            return;
        }
        LoadImpl();
        SetIsLoaded(true);
    }

    void Resource::LoadConfigure(ConfigurableObject &config)
    {
        FUNCTION_LOG();
        // FUNCTION_LOG_P("Config: %s", config.ToString().c_str());
        m_ResourceID = config.Get<rid_t>("rid", m_ResourceID);

        if (auto newPath = config.Get<String>("relPath", ""); newPath != "")
        {
            m_Path = ntt::path::relative(newPath);
        }
    }

    void Resource::LoadConfigureImpl(JSON config)
    {
    }

    void Resource::LoadImpl()
    {
    }

    void Resource::Unload()
    {
        FUNCTION_LOG();
        if (!IsLoaded())
        {
            return;
        }
        UnloadImpl();
        SetIsLoaded(false);
    }

    void Resource::UnloadImpl()
    {
    }
} // namespace ntt
