#pragma once
#include <cores/commons/common.hpp>
#include <utils/path/IPath.hpp>
#include <cores/commons/datatypes.hpp>

namespace ntt::renderer
{
    void LoadTexture(rid_t id, Scope<IPath> path);
    void LoadTexture(rid_t id, const String &path);
    void UnloadTexture(rid_t id);

    Size GetTextureSize(rid_t id);

    void DrawTexture(rid_t resourceId, const Point &position, const Size &size);
    void DrawTexture(rid_t resourceId,
                     const Point &fromPosition,
                     const Size &fromSize,
                     const Point &toPosition,
                     const Size &toSize);
} // namespace ntt::renderer
