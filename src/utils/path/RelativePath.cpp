#include "RelativePath.hpp"
#include <utils/utils.hpp>

RelativePath::RelativePath(String path, String root)
    : m_Path(path)
{
    m_Root = Config::Get("root", root);
}

RelativePath::RelativePath(String path, const IPath &root)
    : m_Path(path)
{
    m_Root = root.Get();
}

RelativePath::~RelativePath()
{
}

String RelativePath::Get() const
{
    return m_Root + "/" + m_Path;
}