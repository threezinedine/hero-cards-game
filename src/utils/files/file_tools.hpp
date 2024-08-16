#pragma once
#include <cores/commons/commons.hpp>

namespace ntt
{
    bool FileExists(const String &path);
    String ReadFile(const String &path);
    void CreateFile(const String &path, const String &content);
    void DeleteFile(const String &path);
} // namespace ntt
