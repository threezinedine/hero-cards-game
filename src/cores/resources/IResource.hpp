#pragma once
#include <cores/commons/common.hpp>
#include <cores/interfaces/Loadable.hpp>
#include <cores/interfaces/IConfigurable.hpp>
#include "ResourceType.hpp"

namespace ntt
{
    class IResource : public Loadable, public IConfigurable
    {
    public:
        virtual ~IResource() = default;

        virtual rid_t GetResourceID() const = 0;
        virtual const String &GetPath() const = 0;
        virtual ResourceType GetType() const = 0;
        virtual String ResourceName() const = 0;
    };
} // namespace ntt
