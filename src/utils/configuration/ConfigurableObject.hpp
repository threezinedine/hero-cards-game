#pragma once
#include <cores/commons/common.hpp>

namespace ntt
{
    /**
     * The based class for all configurable objects
     *  which can be inhertted by all objects that
     *  receive a JSON object as configure like Entity
     *  Script, Resource, etc.
     *
     *  Example of usage:
     *
     *  ```cpp
     *  JSON config = {
     *     {"floatKey", 23.0f},
     *  }
     *
     *  ConfigurableObject obj;
     *
     *  obj.LoadConfigure(config);  // the object must load the configure
     *                              // or the Get method will return the
     *                              // default values
     *
     *  auto intValue = obj.Get<int>("floatKey", 0); // intValue = 23
     *  auto float = obj.Get<float>("floatKey", 0.0f); // floatValue = 23.0f
     *  ```
     */
    class ConfigurableObject
    {
    public:
        virtual ~ConfigurableObject() = default;

        template <typename T>
        bool IsType(const JSON &obj);

        template <typename T>
        T Get(const String &key, T defaultValue)
        {
            if (m_Config.contains(key) && IsType<T>(m_Config[key]))
            {
                return m_Config[key].get<T>();
            }

            return defaultValue;
        }

        template <typename T>
        List<T> GetList(const String &key)
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

        void LoadConfigure(JSON config);

        List<ConfigurableObject> ExtractList(const String &key);

    private:
        JSON m_Config;
    };
} // namespace ntt
