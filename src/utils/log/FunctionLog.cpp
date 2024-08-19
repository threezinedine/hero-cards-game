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
        m_File = path.filename().string();

        PRINT("Function: %s at %s:%u started",
              functionName.c_str(), m_File.c_str(), line);
        m_Timer.Reset();
    }

    FunctionLog::~FunctionLog()
    {
        PRINT("Function: %s at %s:%u ended in %f ms",
              m_FunctionName.c_str(),
              m_File.c_str(), m_Line,
              m_Timer.GetDelta() * 1000);
    }
}