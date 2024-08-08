#pragma once
#include "IPath.hpp"

class RelativePath : public IPath
{
public:
    RelativePath(String path, String root = ".");
    RelativePath(String path, const IPath &root);
    virtual ~RelativePath();

    String Get() const override;

private:
    String m_Path;
    String m_Root;
};