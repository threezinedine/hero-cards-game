#pragma once
#include <cores/commons/common.hpp>

namespace ntt
{
    class Config
    {
    public:
        static void Load(String path);

        template <typename T>
        static bool IsType(JSON obj);

        template <typename T>
        static T Get(String key, T defaultValue)
        {
            if (s_Configs.contains(key) && IsType<T>(s_Configs[key]))
            {
                return s_Configs[key].get<T>();
            }

            return defaultValue;
        }

        static List<JSON> GetList(String key, List<JSON> defaultValue = List<JSON>());
        static JSON GetSceneData(String sceneName);
        static JSON GetGlobalResourceConfig();

    private:
        static JSON s_Configs;
    };
}