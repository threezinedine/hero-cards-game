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

    Map<rid_t, JSON> Config::GetResourcesMapOfScene(String name)
    {
        auto sceneData = GetSceneData(name);

        Map<rid_t, JSON> resourcesMap;

        if (sceneData.contains("resources") && sceneData["resources"].is_array())
        {
            for (const auto &resource : sceneData["resources"])
            {
                if (resource.contains("rid") && resource["rid"].is_number())
                {
                    resourcesMap[resource["rid"].get<rid_t>()] = resource;
                }
            }
        }

        return resourcesMap;
    }

    Map<eid_t, JSON> Config::GetEntitiesMapOfScene(String name)
    {
        auto sceneData = GetSceneData(name);

        Map<eid_t, JSON> entitiesMap;

        if (sceneData.contains("entities") && sceneData["entities"].is_array())
        {
            for (const auto &entity : sceneData["entities"])
            {
                if (entity.contains("eid") && entity["eid"].is_number())
                {
                    entitiesMap[entity["eid"].get<eid_t>()] = entity;
                }
            }
        }

        return entitiesMap;
    }
}