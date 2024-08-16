#pragma once
#include <cores/commons/common.hpp>

namespace ntt
{
    class path
    {
    public:
        static String absolute(const String &path);
        static String relative(const String &path);
        static void setBasePath(const String &path);

    private:
        static String m_BasePath;
    };
}