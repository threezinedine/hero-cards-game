#pragma once
#include <common.hpp>
#include <cores/datatypes.hpp>
#include <cores/ILoadable.hpp>
#include "Resource.hpp"

namespace ntt
{
    class ResourceManager : public ILoadable
    {
    public:
        ResourceManager(const String &sceneName);
        ~ResourceManager();

        void AddResource(Scope<Resource> resource);
        void Load() override;
        void Unload() override;

        bool IsLoaded() const override { return true; }

    private:
        List<Scope<Resource>> m_Resources;
        String m_SceneName;
    };
} // namespace ntt
