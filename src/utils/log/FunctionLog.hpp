#pragma once
#include <cores/commons/common.hpp>
#include <utils/timer/timer.hpp>

namespace ntt
{
    class FunctionLog
    {
    public:
        FunctionLog(String functionName, String file, unsigned int line);
        ~FunctionLog();

        void Print(const char *format, ...);

    protected:
    private:
        String m_FunctionName;
        String m_File;
        unsigned int m_Line;
        AccTimer m_Timer;
    };
} // namespace ntt
