#include "path_tools.hpp"
#include <filesystem>

namespace ntt
{
    String path::m_BasePath = "";

    String path::absolute(const String &path)
    {
        return path;
    }

    String path::relative(const String &path)
    {
        std::filesystem::path p = m_BasePath + "/" + path;
        std::filesystem::absolute(p);
        p = p.lexically_normal();
        return p.string();
    }

    void path::setBasePath(const String &path)
    {
        m_BasePath = path;
    }
} // namespace ntt