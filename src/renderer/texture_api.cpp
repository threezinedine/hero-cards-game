#include "texture_api.hpp"
#include <raylib.h>

namespace ntt::renderer
{
    namespace
    {
        struct TextureObject
        {
            Ref<Texture2D> texture;
            Size size;
            bool active;
        };

        Map<rid_t, TextureObject>
            s_Textures;

        bool IsInvalidTextureId(int textureId)
        {
            auto it = s_Textures.find(textureId);

            return it == s_Textures.end();
        }
    }

    void LoadTexture(rid_t id, const String &path)
    {
        auto image = LoadImage(path.c_str());

        auto imgSize = Size{static_cast<float>(image.width),
                            static_cast<float>(image.height)};

        auto texture = CreateRef<Texture2D>(LoadTextureFromImage(image));
        TextureObject textureObject = {texture, imgSize, true};
        s_Textures[id] = textureObject;

        UnloadImage(image);
    }

    void LoadTexture(rid_t id, Scope<IPath> path)
    {
        LoadTexture(id, path->Get());
    }

    void UnloadTexture(rid_t id)
    {
        if (IsInvalidTextureId(id))
        {
            return;
        }

        PRINT("Unloading texture: %d", id);

        UnloadTexture(*(s_Textures[id].texture));
        s_Textures[id].active = false;
    }

    Size GetTextureSize(rid_t id)
    {
        if (IsInvalidTextureId(id))
        {
            return {0, 0};
        }

        return s_Textures[id].size;
    }

    void DrawTexture(rid_t resourceId, const Point &position, const Size &size)
    {
        if (IsInvalidTextureId(resourceId))
        {
            return;
        }

        DrawTexture(*s_Textures[resourceId].texture, static_cast<int>(position.x),
                    static_cast<int>(position.y),
                    WHITE);
    }

    void DrawTexture(rid_t resourceId,
                     const Point &fromPosition,
                     const Size &fromSize,
                     const Point &toPosition,
                     const Size &toSize)
    {
        if (IsInvalidTextureId(resourceId))
        {
            return;
        }

        DrawTexturePro(*s_Textures[resourceId].texture,
                       {fromPosition.x, fromPosition.y, fromSize.width, fromSize.height},
                       {toPosition.x, toPosition.y, toSize.width, toSize.height},
                       {toSize.width / 2, toSize.height / 2},
                       0,
                       WHITE);
    }
};