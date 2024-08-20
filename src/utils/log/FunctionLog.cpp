#include "FunctionLog.hpp"
#include "log.hpp"
#include <utils/configuration/Config.hpp>
#include <filesystem>

namespace ntt
{
    FunctionLog::FunctionLog(String functionName, String file, unsigned int line)
        : m_File(file), m_FunctionName(functionName), m_Line(line)
    {
        auto path = std::filesystem::path(file);

        // get the current file path
        auto current = std::filesystem::current_path();
        // get the root path which is the src folder
        auto root = current.parent_path()
                        .parent_path()
                        .parent_path();

        root.append("src");

        // m_File should be the relative path from root
        m_File = std::filesystem::relative(path, root).string();

        PRINT("%s at %s:%u started",
              functionName.c_str(), m_File.c_str(), line);
        m_Timer.Reset();
    }

    FunctionLog::~FunctionLog()
    {
        PRINT("%s at %s:%u ended in %f ms",
              m_FunctionName.c_str(),
              m_File.c_str(), m_Line,
              m_Timer.GetDelta() * 1000);
    }
}