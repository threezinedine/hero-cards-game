#include "FunctionLog.hpp"
#include <utils/configuration/Config.hpp>
#include <filesystem>
#include <cstdio>
#include <cstdarg>

namespace ntt
{
    namespace
    {
        unsigned int s_level = 0;
    }

    FunctionLog::FunctionLog(String functionName, String file, unsigned int line)
        : m_File(file), m_FunctionName(functionName), m_Line(line)
    {
        for (unsigned int i = 0; i < s_level; i++)
        {
            printf("\t");
        }

        // get file name only from the path
        m_File = std::filesystem::path(file).filename().string();

        printf("+++ %s at %s:%u started\n",
               functionName.c_str(), m_File.c_str(), line);
        m_Timer.Reset();

        s_level++;
    }

    FunctionLog::~FunctionLog()
    {
        s_level--;
        for (unsigned int i = 0; i < s_level; i++)
        {
            printf("\t");
        }

        printf("--- %s at %s:%u ended in %f ms\n",
               m_FunctionName.c_str(),
               m_File.c_str(), m_Line,
               m_Timer.GetDelta() * 1000);
    }

    void FunctionLog::Print(const char *format, ...)
    {
        for (unsigned int i = 0; i < s_level + 1; i++)
        {
            printf("\t");
        }

        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);

        printf("\n");
    }
}