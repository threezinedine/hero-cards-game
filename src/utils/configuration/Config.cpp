#include "Config.hpp"
#include <fstream>

namespace ntt
{
    JSON Config::s_Configs = JSON::object();

    void Config::Load(String path)
    {
        String content = "";
        std::ifstream file(path);
        if (!file.is_open())
        {
            std::cerr << "Failed to open file: " << path << std::endl;
            return;
        }

        // Read all the file content
        String line;
        while (std::getline(file, line))
        {
            content += line;
        }

        file.close();

        try
        {
            s_Configs = JSON::parse(content);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Failed to parse JSON file: " << path << std::endl;
            std::cerr << e.what() << std::endl;
        }
    }

    JSON Config::GetSceneData(String sceneName)
    {
        if (s_Configs.contains("scenes") && s_Configs["scenes"].is_object())
        {
            if (s_Configs["scenes"].contains(sceneName) && s_Configs["scenes"][sceneName].is_object())
            {
                return s_Configs["scenes"][sceneName];
            }
        }

        return JSON::object();
    }

    JSON Config::GetGlobalResourceConfig()
    {
        if (s_Configs.contains("resources") && s_Configs["resources"].is_array())
        {
            return s_Configs;
        }

        return JSON::object();
    }
}