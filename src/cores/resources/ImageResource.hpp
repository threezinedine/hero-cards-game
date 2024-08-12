#pragma once
#include <cores/datatypes.hpp>
#include <common.hpp>
#include <utils/path/IPath.hpp>
#include "Resource.hpp"

namespace ntt
{
    class ImageResource : public Resource
    {
    public:
        ImageResource(rid_t id, Scope<IPath> path);
        virtual ~ImageResource();

        inline String ResourceName() const override { return "ImageResource"; }
        inline int GetTextureId() const { return m_TextureId; }

    protected:
        void LoadImpl() override;
        void UnloadImpl() override;

    private:
        int m_TextureId;
    };
}