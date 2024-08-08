#include "Config.hpp"
#include <fstream>

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