#include "ImageResource.hpp"
#include <renderer/renderer.hpp>
#include <utils/log/log.hpp>

namespace ntt
{
    ImageResource::ImageResource(rid_t id, String path)
        : Resource(id, path, ResourceType::IMAGE)
    {
    }

    ImageResource::~ImageResource()
    {
    }

    void ImageResource::LoadImpl()
    {
        FUNCTION_LOG_P("Loading Image: %s - RID: %d", GetPath().c_str(), GetResourceID());
        renderer::LoadTexture(GetResourceIDRef(), GetPath());
    }

    void ImageResource::UnloadImpl()
    {
        renderer::UnloadTexture(GetResourceID());
    }
} // namespace ntt
