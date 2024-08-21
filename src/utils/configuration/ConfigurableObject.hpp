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
        ConfigurableObject() = default;
        virtual ~ConfigurableObject() = default;

        void FromFile(const String &path);

        template <typename T>
        T Get(const String &key, T defaultValue = T());

        template <typename T>
        List<T> GetList(const String &key, List<T> defaultValue = List<T>());

        template <typename T>
        Map<String, T> GetMap(const String &key, Map<String, T> defaultValue = Map<String, T>());

        void Override(const ConfigurableObject &object);

    protected:
        ConfigurableObject(const JSON &config);
        template <typename T>
        bool IsType(const JSON &obj);

    private:
        JSON m_Config;
    };
} // namespace ntt
