#include "Resource.hpp"
#include <utils/path/path.hpp>
#include <utils/log/log.hpp>

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

    void Resource::LoadConfigure(JSON config)
    {
        FUNCTION_LOG();
        if (config.is_object())
        {
            if (config.contains("rid") && config["rid"].is_number_unsigned())
            {
                m_ResourceID = config["rid"];
            }

            if (config.contains("relPath"))
            {
                m_Path = path::relative(config["relPath"]);
            }

            LoadConfigureImpl(config);
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
