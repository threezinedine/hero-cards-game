#include "ImageResource.hpp"
#include <renderer/renderer.hpp>

namespace ntt
{
    ImageResource::ImageResource(rid_t id, Scope<IPath> path)
        : Resource(id, std::move(path), ResourceType::IMAGE)
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
        renderer::UnloadTexture(m_TextureId);
    }
} // namespace ntt
