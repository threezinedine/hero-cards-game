#include "ImageResource.hpp"
#include <renderer/renderer.hpp>

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
        renderer::LoadTexture(GetResourceIDRef(), GetPath());
    }

    void ImageResource::UnloadImpl()
    {
        renderer::UnloadTexture(GetResourceID());
    }
} // namespace ntt
