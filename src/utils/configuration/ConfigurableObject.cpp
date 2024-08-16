#include "ConfigurableObject.hpp"

namespace ntt
{
    void ConfigurableObject::LoadConfigure(JSON config)
    {
        m_Config = config;
    }

    template <>
    bool ConfigurableObject::IsType<String>(const JSON &obj)
    {
        return obj.is_string();
    }

    template <>
    bool ConfigurableObject::IsType<int>(const JSON &obj)
    {
        return obj.is_number();
    }

    template <>
    bool ConfigurableObject::IsType<float>(const JSON &obj)
    {
        return obj.is_number();
    }

    template <>
    bool ConfigurableObject::IsType<bool>(const JSON &obj)
    {
        return obj.is_boolean();
    }

    template <>
    bool ConfigurableObject::IsType<JSON>(const JSON &obj)
    {
        return obj.is_object();
    }

    List<ConfigurableObject> ConfigurableObject::ExtractList(const String &key)
    {
        List<ConfigurableObject> result;
        if (m_Config.contains(key) && m_Config[key].is_array())
        {
            for (auto &item : m_Config[key])
            {
                ConfigurableObject obj;
                obj.LoadConfigure(item);
                result.push_back(obj);
            }
        }

        return result;
    }
} // namespace ntt
