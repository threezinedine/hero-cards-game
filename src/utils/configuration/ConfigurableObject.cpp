#include "ConfigurableObject.hpp"
#include <utils/files/files.hpp>
#include <utils/log/log.hpp>

namespace ntt
{
    ConfigurableObject::ConfigurableObject(const JSON &config)
        : m_Config(config)
    {
    }

    void ConfigurableObject::FromFile(const String &path)
    {
        String content = ReadFile(path);

        try
        {
            m_Config = JSON::parse(content);
        }
        catch (const std::exception &e)
        {
            PRINT("Error while parsing JSON file: %s", e.what());
        }
    }

    template <>
    bool ConfigurableObject::IsType<unsigned int>(const JSON &obj)
    {
        return obj.is_number_unsigned();
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
    List<ConfigurableObject> ConfigurableObject::GetList<ConfigurableObject>(const String &key, List<ConfigurableObject> defaultValue)
    {
        List<ConfigurableObject> result;
        if (m_Config.contains(key) && m_Config[key].is_array())
        {
            for (auto &item : m_Config[key])
            {
                if (!item.is_object())
                {
                    continue;
                }
                ConfigurableObject obj(item);
                result.push_back(obj);
            }
        }

        return result;
    }

    void ConfigurableObject::Override(const ConfigurableObject &object)
    {
        for (auto &item : object.m_Config.items())
        {
            if (m_Config.contains(item.key()))
            {
                m_Config[item.key()] = item.value();
            }
        }
    }

    template <typename T>
    T ConfigurableObject::Get(const String &key, T defaultValue)
    {
        if (m_Config.contains(key) && IsType<T>(m_Config[key]))
        {
            return m_Config[key].get<T>();
        }

        return defaultValue;
    }

    template <>
    ConfigurableObject ConfigurableObject::Get<ConfigurableObject>(const String &key, ConfigurableObject defaultValue)
    {
        if (m_Config.contains(key) && m_Config[key].is_object())
        {
            return ConfigurableObject(m_Config[key]);
        }

        return defaultValue;
    }

    template <typename T>
    List<T> ConfigurableObject::GetList(const String &key, List<T> defaultValue)
    {
        List<T> result;
        if (m_Config.contains(key) && m_Config[key].is_array())
        {
            for (auto &item : m_Config[key])
            {
                if (IsType<T>(item))
                {
                    result.push_back(item.get<T>());
                }
            }
        }

        return result;
    }

    template <typename T>
    Map<String, T> ConfigurableObject::GetMap(const String &key, Map<String, T> defaultValue)
    {
        auto value = m_Config[key];
        auto result = Map<String, T>();

        for (const auto &pair : value.items())
        {
            if (!pair.value().is_object())
            {
                if (IsType<T>(pair.value()))
                {
                    result[pair.key()] = pair.value().get<T>();
                }
            }
        }

        return result;
    }

    template <>
    Map<String, ConfigurableObject> ConfigurableObject::GetMap<ConfigurableObject>(
        const String &key, Map<String, ConfigurableObject> defaultValue)
    {
        auto value = m_Config[key];
        auto result = Map<String, ConfigurableObject>();

        if (value.is_object())
        {
            for (const auto &pair : value.items())
            {
                if (pair.value().is_object())
                {
                    ConfigurableObject obj(pair.value());
                    result[pair.key()] = obj;
                }
            }
        }

        return result;
    }

    template int ConfigurableObject::Get<int>(const String &, int);
    template unsigned int ConfigurableObject::Get<unsigned int>(const String &, unsigned int);
    template float ConfigurableObject::Get<float>(const String &, float);
    template String ConfigurableObject::Get<String>(const String &, String);
    template bool ConfigurableObject::Get<bool>(const String &, bool);

    template Map<String, int> ConfigurableObject::GetMap<int>(const String &, Map<String, int>);
    template Map<String, unsigned int> ConfigurableObject::GetMap<unsigned int>(const String &, Map<String, unsigned int>);
    template Map<String, float> ConfigurableObject::GetMap<float>(const String &, Map<String, float>);
    template Map<String, String> ConfigurableObject::GetMap<String>(const String &, Map<String, String>);
    template Map<String, bool> ConfigurableObject::GetMap<bool>(const String &, Map<String, bool>);

    template List<int> ConfigurableObject::GetList<int>(const String &, List<int>);
    template List<unsigned int> ConfigurableObject::GetList<unsigned int>(const String &, List<unsigned int>);
    template List<float> ConfigurableObject::GetList<float>(const String &, List<float>);
    template List<String> ConfigurableObject::GetList<String>(const String &, List<String>);
    template List<bool> ConfigurableObject::GetList<bool>(const String &, List<bool>);
} // namespace ntt
