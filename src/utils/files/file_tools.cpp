#include "file_tools.hpp"
#include <filesystem>
#include <fstream>

namespace ntt
{
    String ReadFile(const String &path)
    {
        std::ifstream file(path);
        String content((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());

        return content;
    }

    bool FileExists(const String &path)
    {
        return std::filesystem::exists(path);
    }

    void CreateFile(const String &path, const String &content)
    {
        std::ofstream file(path);

        if (!file.is_open())
        {
            return;
        }

        file << content;
        file.close();
    }

    void DeleteFile(const String &path)
    {
        if (FileExists(path))
        {
            std::filesystem::remove(path);
        }
    }
} // namespace ntt
