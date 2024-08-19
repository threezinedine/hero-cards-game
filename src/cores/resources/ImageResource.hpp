#pragma once
#include <cores/commons/datatypes.hpp>
#include <cores/commons/common.hpp>
#include "Resource.hpp"

namespace ntt
{
    class ImageResource : public Resource
    {
    public:
        ImageResource(rid_t id, String path);
        virtual ~ImageResource();

        inline String ResourceName() const override { return "ImageResource"; }

    protected:
        void LoadImpl() override;
        void UnloadImpl() override;

    private:
    };
}