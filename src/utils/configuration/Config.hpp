#pragma once
#include <cores/commons/common.hpp>

namespace ntt
{
    class Config
    {
    public:
        static void Load(String path);

        template <typename T>
        static T Get(String key, T defaultValue = T())
        {
            if (s_Configs.contains(key))
            {
                return s_Configs[key].get<T>();
            }

            // TODO: Add warning message

            return defaultValue;
        }

        template <typename T>
        static List<T> Get(String key, List<T> defaultValue = List<T>())
        {
            if (s_Configs.contains(key))
            {
                if (s_Configs[key].is_array())
                {
                    List<T> list;
                    for (const auto &item : s_Configs[key])
                    {
                        list.push_back(item.get<T>());
                    }

                    return list;
                }
            }

            // TODO: Add warning message

            return defaultValue;
        }

        static JSON GetSceneData(String sceneName);
        static JSON GetGlobalResourceConfig();

    private:
        static JSON s_Configs;
    };
}